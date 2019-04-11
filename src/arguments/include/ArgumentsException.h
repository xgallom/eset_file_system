//
// Created by xgallom on 4/4/19.
//

#ifndef ESET_FILE_SYSTEM_ARGUMENTSEXCEPTION_H
#define ESET_FILE_SYSTEM_ARGUMENTSEXCEPTION_H

#include <stdexcept>

namespace Arguments
{
	struct Exception : public std::runtime_error {
		explicit Exception(const std::string &a_what);

		static Exception InvalidArgCount(int argCount);
		static Exception InvalidKeyLength(const std::string &key);
		static Exception InvalidOption(const std::string &option);
	};
}

#endif //ESET_FILE_SYSTEM_ARGUMENTSEXCEPTION_H
