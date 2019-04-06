//
// Created by xgallom on 4/4/19.
//

#include "FileReader.h"
#include "FileParserException.h"

namespace FileParser
{
	static constexpr size_t BufferSize = 2048;

	FileReader::FileReader()
	{ construct(); }

	FileReader::FileReader(const std::string &a_fileName)
	{
		construct();
		setFile(a_fileName);
	}

	void FileReader::construct()
	{
		m_buffer.reserve(BufferSize);
	}

	Optional<std::string> FileReader::readChunk()
	{
		if(!chunkAvailable())
			return {};

		m_buffer.resize(BufferSize);

		m_file.read(&*m_buffer.begin(), BufferSize);

		if(m_file.bad())
			throw Exception::FileReadFailed(m_fileName, m_file.tellg());

		m_buffer.resize(static_cast<size_t>(m_file.gcount()));

		return optional(m_buffer);
	}

	void FileReader::setFile(const std::string &a_fileName)
	{
		m_fileName = a_fileName;
		m_file.close();
		m_file.open(a_fileName);

		if(!m_file.is_open())
			throw Exception::FileOpenFailed(a_fileName);
	}

	std::string FileReader::fileName() const
	{
		return m_fileName;
	}

	bool FileReader::chunkAvailable() const noexcept
	{
		return !m_file.eof();
	}
}
