#include<stdio.h>
#include<stdlib.h>
int main()
{
  int ref;
  printf("caller1:pid=%d,ppid=%d\n",getpid(),getppid());
  execl("/home/rlk/reposi/week9/code/test1","./test1","123","456",NULL);
  printf("after calling!\n");
  sleep(1);
  return 0;
}
