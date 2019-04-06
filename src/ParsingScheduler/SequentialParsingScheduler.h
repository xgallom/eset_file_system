//
// Created by xgallom on 4/5/19.
//

#ifndef ESET_FILE_SYSTEM_SEQUENTIALPARSINGSCHEDULER_H
#define ESET_FILE_SYSTEM_SEQUENTIALPARSINGSCHEDULER_H

#include "ParsingScheduler.h"

#include "FileParser/FileParser.h"

namespace ParsingScheduler
{
	class SequentialParsingScheduler : public ParsingScheduler {
	public:
		explicit SequentialParsingScheduler(FileIndexer::FileIndex &&a_fileIndex, const std::string &a_key);

		std::vector<ParsingResult> run() final;
		bool isFinished() const final;

	private:
		const std::string m_key;
		FileParser::FileParser m_fileParser = {};
	};
}

#endif //ESET_FILE_SYSTEM_SEQUENTIALPARSINGSCHEDULER_H
