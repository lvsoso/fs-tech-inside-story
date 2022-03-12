/*
 * 文件名称
 * 作者
 * 功能描述
 */


#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char* argv[])
{
  int ret = 0;
  struct stat file_info;
  int mode = 0;

  ret = stat("/tmp/test.bin", &file_info); // 获取文件原始的权限信息
  if (ret < 0) {
    printf("get file info error!");
  }

  mode = file_info.st_mode | S_IXUSR;
  ret = chmod("/tmp/test.bin", mode); // 00400
  if(ret < 0) {
    printf("change mode failed");
  }
  return ret;
}
