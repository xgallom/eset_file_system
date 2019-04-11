//
// Created by xgallom on 4/4/19.
//

#include "FileIndexer.h"
#include "IndexingErrorPresenter.h"

#include <ftw.h>
#include <memory>

namespace FileIndexer
{
	namespace
	{
		// Using unique_ptr to avoid uncaught exception due to static storage duration
		std::unique_ptr<FileIndex> s_fileIndex = {};

		int ftwCallback(const char filePath[], const struct stat *, int fileType)
		{
			switch(fileType) {
				case FTW_F:
					s_fileIndex->enqueue(filePath);
					break;

				case FTW_D:
					// Do nothing
					break;

				case FTW_NS:
					OutputPresenter::presentIndexingError(filePath, Error::NoStat);
					break;

				case FTW_DNR:
					OutputPresenter::presentIndexingError(filePath, Error::DirectoryNotRead);
					break;

				case FTW_SL:
					OutputPresenter::presentIndexingError(filePath, Error::SymlinkNotFollowed);
					break;

				default:
					OutputPresenter::presentIndexingError(filePath, Error::UnknownFileType);
					return EXIT_FAILURE;
			}

			return EXIT_SUCCESS;
		}
	}

	FileIndex indexDirectory(const std::string &path)
	{
		if(!s_fileIndex)
			s_fileIndex = std::make_unique<FileIndex>();
		else
			s_fileIndex->clear();

		switch(ftw(path.c_str(), &ftwCallback, 10)) {
			case 0:
				return *s_fileIndex;

			case -1:
				throw Exception::IndexingFailed();

			default:
				throw Exception::FileIndexingFailed();
		}
	}
}
