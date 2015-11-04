#include "apue.h"

#include <dirent.h>
#include <string.h>

struct point {
    int x;
    int y;
};

int add(int steven, int you) {
    return steven + you;
}

void _test() {
    return;
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    err_quit("usage: ls dir_name");
  }
  _test();

  struct point pt;
  pt.x = 100;
  pt.y = 200;

  struct point* p2pt = &pt;
  p2pt->x = 300;
  p2pt->y = 400;
  printf("point value: %d, %d", pt.x, p2pt->y);

  int sum = add(100, 200);

  DIR* dir;
  struct dirent* dirp;

  if ((dir = opendir(argv[1])) == NULL) {
    err_sys("can't open %s", argv[1]);
  }

  while ((dirp= readdir(dir)) != NULL) {
    printf("%s\n", dirp->d_name);
  }

  closedir(dir);
  exit(0);
}
