//
// Created by xgallom on 4/5/19.
//

#ifndef ESET_FILE_SYSTEM_PARALLELPARSINGSCHEDULER_H
#define ESET_FILE_SYSTEM_PARALLELPARSINGSCHEDULER_H

#include "ParsingScheduler.h"
#include "ParsingSchedulerThreadPool.h"

namespace ParsingScheduler
{
	class ParallelParsingScheduler : public ParsingScheduler {
	public:
		explicit ParallelParsingScheduler(FileIndexer::FileIndex &&a_fileIndex, const std::string &key);

		std::vector<ParsingResult> run() final;
		bool isFinished() const final;

	private:
		ThreadPool m_threadPool;
	};
}

#endif //ESET_FILE_SYSTEM_PARALLELPARSINGSCHEDULER_H
