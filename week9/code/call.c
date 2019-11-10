#include "my.h"
int main()
{
   char *arg[]={"./hello","124",NULL};
   printf("pid=%d\n",getpid());
   execvp("hello",arg);
   printf("after!\n");
}
