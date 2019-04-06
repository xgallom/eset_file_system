//
// Created by xgallom on 4/5/19.
//

#include "SuffixWaitingQueue.h"

namespace FileParser
{
	SuffixWaitingQueue::SuffixWaitingQueue()
	{
		m_waitingQueue.reserve(SearchIndex::SuffixSize);
	}

	Optional<SearchIndex> SuffixWaitingQueue::updateWaitingQueue(char c, Optional<SearchIndex> newIndex)
	{
		const auto result = updateExistingIndexes(c);

		if(newIndex) {
			newIndex().appendSuffix(c);
			m_waitingQueue.enqueue(newIndex());
		}

		return result;
	}

	std::vector<SearchIndex> SuffixWaitingQueue::pullUnfinishedIndexes() noexcept
	{
		return m_waitingQueue.dequeueAll();
	}

	Optional<SearchIndex> SuffixWaitingQueue::updateExistingIndexes(char c)
	{
		if(!m_waitingQueue.isEmpty()) {
			for(auto &waitingIndex : m_waitingQueue)
				waitingIndex.appendSuffix(c);

			return checkFirstWaitingIndex();
		}

		return {};
	}

	Optional<SearchIndex> SuffixWaitingQueue::checkFirstWaitingIndex()
	{
		const auto &firstIndex = m_waitingQueue.front();

		if(firstIndex.hasFullSuffix())
			return optional(m_waitingQueue.dequeue());

		return {};
	}
}
