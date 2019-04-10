//
// Created by xgallom on 4/5/19.
//

#include "ParallelParsingScheduler.h"
#include "FileParser.h"

namespace ParsingScheduler
{
	ParallelParsingScheduler::ParallelParsingScheduler(FileIndexer::FileIndex &&a_fileIndex, const std::string &key) :
			ParsingScheduler(std::move(a_fileIndex)),
			m_runFlag(true)
	{
		const auto threadCount = std::min(std::thread::hardware_concurrency(), 16U);

		m_threadFlags.resetToInitial(threadCount);

		for(size_t n = 0; n < threadCount; ++n) {
			m_threadInputs.emplace_back();
			m_threadResults.emplace_back();

			m_threadPool.emplace_back(threadHandler, this, n, key);
		}
	}

	ParallelParsingScheduler::~ParallelParsingScheduler()
	{
		disableRunFlag();

		for(auto &thread : m_threadPool)
			thread.join();
	}

	std::vector<ParsingResult> ParallelParsingScheduler::run()
	{
		std::vector<ParsingResult> result;

		for(size_t threadIndex = 0; threadIndex < m_threadPool.size(); ++threadIndex) {
			const auto threadFlags = m_threadFlags.flagsForThread(threadIndex);

			if(threadFlags & ThreadFlags::ResultsReady) {
				result.emplace_back(std::move(m_threadResults[threadIndex]));

				m_threadFlags.clearFlagsForThread(threadIndex, ThreadFlags::ResultsReady);
			}

			if(!ParsingScheduler::isFinished() && !(threadFlags & ThreadFlags::Processing)) {
				m_threadInputs[threadIndex] = nextFileName();

				m_threadFlags.setFlagsForThread(threadIndex, ThreadFlags::DataReady);

				if(ParsingScheduler::isFinished())
					disableRunFlag();
			}
		}

		return result;
	}

	bool ParallelParsingScheduler::isFinished() const
	{
		return ParsingScheduler::isFinished() && m_threadFlags.value() == 0;
	}

	void ParallelParsingScheduler::disableRunFlag()
	{
		m_runFlag.store(false, std::memory_order_relaxed);
	}

	void ParallelParsingScheduler::threadHandler(ParallelParsingScheduler *scheduler,
												 size_t index, const std::string &key)
	{
		FileParser::FileParser fileParser;

		scheduler->m_threadFlags.clearFlagsForThread(index, ThreadFlags::Processing);

		ThreadFlags::Enum threadFlags = ThreadFlags::WaitingForData;

		while(scheduler->m_runFlag.load(std::memory_order_relaxed) || threadFlags) {
			threadFlags = scheduler->m_threadFlags.flagsForThread(index);

			if(threadFlags == ThreadFlags::DataReady) {
				if(fileParser.isFinished()) {
					const auto fileName = std::move(scheduler->m_threadInputs[index]);
					fileParser.setFile(fileName);
				}

				scheduler->m_threadResults[index] = fileParser.parseWithKey(key);

				scheduler->m_threadFlags.setFlagsForThread(index, ThreadFlags::ResultsReady);

				if(fileParser.isFinished())
					scheduler->m_threadFlags.clearFlagsForThread(index, ThreadFlags::Processing,
																 std::memory_order_relaxed);
			}
		}
	}
}
