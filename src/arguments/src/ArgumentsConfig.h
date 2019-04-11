//
// Created by xgallom on 4/4/19.
//

#ifndef ESET_FILE_SYSTEM_ARGUMENTSCONFIG_H
#define ESET_FILE_SYSTEM_ARGUMENTSCONFIG_H

namespace Arguments
{
	enum ArgumentsIndex {
		FileNameArgIndex = 0,
		PathArgIndex,
		KeyArgIndex,
		ParallelArgIndex
	};

	static constexpr int
			MinArgCount = 3,
			MaxArgCount = 4,
			MaximumKeyLength = 128;
}

#endif //ESET_FILE_SYSTEM_ARGUMENTSCONFIG_H
