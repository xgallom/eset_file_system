//
// Created by xgallom on 4/5/19.
//

#ifndef ESET_FILE_SYSTEM_PARSINGSCHEDULERBUILDER_H
#define ESET_FILE_SYSTEM_PARSINGSCHEDULERBUILDER_H

#include "ParsingScheduler.h"

#include <memory>

namespace ParsingScheduler
{
	namespace Builder
	{
		std::unique_ptr<ParsingScheduler> build(FileIndexer::FileIndex &&fileIndex,
												const std::string &key, bool parallel);
	}
}


#endif //ESET_FILE_SYSTEM_PARSINGSCHEDULERBUILDER_H
