//
// Created by xgallom on 4/10/19.
//

#include "ArgumentsUsagePresenter.h"

#include <iostream>

namespace OutputPresenter
{
	static constexpr char UsageText[] =
			"\n"
			"Usage:\n"
			"  eset_file_system <target_path> <key>\n"
			"  eset_file_system <target_path> <key> -p\n"
			"\n"
			"Arguments:\n"
			"  <target_path> - A path to search in for the key, can be either a single file, or a directory\n"
			"                  If it's a directory, it will be scanned recursively\n"
			"  <key>         - A string literal to search for in the path specified by the target_path\n"
			"\n"
			"Options:\n"
			"  -p            - Runs the application in multi-threaded processing mode\n"
			"                  Note that file indexing will still be done synchronously\n";

	void presentArgumentsUsage()
	{
		std::cout << UsageText << std::endl;
	}
}
