//
// Created by xgallom on 4/10/19.
//

#ifndef ESET_FILE_SYSTEM_SEARCHRESULTSPRESENTER_H
#define ESET_FILE_SYSTEM_SEARCHRESULTSPRESENTER_H

#include "SearchIndex.h"

#include <vector>

namespace OutputPresenter
{
	void presentSearchResults(const std::string &fileName, const std::vector<FileParser::SearchIndex> &searchResults);
}

#endif //ESET_FILE_SYSTEM_SEARCHRESULTSPRESENTER_H
