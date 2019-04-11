//
// Created by xgallom on 4/5/19.
//

#include "ParsingScheduler.h"

namespace ParsingScheduler
{
	ParsingScheduler::ParsingScheduler(FileIndexer::FileIndex &&a_fileIndex) noexcept :
			m_fileIndex(a_fileIndex)
	{}

	bool ParsingScheduler::isFinished() const
	{
		return m_fileIndex.isEmpty();
	}

	std::string ParsingScheduler::nextFileName()
	{
		return m_fileIndex.dequeue();
	}
}
