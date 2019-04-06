//
// Created by xgallom on 4/4/19.
//

#ifndef ESET_FILE_SYSTEM_ARGUMENTSUSAGE_H
#define ESET_FILE_SYSTEM_ARGUMENTSUSAGE_H

namespace Arguments
{
	constexpr char UsageText[] =
			"\n"
			"Usage:\n"
			"  eset_file_system <target_path> <key>\n"
			"  eset_file_system <target_path> <key> -p\n"
			"\n"
			"Arguments:\n"
			"  <target_path> - A path to search in for the key, can be either a single file, or a directory\n"
			"                  If it's a directory, it will be scanned recursively\n"
			"  <key>         - A string literal to search for in the path specified by the search_path\n"
			"\n"
			"Options:\n"
			"  -p            - Runs the application in multi-threaded processing mode\n"
			"                  Note that file indexing will still be done synchronously\n";
}

#endif //ESET_FILE_SYSTEM_ARGUMENTSUSAGE_H
