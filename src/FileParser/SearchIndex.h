//
// Created by xgallom on 4/4/19.
//

#ifndef ESET_FILE_SYSTEM_SEARCHINDEX_H
#define ESET_FILE_SYSTEM_SEARCHINDEX_H

#include <string>
#include <array>

namespace FileParser
{
	class SearchIndex {
	public:
		static constexpr size_t
				PrefixSize = 3,
				SuffixSize = PrefixSize;

		SearchIndex() noexcept = default;
		SearchIndex(size_t a_filePosition, const char a_prefix[]);

		size_t filePosition() const;

		std::string prefix() const;
		std::string suffix() const;

		void setSuffix(const char a_suffix[]);
		void appendSuffix(char c);

		bool hasFullSuffix() const noexcept;

	private:
		size_t m_filePosition = 0;

		// + 1 to store '\0'
		std::array<char, PrefixSize + 1> m_prefix = {};
		std::array<char, SuffixSize + 1> m_suffix = {};

		unsigned char m_suffixSize = 0;
	};
}

#endif //ESET_FILE_SYSTEM_SEARCHINDEX_H
