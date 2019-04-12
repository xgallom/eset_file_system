//
// Created by xgallom on 4/4/19.
//

#include "FileParserImpl.h"
#include "FileParserException.h"
#include "ExceptionPresenter.h"

namespace FileParser
{
	static constexpr size_t IndexesBuffer = 64;

	FileParserImpl::FileParserImpl() :
			m_isFinished(true)
	{ construct(); }

	FileParserImpl::FileParserImpl(const std::string &a_fileName) :
			m_fileReader(a_fileName)
	{ construct(); }

	void FileParserImpl::construct()
	{
		m_currentPrefix.reserve(SearchIndex::PrefixSize + 1);
	}

	std::vector<SearchIndex> FileParserImpl::parseWithKey(const std::string &key)
	{
		try {
			m_validIndexes.reserve(IndexesBuffer);

			if(prepareNextChunk())
				processNewChunk(key);

			if(!prepareNextChunk()) {
				addUnfinishedIndexes();
				m_isFinished = true;
			}
		}
		catch(std::bad_alloc &badAlloc) {
			// Do nothing
		}
		catch(Exception &fileParserException) {
			OutputPresenter::presentException(fileParserException);
			m_isFinished = true;
		}

		return std::move(m_validIndexes);
	}

	void FileParserImpl::setFile(const std::string &a_fileName)
	{
		m_keyValidator.clear();
		m_suffixWaitingQueue.pullUnfinishedIndexes();

		m_chunkPosition = 0;
		m_chunkIndex = 0;

		m_currentPrefix.clear();
		m_dataChunk.clear();

		m_validIndexes.clear();

		m_isFinished = false;

		m_fileReader.setFile(a_fileName);
	}

	bool FileParserImpl::isFinished() const noexcept
	{
		return m_isFinished;
	}

	std::string FileParserImpl::fileName() const
	{
		return m_fileReader.fileName();
	}

	bool FileParserImpl::prepareNextChunk()
	{
		if(m_chunkIndex == m_dataChunk.size()) {
			// Move current chunk position counter to the beginning of the next chunk of data
			m_chunkPosition += m_dataChunk.size();
			m_chunkIndex = 0;

			auto dataChunk = m_fileReader.readChunk();

			if(dataChunk) {
				m_dataChunk = std::move(dataChunk());

				return true;
			}

			return false;
		}

		return true;
	}

	void FileParserImpl::processNewChunk(const std::string &key)
	{
		const auto size = m_dataChunk.size();

		for(; m_chunkIndex < size; ++m_chunkIndex)
			processCharacter(m_chunkPosition + m_chunkIndex, m_dataChunk[m_chunkIndex], key);
	}

	void FileParserImpl::processCharacter(size_t filePosition, char c, const std::string &key)
	{
		const auto validIndex = m_keyValidator.validate(filePosition,
														m_currentPrefix.c_str(),
														c, key);

		auto suffixedIndex = m_suffixWaitingQueue.updateWaitingQueue(c, validIndex);

		if(suffixedIndex)
			m_validIndexes.push_back(suffixedIndex());

		addToPrefix(c);
	}

	void FileParserImpl::addToPrefix(char c)
	{
		m_currentPrefix.push_back(c);

		if(m_currentPrefix.size() > SearchIndex::PrefixSize)
			m_currentPrefix.erase(m_currentPrefix.begin());
	}

	void FileParserImpl::addUnfinishedIndexes()
	{
		const auto unfinishedIndexes = m_suffixWaitingQueue.pullUnfinishedIndexes();

		m_validIndexes.insert(m_validIndexes.end(), unfinishedIndexes.begin(), unfinishedIndexes.end());
	}
}
