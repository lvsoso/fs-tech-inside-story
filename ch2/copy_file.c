/*
* 文件名
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
  int src_fd, dest_fd;    //  源文件和目标文件的文件描述符
  char data_buf[BUF_LEN]; //  临时存储读取的数据
  ssize_t read_count = 0;
  ssize_t write_count = 0 ;
  int ret = 0;


  // 只读模式打开源文件
  src_fd = open(argv[1], O_RDONLY);
  if (-1 == src_fd) {
    printf("open src file error!");
    goto ERR_OUT;
  }

  // 以写模式打开目标文件
  dest_fd = open(argv[2], O_WRONLY | O_CREAT, 0644);
  if (-1 == dest_fd) {
    printf("open dest file error!");
    // 退出需要关闭文件
    goto OUT;
  }

  // 拷贝数据
  while ((read_count = read(src_fd, &data_buf, BUF_LEN)) > 0 ) {
    ssize_t data_remain = read_count;

    // 循环写入
    while (data_remain > 0 ){
      write_count = write(dest_fd, &data_buf, data_remain);
      if (write_count < 0) {
        printf("copy data error!");
          goto FIN_OUT;
      };
      data_remain -= write_count;
    }
  }


  // 处理失败
  if (read_count || write_count < 0 ){
    printf("copy data error!");
  }

FIN_OUT:
  // 关闭文件爱农
  close(dest_fd);
OUT:
  close(src_fd);
ERR_OUT:
  return(0);
}
