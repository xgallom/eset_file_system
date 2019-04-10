//
// Created by xgallom on 4/5/19.
//

#ifndef ESET_FILE_SYSTEM_FILEINDEXERERROR_H
#define ESET_FILE_SYSTEM_FILEINDEXERERROR_H

namespace FileIndexer
{
	namespace Error
	{
		enum Enum {
			NoStat = 0,
			DirectoryNotRead,
			SymlinkNotFollowed,
			UnknownFileType
		};

		static constexpr auto Size = UnknownFileType + 1;
	}
}

#endif //ESET_FILE_SYSTEM_FILEINDEXERERROR_H
