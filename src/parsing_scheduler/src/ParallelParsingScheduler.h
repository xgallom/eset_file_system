//
// Created by xgallom on 4/5/19.
//

#ifndef ESET_FILE_SYSTEM_PARALLELPARSINGSCHEDULER_H
#define ESET_FILE_SYSTEM_PARALLELPARSINGSCHEDULER_H

#include "ParsingScheduler.h"
#include "ParallelParsingSchedulerThreadFlags.h"

#include <thread>

namespace ParsingScheduler
{
	class ParallelParsingScheduler : public ParsingScheduler {
	public:
		explicit ParallelParsingScheduler(FileIndexer::FileIndex &&a_fileIndex, const std::string &key);
		~ParallelParsingScheduler() final;

		std::vector<ParsingResult> run() final;
		bool isFinished() const final;

	private:
		void disableRunFlag();

		ThreadFlags m_threadFlags = {};

		std::vector<std::thread> m_threadPool = {};
		std::vector<std::string> m_threadInputs = {};
		std::vector<ParsingResult> m_threadResults = {};
		std::atomic<bool> m_runFlag;

		static void threadHandler(ParallelParsingScheduler *scheduler, size_t index, const std::string &key);
	};
}

#endif //ESET_FILE_SYSTEM_PARALLELPARSINGSCHEDULER_H
