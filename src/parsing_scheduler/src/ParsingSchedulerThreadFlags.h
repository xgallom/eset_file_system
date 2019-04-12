//
// Created by xgallom on 4/6/19.
//

#ifndef ESET_FILE_SYSTEM_PARSINGSCHEDULERTHREADFLAGS_H
#define ESET_FILE_SYSTEM_PARSINGSCHEDULERTHREADFLAGS_H

#include <atomic>
#include <cstddef>

namespace ParsingScheduler
{
	class ThreadFlags {
	public:
		// Two bits for each thread, up to 2 * 16 = 32 bits
		enum Enum : uint32_t {
			WaitingForData = 0,
			Processing = 1,
			ResultsReady = 2,
			IntermediateResults = ResultsReady | Processing
		};

		static constexpr Enum DataReady = Processing;

		static constexpr uint32_t
				BitOffset = 1U,
				BitCount = 1U << BitOffset;

		static constexpr Enum BitMask = IntermediateResults;

		void resetToInitial(size_t threadCount) noexcept;

		Enum flagsForThread(size_t threadIndex,
							std::memory_order memoryOrder = std::memory_order_acquire) const noexcept;
		void setFlagsForThread(size_t threadIndex, Enum flags,
							   std::memory_order memoryOrder = std::memory_order_release) noexcept;
		void clearFlagsForThread(size_t threadIndex, Enum flags,
								 std::memory_order memoryOrder = std::memory_order_release) noexcept;

		uint32_t value() const noexcept;

	private:
		static size_t offsetFor(size_t threadIndex) noexcept;

		std::atomic<uint32_t> m_value;
	};
}

#endif //ESET_FILE_SYSTEM_PARSINGSCHEDULERTHREADFLAGS_H
