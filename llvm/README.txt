Offical website only provide the pre-build binary for x86_64, so we need to
build the llvm for 32-bit os by ourself.

1. tar -xvf llvm-3.6.1.src.tar.xz llvm-3.6.1.src
2. mv llvm-3.6.1.src src
3. tar -xvf cfe-3.6.1.src.tar.xz cfe-3.6.1.src
4. mv cfe-3.6.1.src src/tools
5. mv cfe-3.6.1.src clang

# get the following instructions from src/docs/GettingStarged.rst
6. cd build
7. ../src/configure --prefix=/home/stevenyou/software/llvm/install
--enable-optimized --enable-assertions=NO
8. make
9. make install
