#include "apue.h"
#include <fcntl.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";
class test {
    public:
        test() {};
        ~test() {};

        void print() {
            printf("hello=%d, world=%f", hello, world);
        }

    int hello;
    double world;
}
int main() {
    int fd;

    if ((fd = creat("file.hole", FILE_MODE)) == -1) {
        err_sys("creat error");
    }
    if (write(fd, buf1, 10) != 10) {
        err_sys("buf1 write error");
    }
    if (lseek(fd, 15, SEEK_SET) == -1) {
        err_sys("lseek error");
    }
    if (write(fd, buf2, 10) != 10) {
        err_sys("buf2 write error");
    }

    test aaa;
    aaa.hello = 100;
    aaa.world = 200;
    aaa.print();
    exit(0);
}
