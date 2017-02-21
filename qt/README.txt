How to install qt5 on Ubuntu

1. download qt-opensource-linux-x64-5.8.0.run from http://download.qt.io/archive/qt/5.8/5.8.0/
2. chmod +x qt-opensource-linux-x64-5.8.0.run
3. ./qt-opensource-linux-x64-5.8.0.run, install qt5.8 to /opt/Qt5.8.0 folder(can be changed to other location with enought disk space)
4. modify /usr/lib/x86_64-linux-gnu/qt-default/qtchooser/default.conf, replace with the following contents:
   /opt/Qt5.8.0/5.8/gcc_64/bin
   /opt/Qt5.8.0

5. Now you can run "qmake --version" to see the QT version information.

Issues:
"/usr/bin/ld: cannot find -lGL" when build qt project

solution 1: 
  if your project doesn't depend on opengl, you can remove the link option for opengl
  1.1 run the link without opengl option from command line
      g++ -Wl,-rpath,/opt/Qt5.8.0/5.8/gcc_64/lib -o HelloWorld main.o mainwindow.o moc_mainwindow.o   -L/opt/Qt5.8.0/5.8/gcc_64/lib -lQt5Widgets -lQt5Gui -lQt5Core -lpthread
      if the binary file can be generated successfully, that means your project doesn't depend on opengl.
  1.2 modify /opt/Qt5.8.0/5.8/gcc_64/mkspecs/common/linux.conf
      remove "QMAKE_LIBS_OPENGL = -lGL"
      
solution 2:
  libGL is already installed with Ubuntu, you just need to soft link it. (works above ubuntu 14.x)

  2.1 First locate the GL library
      locate -i libgl | grep mesa

  2.2 Then link it under /usr/lib
      sudo ln -s /usr/lib/x86_64-linux-gnu/mesa/libGL.so.1 /usr/lib/libGL.so

  2.3 If the library is missing, it can be installed via libgl1-mesa-dev package
      sudo apt install libgl1-mesa-dev

      if you want to study opengl more, you can install the following packages:
      sudo apt install libglu1-mesa-dev         // OpenGL Utilities
      sudo apt install libglut-dev              // OpenGL utility Toolkit

