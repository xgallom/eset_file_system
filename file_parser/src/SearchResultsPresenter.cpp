//
// Created by xgallom on 4/10/19.
//

#include "SearchResultsPresenter.h"

#include <regex>
#include <iostream>

namespace OutputPresenter
{
	namespace
	{
		struct {
			char symbol[2];
			char replacement[3];
		} constexpr ReplacementTable[] = {
				{"\n", "\\n"},
				{"\t", "\\t"}
		};

		std::string formatString(std::string string)
		{
			for(const auto &entry : ReplacementTable)
				string = std::regex_replace(string, std::regex(entry.symbol), entry.replacement);

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
}

