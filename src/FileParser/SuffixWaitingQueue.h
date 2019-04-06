//
// Created by xgallom on 4/5/19.
//

#ifndef ESET_FILE_SYSTEM_SUFFIXWAITINGQUEUE_H
#define ESET_FILE_SYSTEM_SUFFIXWAITINGQUEUE_H

#include "Utility/Optional.h"
#include "Utility/Queue.h"
#include "SearchIndex.h"

#include <vector>

namespace FileParser
{
	class SuffixWaitingQueue {
	public:
		SuffixWaitingQueue();

		Optional<SearchIndex> updateWaitingQueue(char c, Optional<SearchIndex> newIndex);
		std::vector<SearchIndex> pullUnfinishedIndexes() noexcept;

	private:
		Optional<SearchIndex> updateExistingIndexes(char c);
		Optional<SearchIndex> checkFirstWaitingIndex();

		Queue<std::vector<SearchIndex>> m_waitingQueue = {};
	};
}

#endif //ESET_FILE_SYSTEM_SUFFIXWAITINGQUEUE_H
