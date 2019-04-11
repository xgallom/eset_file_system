//
// Created by xgallom on 4/5/19.
//

#ifndef ESET_FILE_SYSTEM_PARSINGRESULT_H
#define ESET_FILE_SYSTEM_PARSINGRESULT_H

#include "SearchIndex.h"

#include <vector>

namespace ParsingScheduler
{
	class ParsingResult {
	public:
		ParsingResult() = default;
		ParsingResult(const std::string &a_fileName, std::vector<FileParser::SearchIndex> &&a_index);

		std::string fileName() const;
		const std::vector<FileParser::SearchIndex> &index() const;
		std::vector<FileParser::SearchIndex> &index();

		explicit operator bool() const noexcept;

	private:
		std::string m_fileName = "";
		std::vector<FileParser::SearchIndex> m_index = {};
	};
}

#endif //ESET_FILE_SYSTEM_PARSINGRESULT_H
