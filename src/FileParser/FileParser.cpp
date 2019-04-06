//
// Created by xgallom on 4/4/19.
//

#include "FileParser.h"
#include "FileParserImpl.h"

namespace FileParser
{
	FileParser::FileParser() :
			m_impl(std::make_unique<FileParserImpl>())
	{}

	FileParser::FileParser(const std::string &a_fileName) :
			m_impl(std::make_unique<FileParserImpl>(a_fileName))
	{}

	FileParser::~FileParser() = default;

	ParsingScheduler::ParsingResult FileParser::parseWithKey(const std::string &key)
	{
		return {m_impl->fileName(), m_impl->parseWithKey(key)};
	}

	void FileParser::setFile(const std::string &a_fileName)
	{
		m_impl->setFile(a_fileName);
	}

	bool FileParser::isFinished() const noexcept
	{
		return m_impl->isFinished();
	}
}
