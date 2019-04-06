//
// Created by xgallom on 4/5/19.
//

#include "SequentialParsingScheduler.h"
#include "FileParser/FileParser.h"

namespace ParsingScheduler
{
	SequentialParsingScheduler::SequentialParsingScheduler(FileIndexer::FileIndex &&a_fileIndex,
														   const std::string &a_key) :
			ParsingScheduler(std::move(a_fileIndex)),
			m_key(a_key)
	{}

	std::vector<ParsingResult> SequentialParsingScheduler::run()
	{
		if(m_fileParser.isFinished())
			m_fileParser.setFile(nextFileName());

		return {m_fileParser.parseWithKey(m_key)};
	}

	bool SequentialParsingScheduler::isFinished() const
	{
		return ParsingScheduler::isFinished() && m_fileParser.isFinished();
	}
}
