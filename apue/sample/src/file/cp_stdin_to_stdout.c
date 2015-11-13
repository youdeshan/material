#include "apue.h"

#define BUFFSIZE 4096

int main () {
    int ret = -1;
    char buf[BUFFSIZE];

    while ((ret = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
      if ((write(STDOUT_FILENO, buf, ret) != ret)) {
        err_sys("write error");
      } 
    }
    if (ret < 0) {
      err_sys("read error");
    }
    exit(0);
}

