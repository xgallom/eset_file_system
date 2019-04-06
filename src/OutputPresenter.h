//
// Created by xgallom on 4/5/19.
//

#ifndef ESET_FILE_SYSTEM_OUTPUTPRESENTER_H
#define ESET_FILE_SYSTEM_OUTPUTPRESENTER_H

#include "FileParser/SearchIndex.h"
#include "FileIndexer/FileIndexerError.h"

#include <string>
#include <vector>
#include <exception>

namespace OutputPresenter
{
	void presentSearchResults(const std::string &fileName, const std::vector<FileParser::SearchIndex> &searchResults);
	void presentIndexingError(const std::string &filePath, FileIndexer::Error::Enum errorType);
	int presentException(const std::exception &exception);
	void presentUsage();
}


#endif //ESET_FILE_SYSTEM_OUTPUTPRESENTER_H
