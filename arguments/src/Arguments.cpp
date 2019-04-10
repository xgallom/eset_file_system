//
// Created by xgallom on 4/4/19.
//

#include "Arguments.h"

#include "ArgumentsConfig.h"

namespace Arguments
{
	Arguments::Arguments(std::string &&a_path, std::string &&a_key, bool a_parallelize) :
			m_path(a_path),
			m_key(a_key),
			m_parallelize(a_parallelize)
	{}

	std::string Arguments::path() const
	{
		return m_path;
	}

	std::string Arguments::key() const
	{
		return m_key;
	}

	bool Arguments::parallelize() const noexcept
	{
		return m_parallelize;
	}

	Arguments parse(int argCount, const char *argValues[])
	{
		if(argCount < MinArgCount || argCount > MaxArgCount)
			throw Exception::InvalidArgCount(argCount);

		std::string
				path = argValues[PathArgIndex],
				key = argValues[KeyArgIndex];

		bool parallelize = false;

		if(key.length() && key.length() > MaximumKeyLength)
			throw Exception::InvalidKeyLength(key);

		if(argCount == MaxArgCount) {
			const std::string parallelizeOption = argValues[ParallelArgIndex];

			if(parallelizeOption == "-p")
				parallelize = true;
			else
				throw Exception::InvalidOption(parallelizeOption);
		}

		return {std::move(path), std::move(key), parallelize};
	}
}
