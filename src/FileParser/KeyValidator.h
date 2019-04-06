//
// Created by xgallom on 4/4/19.
//

#ifndef ESET_FILE_SYSTEM_KEYVALIDATOR_H
#define ESET_FILE_SYSTEM_KEYVALIDATOR_H

#include "SearchIndex.h"
#include "Utility/Optional.h"

#include <vector>

namespace FileParser
{
	class KeyValidator {
	public:
		Optional<SearchIndex> validate(size_t filePosition, const char *prefix, char c, const std::string &key);
		void clear();

	private:
		Optional<SearchIndex> validateExistingIndexes(size_t filePosition, char c, const std::string &key);
		Optional<SearchIndex> populateSwapBuffer(size_t filePosition, char c, const std::string &key);
		void validateNewIndex(size_t filePosition, const char *prefix, char c, const std::string &key);

		std::vector<SearchIndex>
				m_unvalidatedIndexes = {},
				m_unvalidatedSwapBuffer = {};
	};
}


#endif //ESET_FILE_SYSTEM_KEYVALIDATOR_H
