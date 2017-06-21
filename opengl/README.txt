www.cnblogs.com/liangliangh/p/3521381.html

How to compile glew?
1. sudo apt install libgl-dev
2. cd build
3. cmake -DCMAKE_INSTALL_PREFIX=~/install -DBUILD_UTILS=ON ./cmake
4. make -j4 glew
   make -j4 glew_s
   make -j4 glewinfo
   make -j4 visualinfo
5. make install

Using apt-file to search missing file or library
1. sudo apt install apt-file
2. apt-file update
3. apt-file search glu.h
   apt-file search XInput.h

How to compile freeglut?
1. sudo apt install libglu1-mesa-dev(for missing glu.h)
2. sudo apt install libxi-dev(for missing XInput.h)
3. mkdir build, cd build
4. cmake -DCMAKE_INSTALL_PREFIX=~/install -DCMAKE_BUILD_TYPE=Release
   -DFREEGLUT_BUILD_DEMOS=ON -DFREEGLUT_REPLACE_GLUT=OFF ..
   (will generate dynamic and static library as default)
5. make
6. make install

How to compile glfw?
1. sudo apt install xorg-dev
2. mkdir build, cd build
3. ccmake ..
4. configure the cmake
   BUILD_SHARED_LIBS = TRUE
   CMAKE_BUILD_TYPE = Release
   CMAKE_INSTALL_PREFIX = ~/install
5. make
6. make install

For Windows:
  freeglut -- static lib(not used)
  glfw     -- shared lib(dll)
  glew     -- shared lib(dll)

For linux:
  freeglut -- shared lib(so)
  glew     -- shared lib(so)

If "cannot open shared object file" error happen, run the following command:
0. ldd glApp
1. cd third_party/unix/lib
2. sudo ldconfig `pwd`
4. ldconfig -p | grep freeglut

https://learnopengl-cn.github.io
http://www.lurklurk.org/linkers/linkers.html
