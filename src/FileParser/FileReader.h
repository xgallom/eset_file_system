//
// Created by xgallom on 4/4/19.
//

#ifndef ESET_FILE_SYSTEM_FILEREADER_H
#define ESET_FILE_SYSTEM_FILEREADER_H

#include "Utility/Optional.h"

#include <string>
#include <fstream>

namespace FileParser
{
	class FileReader {
	public:
		FileReader();
		explicit FileReader(const std::string &a_fileName);

		Optional<std::string> readChunk();
		void setFile(const std::string &a_fileName);

		std::string fileName() const;

	private:
		void construct();

		bool chunkAvailable() const noexcept;

		std::string m_fileName = {};
		std::ifstream m_file = {};
		std::string m_buffer = {};
	};
}

#endif //ESET_FILE_SYSTEM_FILEREADER_H
