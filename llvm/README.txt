Offical website only provide the pre-build binary for x86_64, so we need to
build the llvm for 32-bit os by ourself.

1. unzip llvm-3.6.1.src.tar.xz to llvm-3.6.1.src
2. rename llvm-3.6.1.src to src
3. unzip cfe-3.6.1.src.tar.xz to cfe-3.6.1.src
4. move the cfe-3.6.1.src to src/tools
5. rename cfe-3.6.1.src to clang

# get the following instructions from src/docs/GettingStarged/rst
6. cd build
7. ../src/configure --prefix=/home/stevenyou/software/llvm/install
--enable-optimized --enable-assertions=NO
8. make
9. make install
