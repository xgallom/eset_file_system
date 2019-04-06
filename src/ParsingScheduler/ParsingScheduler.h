//
// Created by xgallom on 4/5/19.
//

#ifndef ESET_FILE_SYSTEM_PARSINGSCHEDULER_H
#define ESET_FILE_SYSTEM_PARSINGSCHEDULER_H

#include "FileIndexer/FileIndex.h"
#include "ParsingResult.h"

#include <vector>

namespace ParsingScheduler
{
	class ParsingScheduler {
	public:
		explicit ParsingScheduler(FileIndexer::FileIndex &&a_fileIndex) noexcept;
		virtual ~ParsingScheduler() = default;

		virtual std::vector<ParsingResult> run() = 0;
		virtual bool isFinished() const;

	protected:
		std::string nextFileName();

	private:
		FileIndexer::FileIndex m_fileIndex;
	};
}
#endif //ESET_FILE_SYSTEM_PARSINGSCHEDULER_H
