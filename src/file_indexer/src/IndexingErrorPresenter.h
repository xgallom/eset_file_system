//
// Created by xgallom on 4/10/19.
//

#ifndef ESET_FILE_SYSTEM_INDEXINGERRORPRESENTER_H
#define ESET_FILE_SYSTEM_INDEXINGERRORPRESENTER_H

#include "FileIndexerError.h"

#include <string>

namespace OutputPresenter
{
	void presentIndexingError(const std::string &filePath, FileIndexer::Error::Enum errorType);
}

#endif //ESET_FILE_SYSTEM_INDEXINGERRORPRESENTER_H
