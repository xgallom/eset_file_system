//
// Created by xgallom on 4/12/19.
//

#ifndef ESET_FILE_SYSTEM_PARSINGSCHEDULERTHREADPOOL_H
#define ESET_FILE_SYSTEM_PARSINGSCHEDULERTHREADPOOL_H

#include "ParsingSchedulerThreadPoolIterator.h"

#include <vector>
#include <thread>

namespace ParsingScheduler
{
	class ThreadPool {
	public:
		explicit ThreadPool(unsigned int threadCount, const std::string &key);
		~ThreadPool() noexcept;

		bool isFinished() const noexcept;
		void stopThreads() noexcept;
		Optional<ParsingResult> consumeResults(size_t threadIndex, ThreadFlags::Enum threadFlags) noexcept;
		ThreadFlags::Enum threadFlags(size_t threadIndex) const noexcept;
		void setThreadInput(size_t threadIndex, std::string &&input) noexcept;

		ThreadPoolIterator begin() noexcept;
		ThreadPoolIterator end() noexcept;

	private:
		void signalProcessingFinished(size_t threadIndex) noexcept;
		void signalResultsReady(size_t threadIndex) noexcept;
		bool runFlag() const noexcept;
		std::string threadInput(size_t threadIndex) noexcept;
		void setThreadResult(size_t threadIndex, ParsingResult &&result) noexcept;

		ThreadFlags m_threadFlags = {};

		std::vector<std::thread> m_threadPool = {};
		std::vector<std::string> m_threadInputs = {};
		std::vector<ParsingResult> m_threadResults = {};
		std::atomic<bool> m_runFlag;

		static void threadHandler(ThreadPool *a_this, size_t index, const std::string &key);
	};

	void pauseBusyLoop();
}

#endif //ESET_FILE_SYSTEM_PARSINGSCHEDULERTHREADPOOL_H
