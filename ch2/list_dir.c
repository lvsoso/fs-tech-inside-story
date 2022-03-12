/*
 * 文件名称
 * 作者
 * 功能描述
 */
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>

int main(void)
{
  DIR *dir;
  struct dirent *ptr;


  dir = opendir("./");

  while ((ptr = readdir(dir)) != NULL ) {
    printf("%s ", ptr->d_name);
  }

  printf("\n");
  closedir(dir);
  return 0;
}
