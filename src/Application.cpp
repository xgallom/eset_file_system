//
// Created by xgallom on 4/4/19.
//

#include "Application.h"

#include "FileIndexer/FileIndexer.h"
#include "ParsingScheduler/ParsingSchedulerBuilder.h"
#include "OutputPresenter.h"

namespace Application
{
	int run(const std::string &path, const std::string &key, bool runParallel)
	{
		try {
			auto fileIndex = FileIndexer::indexDirectory(path);

			auto scheduler = ParsingScheduler::Builder::build(std::move(fileIndex), key, runParallel);

			while(!scheduler->isFinished()) {
				const auto searchResults = scheduler->run();

				for(const auto &searchResult : searchResults)
					OutputPresenter::presentSearchResults(searchResult.fileName(), searchResult.index());
			}
		}
		catch(FileIndexer::Exception &indexingException) {
			return OutputPresenter::presentException(indexingException);
		}

		return EXIT_SUCCESS;
	}
}
