//
// Created by xgallom on 4/4/19.
//

#include "SearchIndex.h"

namespace FileParser
{
	SearchIndex::SearchIndex(size_t a_filePosition, const char a_prefix[]) :
			m_filePosition(a_filePosition)
	{
		std::copy(a_prefix, a_prefix + PrefixSize, m_prefix.begin());
	}

	size_t SearchIndex::filePosition() const
	{
		return m_filePosition;
	}

	std::string SearchIndex::prefix() const
	{
		return m_prefix.data();
	}

	std::string SearchIndex::suffix() const
	{
		return m_suffix.data();
	}

	void SearchIndex::setSuffix(const char *a_suffix)
	{
		std::copy(a_suffix, a_suffix + SuffixSize, m_suffix.begin());
		m_suffixSize = SuffixSize;
	}

	void SearchIndex::appendSuffix(char c)
	{
		if(m_suffixSize < SuffixSize)
			m_suffix[m_suffixSize++] = c;
	}

	bool SearchIndex::hasFullSuffix() const noexcept
	{
		return m_suffixSize >= SuffixSize;
	}
}
