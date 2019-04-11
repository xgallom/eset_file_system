//
// Created by xgallom on 4/4/19.
//

#ifndef ESET_FILE_SYSTEM_APPLICATION_H
#define ESET_FILE_SYSTEM_APPLICATION_H

#include <string>

namespace Application
{
	int run(const std::string &path, const std::string &key, bool parallelize);
}

#endif //ESET_FILE_SYSTEM_APPLICATION_H
