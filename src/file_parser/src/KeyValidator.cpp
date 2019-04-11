//
// Created by xgallom on 4/4/19.
//

#include "KeyValidator.h"

namespace FileParser
{
	Optional<SearchIndex>
	KeyValidator::validate(size_t filePosition, const char *prefix, char c, const std::string &key)
	{
		const auto result = validateExistingIndexes(filePosition, c, key);

		validateNewIndex(filePosition, prefix, c, key);

		return result;
	}

	void KeyValidator::clear()
	{
		m_unvalidatedIndexes.clear();
		m_unvalidatedSwapBuffer.clear();
	}

	Optional<SearchIndex> KeyValidator::validateExistingIndexes(size_t filePosition, char c, const std::string &key)
	{
		m_unvalidatedSwapBuffer.clear();

		const auto result = populateSwapBuffer(filePosition, c, key);

		std::swap(m_unvalidatedIndexes, m_unvalidatedSwapBuffer);

		return result;
	}

	Optional<SearchIndex> KeyValidator::populateSwapBuffer(size_t filePosition, char c, const std::string &key)
	{
		Optional<SearchIndex> result = {};

		for(const auto &searchIndex : m_unvalidatedIndexes) {
			const auto offset = filePosition - searchIndex.filePosition();

			// The index is valid and complete, we move it out
			if(offset >= key.size())
				result.set(searchIndex);
				// The index is valid but still incomplete, so we move it to the next validation round
			else if(key[offset] == c)
				m_unvalidatedSwapBuffer.push_back(searchIndex);
			// Invalid indexes disappear because they don't get transferred to the swap buffer
		}

		return result;
	}

	void KeyValidator::validateNewIndex(size_t filePosition, const char *prefix, char c, const std::string &key)
	{
		if(c == key.front())
			m_unvalidatedIndexes.emplace_back(filePosition, prefix);
	}
}
