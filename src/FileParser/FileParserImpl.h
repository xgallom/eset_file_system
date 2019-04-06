//
// Created by xgallom on 4/4/19.
//

#ifndef ESET_FILE_SYSTEM_FILEPARSERINTERNAL_H
#define ESET_FILE_SYSTEM_FILEPARSERINTERNAL_H

#include "FileReader.h"
#include "KeyValidator.h"
#include "SuffixWaitingQueue.h"

namespace FileParser
{
	class FileParserImpl {
	public:
		FileParserImpl();
		explicit FileParserImpl(const std::string &a_fileName);

		std::vector<SearchIndex> parseWithKey(const std::string &key);
		void setFile(const std::string &a_fileName);

		bool isFinished() const noexcept;
		std::string fileName() const;

	private:
		void construct();

		bool prepareNextChunk();
		void processNewChunk(const std::string &key);
		void processCharacter(size_t filePosition, char c, const std::string &key);
		void addToPrefix(char c);
		void addUnfinishedIndexes();

		FileReader m_fileReader = {};
		KeyValidator m_keyValidator = {};
		SuffixWaitingQueue m_suffixWaitingQueue = {};

		size_t
				m_chunkPosition = 0,
				m_chunkIndex = 0;

		std::string
				m_currentPrefix = {},
				m_dataChunk = {};

		std::vector<SearchIndex>
				m_validIndexes = {};

		bool m_isFinished = false;
	};
}

#endif //ESET_FILE_SYSTEM_FILEPARSERINTERNAL_H
