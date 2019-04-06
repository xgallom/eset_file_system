//
// Created by xgallom on 4/4/19.
//

#ifndef ESET_FILE_SYSTEM_ARGUMENTS_H
#define ESET_FILE_SYSTEM_ARGUMENTS_H

#include "ArgumentsException.h"

#include <string>

namespace Arguments
{
	class Arguments {
	public:
		std::string path() const;
		std::string key() const;
		bool parallelize() const noexcept;

		Arguments() = default;
		Arguments(std::string &&a_path, std::string &&a_key, bool a_parallelize);

	private:
		std::string m_path = {};
		std::string m_key = {};
		bool m_parallelize = false;
	};

	Arguments parse(int argCount, const char *argValues[]);
}

#endif //ESET_FILE_SYSTEM_ARGUMENTS_H
