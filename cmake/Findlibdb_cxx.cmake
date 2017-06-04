# Findlibdb_cxx.cmake 的命名规范: 
#   FindlibNAME.cmake ,其中NAME 是函数库的名称

MESSAGE(STATUS "Using bundled Findlibdb.cmake...")

FIND_PATH(
    LIBDB_CXX_INCLUDE_DIR
    db_cxx.h 
    /usr/include/ 
    /usr/local/include/ 
)
 
FIND_LIBRARY(
LIBDB_CXX_LIBRARIES NAMES  db_cxx
PATHS /usr/lib/ /usr/local/lib/
)

Note:
line6~11 在 /usr/include/ 和 /usr/local/include/ 中查找文件db_cxx.h ,并将db_cxx.h所在的路径保存在 LIBDB_CXX_INCLUDE_DIR中
line13~16 在目录 /usr/lib/ 和 /usr/local/lib/ 中寻找名称为 db_cxx的链接库,并将结果保存在 LIBDB_CXX_LIBRARIES
