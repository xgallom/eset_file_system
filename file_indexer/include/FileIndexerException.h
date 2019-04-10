//
// Created by xgallom on 4/4/19.
//

#ifndef ESET_FILE_SYSTEM_FILEINDEXEREXCEPTION_H
#define ESET_FILE_SYSTEM_FILEINDEXEREXCEPTION_H

#include <stdexcept>

namespace FileIndexer
{
	struct Exception : public std::runtime_error {
		explicit Exception(const std::string &a_what);

		static Exception FileIndexingFailed();
		static Exception IndexingFailed();
	};
}

#endif //ESET_FILE_SYSTEM_FILEINDEXEREXCEPTION_H
