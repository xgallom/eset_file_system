//
// Created by xgallom on 4/12/19.
//

#include "ParsingSchedulerThreadPool.h"
#include "FileParser.h"

namespace ParsingScheduler
{
	static bool areThreadsFinished(uint32_t threadFlags) noexcept
	{
		return threadFlags == 0;
	}

	ThreadPool::ThreadPool(unsigned int threadCount, const std::string &key) :
			m_runFlag(true)
	{
		m_threadFlags.resetToInitial(threadCount);

		m_threadInputs.resize(threadCount);
		m_threadResults.resize(threadCount);
		m_threadPool.reserve(threadCount);

		for(size_t n = 0; n < threadCount; ++n)
			m_threadPool.emplace_back(threadHandler, this, n, key);
	}

	ThreadPool::~ThreadPool() noexcept
	{
		stopThreads();

		for(auto &thread : m_threadPool)
			thread.join();
	}

	bool ThreadPool::isFinished() const noexcept
	{
		return areThreadsFinished(m_threadFlags.value());
	}

	void ThreadPool::stopThreads() noexcept
	{
		m_runFlag.store(false, std::memory_order_relaxed);
	}

	Optional<ParsingResult> ThreadPool::consumeResults(size_t threadIndex, ThreadFlags::Enum threadFlags) noexcept
	{
		Optional<ParsingResult> result = {};

		if(threadFlags & ThreadFlags::ResultsReady) {
			result = Optional<ParsingResult>(std::move(m_threadResults[threadIndex]));

			m_threadFlags.clearFlagsForThread(threadIndex, ThreadFlags::ResultsReady);
		}

		return result;
	}

	ThreadFlags::Enum ThreadPool::threadFlags(size_t threadIndex) const noexcept
	{
		return m_threadFlags.flagsForThread(threadIndex);
	}

	void ThreadPool::setThreadInput(size_t threadIndex, std::string &&input) noexcept
	{
		m_threadInputs[threadIndex] = std::move(input);

		m_threadFlags.setFlagsForThread(threadIndex, ThreadFlags::DataReady);
	}

	ThreadPoolIterator ThreadPool::begin() noexcept
	{
		return {*this, 0};
	}

	ThreadPoolIterator ThreadPool::end() noexcept
	{
		return {*this, m_threadPool.size()};
	}

	void ThreadPool::signalProcessingFinished(size_t threadIndex) noexcept
	{
		m_threadFlags.clearFlagsForThread(threadIndex, ThreadFlags::Processing, std::memory_order_relaxed);
	}

	void ThreadPool::signalResultsReady(size_t threadIndex) noexcept
	{
		m_threadFlags.setFlagsForThread(threadIndex, ThreadFlags::ResultsReady);
	}

	bool ThreadPool::runFlag() const noexcept
	{
		return m_runFlag.load(std::memory_order_relaxed);
	}

	std::string ThreadPool::threadInput(size_t threadIndex) noexcept
	{
		return std::move(m_threadInputs[threadIndex]);
	}

	void ThreadPool::setThreadResult(size_t threadIndex, ParsingResult &&result) noexcept
	{
		m_threadResults[threadIndex] = std::move(result);
	}

	void ThreadPool::threadHandler(ThreadPool *a_this, size_t index, const std::string &key)
	{
		FileParser::FileParser fileParser;

		ThreadFlags::Enum threadFlags = ThreadFlags::WaitingForData;

		a_this->signalProcessingFinished(index);

		while(a_this->runFlag() || !areThreadsFinished(threadFlags)) {
			threadFlags = a_this->threadFlags(index);

			if(threadFlags == ThreadFlags::DataReady) {
				if(fileParser.isFinished())
					fileParser.setFile(a_this->threadInput(index));

				a_this->setThreadResult(index, fileParser.parseWithKey(key));

				a_this->signalResultsReady(index);

				if(fileParser.isFinished())
					a_this->signalProcessingFinished(index);
			}

			pauseBusyLoop();
		}
	}

	void pauseBusyLoop()
	{
		asm("PAUSE");
	}
}
