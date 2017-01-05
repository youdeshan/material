Compile the YCM on Ubuntu 16.04 LTS

1. sudo apt-get install cmake
2. sudo apt-get install python-dev python3-dev
3. mkdir ycm/build, cd to this directory

# Use of a custom-build libclang library(download the source code from llvm.org and compile it by youself)
4. cmake -G "Unix Makefiles" -DEXTERNAL_LIBCLANG_PATH=~/software/llvm/install/lib/libclang.so . ~/.vim/bundle/YouCompleteMe/third_party/ycmd/cpp

# Use of downloaded binary distribution of LLVM+Clang from llvm.org
# PATH_TO_LLVM_ROOT is specified to the binary extracted folder(with bin,lib,include etc. folders)
4. cmake -G "Unix Makefiles" -DPATH_TO_LLVM_ROOT=~/software/llvm/from_binary . ~/.vim/bundle/YouCompleteMe/third_party/ycmd/cpp

5. cmake --build . --target ycm_core 
   it will generate 'ycm_core.so' file under ~/.vim/bundle/YouCompleteMe/third_party/ycmd
   it will also copy 'libclang.so' to this folder

6. cp ~/.vim/bundle/third_party/ycmd/cpp/ycm/.ycm_extra_conf.py ~
   and comment the unnecessary flags, such as '-DUSE_CLANG_COMPILER'

Note: the c++ compiler already installed on Ubuntu 16.04, so don't need to
install the compiler by yourself(sudo apt-get install g++)

error 1: "YCM is compiled with Python2, but loaded with Python3"
solution: add 'let g:ycm_path_to_python_interpreter= '/usr/bin/python'' to ~/.vimrc

Support javascript:
1. install Node.js and npm
   1.1 sudo git clone https://github.com/nodejs/node.git
   1.2 sudo chmod -R 755 node
   1.3 cd node
       sudo ./configure --prefix=~/install
       sudo make
       sudo make install
   1.4 node --version

2. navigate to ~/.vim/bundle/YouCompleteMe/third_party/ycmd/third_party/tern_runtime
   run cmd: npm install --production

3. modify ~/.vimrc
   let g:ycm_filetype_whitelist = { 'cpp' : 1, 'c' : 1, 'javascript' : 1} 

Support python:
1. By default YCM runs jedi with the same Python interpreter used by the ycmd
server, so if you would like to use a different interpreter, use the following
option specifying the Python binary to use:
let g:ycm_python_binary_path = '/usr/bin/python'

2. let g:ycm_filetype_whitelist = { 'cpp' : 1, 'c' : 1, 'javascript' : 1,
    'python' : 1} 

That's OK, enjoy the javascript and python world!
