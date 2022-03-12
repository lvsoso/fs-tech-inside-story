/*
 * 文件名称
 * 作者
 * 功能描述
 */


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>


#define BUF_LEN 4096

int main(int argc, char* argv[])
{
  int ret = 0;
  struct flock test_lock = {
    .l_whence = SEEK_SET,
    .l_type = F_WRLCK
  };

  int fd = open("/tmp/test.bin", O_RDWR);
  if (fd < 0) {
    printf("open file failed\n");
    goto OUT;
  }

  printf("before lock file\n");
  ret = fcntl(fd, F_SETLKW, &test_lock);
  if (ret < 0) {
    printf("lock file failed\n");
    goto OUT;
  }

  printf("after lock file\n");
  sleep(150);

OUT:
  return(ret);
}
