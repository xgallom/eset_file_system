//
// Created by xgallom on 4/12/19.
//

#ifndef ESET_FILE_SYSTEM_PARSINGSCHEDULERTHREADPOOLITERATOR_H
#define ESET_FILE_SYSTEM_PARSINGSCHEDULERTHREADPOOLITERATOR_H

#include "ParsingSchedulerThreadFlags.h"
#include "ParsingResult.h"
#include "Optional.h"

namespace ParsingScheduler
{
	class ThreadPool;

	class ThreadPoolIterator {
	public:
		ThreadPoolIterator(ThreadPool &threadPool, size_t index) noexcept;

		Optional<ParsingResult> consumeResults() noexcept;
		bool processing() const noexcept;
		void setInput(std::string &&input) noexcept;

		ThreadPoolIterator &operator*() noexcept;
		ThreadPoolIterator &operator++() noexcept;

		bool operator==(const ThreadPoolIterator &r) const noexcept;
		bool operator!=(const ThreadPoolIterator &r) const noexcept;

	private:
		ThreadPool &m_threadPool;
		size_t m_index;
		ThreadFlags::Enum m_threadFlags;
	};
}

#endif //ESET_FILE_SYSTEM_PARSINGSCHEDULERTHREADPOOLITERATOR_H
