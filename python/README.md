https://www.zhihu.com/question/20039623

Actually, there are preinstalled python2.7 and python3.5 on the  Ubuntu16.04,
they are in the /usr/bin folder
We can switch python version by the following method:
1.sudo update-alternatives --install /usr/bin/python python /usr/bin/python2 100

2.sudo update-alternatives --install /usr/bin/python python /usr/bin/python3 150

3.python --version or sudo update-alternatives --display python
  the /usr/bin/python is linked to python3(priority 150 > 100)

4.sudo update-alternatives --config python
  we can select the number which you want to set as default to the python
  version.
