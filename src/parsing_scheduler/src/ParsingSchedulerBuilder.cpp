//
// Created by xgallom on 4/5/19.
//

#include "ParsingSchedulerBuilder.h"
#include "ParallelParsingScheduler.h"
#include "SequentialParsingScheduler.h"

namespace ParsingScheduler
{
	namespace Builder
	{
		std::unique_ptr<ParsingScheduler> build(FileIndexer::FileIndex &&fileIndex, const std::string &key,
												bool parallel)
		{
			if(parallel)
				return std::make_unique<ParallelParsingScheduler>(std::move(fileIndex), key);
			else
				return std::make_unique<SequentialParsingScheduler>(std::move(fileIndex), key);
		}
	}
}
