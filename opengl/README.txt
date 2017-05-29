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
