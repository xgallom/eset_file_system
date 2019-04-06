//
// Created by xgallom on 4/5/19.
//

#include "OutputPresenter.h"
#include "Arguments/ArgumentsUsage.h"

#include <iostream>
#include <unordered_map>
#include <regex>

namespace OutputPresenter
{
	namespace
	{
		std::string formatString(std::string string)
		{
			static const std::unordered_map<std::string, std::string> replacementTable = {
					{"\n", "\\n"},
					{"\t", "\\t"}
			};

			for(const auto &entry : replacementTable)
				string = std::regex_replace(string, std::regex(entry.first), entry.second);

			return string;
		}
	}

	void presentSearchResults(const std::string &fileName, const std::vector<FileParser::SearchIndex> &searchResults)
	{
		for(const auto &result : searchResults) {
			std::cout
					<< fileName << "(" << result.filePosition() << "): "
					<< formatString(result.prefix()) << "..." << formatString(result.suffix()) << "\n";
		}
	}

	void presentIndexingError(const std::string &filePath, FileIndexer::Error::Enum errorType)
	{
		static const std::array<std::string, FileIndexer::Error::Size> errorTexts = {
				"Stat call failed",
				"Directory could not be read\n",
				"Symbolic link not followed/file does not exist\n",
				"Unknown file type\n"
		};

		std::cerr << filePath << ": " << errorTexts[errorType] << "\n";
	}

	int presentException(const std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;

		return EXIT_FAILURE;
	}

	void presentUsage()
	{
		std::cout << Arguments::UsageText << std::endl;
	}
}
