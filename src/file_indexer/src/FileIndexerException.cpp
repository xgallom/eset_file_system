//
// Created by xgallom on 4/4/19.
//

#include "FileIndexerException.h"

namespace FileIndexer
{
	Exception::Exception(const std::string &a_what) :
			std::runtime_error(a_what)
	{}

	Exception Exception::FileIndexingFailed()
	{
		return Exception("Error indexing directory/file");
	}

	Exception Exception::IndexingFailed()
	{
		return Exception("File indexing failed, make sure the path specified is a valid file or a directory");
	}
}
