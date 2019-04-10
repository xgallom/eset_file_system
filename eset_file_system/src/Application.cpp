//
// Created by xgallom on 4/4/19.
//

#include "Application.h"

#include "FileIndexer.h"
#include "ParsingSchedulerBuilder.h"
#include "SearchResultsPresenter.h"
#include "ExceptionPresenter.h"

namespace Application
{
	int run(const std::string &path, const std::string &key, bool runParallel)
	{
		FileIndexer::FileIndex fileIndex;

		try {
			fileIndex = FileIndexer::indexDirectory(path);
		}
		catch(FileIndexer::Exception &indexingException) {
			return OutputPresenter::presentException(indexingException);
		}

		auto scheduler = ParsingScheduler::Builder::build(std::move(fileIndex), key, runParallel);

		while(!scheduler->isFinished()) {
			const auto searchResults = scheduler->run();

			for(const auto &searchResult : searchResults)
				OutputPresenter::presentSearchResults(searchResult.fileName(), searchResult.index());
		}

		return EXIT_SUCCESS;
	}
}
