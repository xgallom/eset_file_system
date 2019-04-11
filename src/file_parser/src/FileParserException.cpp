//
// Created by xgallom on 4/4/19.
//

#include "FileParserException.h"

#include <sstream>

namespace FileParser
{
	Exception::Exception(const std::string &a_what) :
			std::runtime_error(a_what)
	{}

	Exception Exception::FileOpenFailed(const std::string &fileName)
	{
		std::stringstream stream;

		stream << fileName << ": Failed to open file";

		return Exception(stream.str());
	}

	Exception Exception::FileReadFailed(const std::string &fileName, long position)
	{
		std::stringstream stream;

		stream << fileName << "(" << position << "): Failed to read from file";

		return Exception(stream.str());
	}
}
