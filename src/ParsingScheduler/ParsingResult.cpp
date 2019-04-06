//
// Created by xgallom on 4/5/19.
//

#include "ParsingResult.h"

namespace ParsingScheduler
{
	ParsingResult::ParsingResult(const std::string &a_fileName, std::vector<FileParser::SearchIndex> &&a_index) :
			m_fileName(a_fileName),
			m_index(std::move(a_index))
	{}

	void ParsingResult::setFileName(const std::string &a_fileName)
	{
		m_fileName = a_fileName;
	}

	std::string ParsingResult::fileName() const
	{
		return m_fileName;
	}

	const std::vector<FileParser::SearchIndex> &ParsingResult::index() const
	{
		return m_index;
	}

	std::vector<FileParser::SearchIndex> &ParsingResult::index()
	{
		return m_index;
	}

	ParsingResult::operator bool() const noexcept
	{
		return !m_fileName.empty();
	}
}
