//
// Created by xgallom on 4/6/19.
//

#include "ParallelParsingSchedulerThreadFlags.h"

namespace ParsingScheduler
{
	void ThreadFlags::resetToInitial(size_t threadCount) noexcept
	{
		uint32_t threadFlags = 0;

		while(threadCount--) {
			threadFlags <<= ThreadFlags::BitCount;
			threadFlags |= ThreadFlags::Processing;
		}

		m_value.store(threadFlags, std::memory_order_relaxed);
	}

	ThreadFlags::Enum ThreadFlags::flagsForThread(size_t threadIndex, std::memory_order memoryOrder) const noexcept
	{
		uint32_t threadFlags = m_value.load(memoryOrder);

		threadFlags >>= offsetFor(threadIndex);
		threadFlags &= ThreadFlags::BitMask;

		return static_cast<ThreadFlags::Enum>(threadFlags);
	}

	void ThreadFlags::setFlagsForThread(size_t threadIndex, Enum flags, std::memory_order memoryOrder) noexcept
	{
		m_value.fetch_or(flags << offsetFor(threadIndex), memoryOrder);
	}

	void ThreadFlags::clearFlagsForThread(size_t threadIndex, Enum flags, std::memory_order memoryOrder) noexcept
	{
		m_value.fetch_and(~(flags << offsetFor(threadIndex)), memoryOrder);
	}

	uint32_t ThreadFlags::value() const noexcept
	{
		return m_value.load(std::memory_order_relaxed);
	}

	size_t ThreadFlags::offsetFor(size_t threadIndex) noexcept
	{
		return threadIndex << ThreadFlags::BitOffset;
	}
}