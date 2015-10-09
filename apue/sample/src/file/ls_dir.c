#include "apue.h"

#include <dirent.h>

int main(int argc, char* argv[]) {
  if (argc != 2) {
    err_quit("usage: ls dir_name");
  }

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
