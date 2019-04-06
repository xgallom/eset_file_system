//
// Created by xgallom on 4/4/19.
//

#ifndef ESET_FILE_SYSTEM_FILEPARSEREXCEPTION_H
#define ESET_FILE_SYSTEM_FILEPARSEREXCEPTION_H

#include <stdexcept>

namespace FileParser
{
	struct Exception : public std::runtime_error {
		explicit Exception(const std::string &a_what);

		static Exception FileOpenFailed(const std::string &fileName);
		static Exception FileReadFailed(const std::string &fileName, long position);
	};
}

#endif //ESET_FILE_SYSTEM_FILEPARSEREXCEPTION_H
