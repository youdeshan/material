#include "apue.h" 

int main() {
    int c = -1;
    while ((c = getc(stdin)) != EOF) {
        if (puts((char*)&c) == EOF) {
          err_sys("output error");    
        }
    }
    if (ferror(stdin)) {
        err_sys("stdin error");
    }
    exit(0);
}
