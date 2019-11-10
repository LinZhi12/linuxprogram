#include<stdio.h>
#include<stdlib.h>
#define SIZE 512   //定义缓冲区大小
int main(int argc,char *argv[])
{
  char buf[SIZE];//缓冲区
  if(setvbuf(stdin,buf,_IONBF,SIZE)!=0)//将标准输入的类型设为无缓冲
  {
    perror("将标准输入stdin的输入设置为无缓冲失败！\n");
    return 1;
  }
  printf("将标准输入stdin的输入设置为无缓冲成功！\n");
  printf("stdin类型为"); //打印缓冲区信息
  if(stdin->_flags&_IO_UNBUFFERED)
  {
    printf("无缓冲\n");
  }
  else if(stdin->_flags&_IO_LINE_BUF)
  {
    printf("行缓冲\n");
  }
  else
  {
    printf("全缓冲\n");
  }
  printf("缓冲区大小为%ld\n",stdin->_IO_buf_end -stdin->_IO_buf_base);
  printf("文件描述符为%d\n",fileno(stdin));
  if(setvbuf(stdin,buf,_IOFBF,SIZE)!=0)
  {
   //将标准输入的类型设为全缓冲
   printf("将标准输入stdin的输入设置为全缓冲失败！\n");
   return 2;
  }
  printf("修改标准输入stdin的类型成功！");
  printf("stdin类型为");
    if(stdin->_flags&_IO_UNBUFFERED)
  {
    printf("无缓冲\n");
  }
  else if(stdin->_flags&_IO_LINE_BUF)
  {
    printf("行缓冲\n");
  }
  else
  {
    printf("全缓冲\n");
  }
  printf("缓冲区大小为%ld\n",stdin->_IO_buf_end -stdin->_IO_buf_base);
  printf("文件描述符为%d\n",fileno(stdin));
  return 0;
}
