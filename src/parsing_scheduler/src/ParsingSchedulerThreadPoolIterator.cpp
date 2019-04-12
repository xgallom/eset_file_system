//
// Created by xgallom on 4/12/19.
//

#include "ParsingSchedulerThreadPoolIterator.h"
#include "ParsingSchedulerThreadPool.h"

namespace ParsingScheduler
{
	ThreadPoolIterator::ThreadPoolIterator(ThreadPool &threadPool, size_t index) noexcept :
			m_threadPool(threadPool),
			m_index(index),
			m_threadFlags(threadPool.threadFlags(index))
	{}

	Optional<ParsingResult> ThreadPoolIterator::consumeResults() noexcept
	{
		return m_threadPool.consumeResults(m_index, m_threadFlags);
	}

	bool ThreadPoolIterator::processing() const noexcept
	{
		return m_threadFlags & ThreadFlags::Processing;
	}

	void ThreadPoolIterator::setInput(std::string &&input) noexcept
	{
		m_threadPool.setThreadInput(m_index, std::move(input));
	}

	ThreadPoolIterator &ThreadPoolIterator::operator*() noexcept
	{
		return *this;
	}

	ThreadPoolIterator &ThreadPoolIterator::operator++() noexcept
	{
		m_threadFlags = m_threadPool.threadFlags(++m_index);
		return *this;
	}

	bool ThreadPoolIterator::operator==(const ThreadPoolIterator &r) const noexcept
	{
		return m_index == r.m_index;
	}

	bool ThreadPoolIterator::operator!=(const ThreadPoolIterator &r) const noexcept
	{
		return !(*this == r);
	}
}
