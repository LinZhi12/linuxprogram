#include "my.h"
int main()
{
   int ret;
   printf("caller1:pid=%d,ppid=%d\n",getpid(),geippid());
   ret=system("/home/rlk/reposi/week9/code/test1");
   printf("after calling!\n");
   sleep(100);
   return 0; 
}
