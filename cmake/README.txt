ExternalProject是一个非常棒的Cmake工具
通过配置Cmake会自动执行下载、配置、编译、安装第三方库几个步骤.
ExternalProject_Add(liblua
    DOWNLOAD_DIR third_party/
    GIT_REPOSITORY https://github.com/elite-lang/lua
    SOURCE_DIR third_party/lua/
    CMAKE_COMMAND cmake
    CMAKE_ARGS "-DCMAKE_INSTALL_PREFIX=${third_party_install_path}"
    # INSTALL_COMMAND ""
    BUILD_ALWAYS 0
    )

CMake常用变量
UNIX 如果为真，表示为 UNIX-like 的系统，包括 AppleOS X 和 CygWin
WIN32 如果为真，表示为 Windows 系统，包括 CygWin
APPLE 如果为真，表示为 Apple 系统
CMAKE_SIZEOF_VOID_P 表示 void* 的大小（例如为 4 或者 8），可以使用其来判断当前构建为 32 位还是 64 位