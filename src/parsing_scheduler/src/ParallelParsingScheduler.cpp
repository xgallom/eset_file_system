//
// Created by xgallom on 4/5/19.
//

#include "ParallelParsingScheduler.h"

namespace ParsingScheduler
{
	ParallelParsingScheduler::ParallelParsingScheduler(FileIndexer::FileIndex &&a_fileIndex, const std::string &key) :
			ParsingScheduler(std::move(a_fileIndex)),
			m_threadPool(std::min(std::thread::hardware_concurrency(), 16U), key)
	{}

	std::vector<ParsingResult> ParallelParsingScheduler::run()
	{
		std::vector<ParsingResult> result;

		for(auto &thread : m_threadPool) {
			auto threadResult = thread.consumeResults();

			if(threadResult)
				result.emplace_back(std::move(threadResult()));

			if(!ParsingScheduler::isFinished() && !thread.processing()) {
				thread.setInput(nextFileName());

				if(ParsingScheduler::isFinished())
					m_threadPool.stopThreads();
			}

			pauseBusyLoop();
		}

		return result;
	}

	bool ParallelParsingScheduler::isFinished() const
	{
		return ParsingScheduler::isFinished() && m_threadPool.isFinished();
	}
}
