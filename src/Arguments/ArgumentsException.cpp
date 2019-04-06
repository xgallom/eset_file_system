//
// Created by xgallom on 4/4/19.
//

#include "ArgumentsException.h"
#include "ArgumentsConfig.h"

#include <sstream>

namespace Arguments
{
	Exception::Exception(const std::string &a_what) :
			std::runtime_error(a_what)
	{}

	Exception Exception::InvalidArgCount(int argCount)
	{
		std::stringstream stream;

		// count - 1 because argument[0] is the program name
		stream << "Program expects between " << (MinArgCount - 1) << " and " << (MaxArgCount - 1) << " arguments, "
			   << (argCount - 1) << " provided";

		return Exception(stream.str());
	}

	Exception Exception::InvalidKeyLength(const std::string &key)
	{
		std::stringstream stream;

		stream << "Key \"" << key << "\" with length " << key.length() << " is either empty, or too long.\n"
			   << "Maximum allowed key length is " << MaximumKeyLength;

		return Exception(stream.str());
	}

	Exception Exception::InvalidOption(const std::string &option)
	{
		std::stringstream stream;

		stream << "Invalid option " << option;

		return Exception(stream.str());
	}
}
