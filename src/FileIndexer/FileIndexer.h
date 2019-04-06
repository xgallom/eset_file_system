//
// Created by xgallom on 4/4/19.
//

#ifndef ESET_FILE_SYSTEM_FILEINDEXER_H
#define ESET_FILE_SYSTEM_FILEINDEXER_H

#include "FileIndex.h"
#include "FileIndexerException.h"

namespace FileIndexer
{
	FileIndex indexDirectory(const std::string &path);
}


#endif //ESET_FILE_SYSTEM_FILEINDEXER_H
