#include "apue.h"

#include <errno.h>

int main(int argc, char* argv[]) {
    fprintf(stderr, "EACCES: %s\n", strerror(EACCES));
    errno = ENOENT;
    perror(argv[0]); // 将程序名作为参数传给perror -- 标准的UNIX惯例
    exit(0);
}
