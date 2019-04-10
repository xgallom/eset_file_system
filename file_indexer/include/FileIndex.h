//
// Created by xgallom on 4/4/19.
//

#ifndef ESET_FILE_SYSTEM_FILEINDEX_H
#define ESET_FILE_SYSTEM_FILEINDEX_H

#include "Queue.h"

#include <string>
#include <deque>

namespace FileIndexer
{
	using FileIndex = Queue<std::deque<std::string>>;
}

#endif //ESET_FILE_SYSTEM_FILEINDEX_H
