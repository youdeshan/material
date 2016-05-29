Compile the YCM on Ubuntu 16.04 LTS

1. sudo apt-get install cmake
2. sudo apt-get install python-dev python3-dev
3. mkdir ycm/build, cd to this directory
4. cmake -G "Unix Makefiles" -DEXTERNAL_LIBCLANG_PATH=~/software/llvm/install/lib/libclang.so . ~/.vim/bundle/YouCompleteMe/third_party/ycmd/cpp
5. cmake --build . --target ycm_core 
   it will generate 'ycm_core.so' file under ~/.vim/bundle/YouCompleteMe/third_party/ycmd
   it will also copy 'libclang.so' to this folder

Note: the c++ compiler already installed on Ubuntu 16.04, so don't need to
install the compiler by yourself(sudo apt-get install g++)
