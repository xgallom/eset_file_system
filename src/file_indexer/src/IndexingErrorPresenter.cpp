//
// Created by xgallom on 4/10/19.
//

#include "IndexingErrorPresenter.h"

#include <iostream>

namespace OutputPresenter
{
	static constexpr char ErrorTexts[FileIndexer::Error::Size][48] = {
			"Stat call failed",
			"Directory could not be read\n",
			"Symbolic link not followed/file does not exist\n",
			"Unknown file type\n"
	};

	void presentIndexingError(const std::string &filePath, FileIndexer::Error::Enum errorType)
	{
		std::cerr << filePath << ": " << ErrorTexts[errorType] << "\n";
	}
}
