//
// Created by xgallom on 4/4/19.
//

#ifndef ESET_FILE_SYSTEM_FILEPARSER_H
#define ESET_FILE_SYSTEM_FILEPARSER_H

#include "SearchIndex.h"
#include "ParsingScheduler/ParsingResult.h"

#include <string>
#include <vector>
#include <memory>

namespace FileParser
{
	class FileParserImpl;

	class FileParser {
	public:
		FileParser();
		explicit FileParser(const std::string &a_fileName);
		~FileParser();

		ParsingScheduler::ParsingResult parseWithKey(const std::string &key);
		void setFile(const std::string &a_fileName);

		bool isFinished() const noexcept;

	private:
		std::unique_ptr<FileParserImpl> m_impl;
	};
}

#endif //ESET_FILE_SYSTEM_FILEPARSER_H
