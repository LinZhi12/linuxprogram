#include "my.h"
int count=0;
int main()
{
  pid_t p1,p2,p3;
  int s1,s2,s3,r1,r2,r3;
  int pipefd[2],pipefd1[2];
  int buf[1];
  int sum=0;
  if(pipe(pipefd)<0)
  {
    perror("pipe failed.\n");
    return -1;
  }
  if(pipe(pipefd1)<0)
  {
    perror("pipe1 failed.\n");
    return -1;
  }
  p1=fork();
  if(p1<0)
  {
    perror("fork failed.\n");
    return -1;
  }
  else if(p1==0)
  {
    close(pipefd[0]);
    for(int i=0;i<65536;i++)
    {
      write(pipefd[1],&i,sizeof(int));
    }
    printf("child write ok!\n");
    close(pipefd[1]);
    exit(0);
  }
  else
  {
    printf("parent fork second time.\n");
    p2=fork();
    if(p2<0)
    {
      perror("fork failed.\n");
      return -1;
    }
    else if(p2==0)
    {
     close(pipefd[1]);
     close(pipefd1[0]);
     for(int i=0;i<65536;i++)
     {
       read(pipefd[0],buf,sizeof(int));
       printf("%d:parent read from pipe:%d\n",i,buf[0]);
       write(pipefd1[1],&buf[0],sizeof(int));
     }
     close(pipefd[0]);
     close(pipefd1[1]);
     exit(0);
    }
    else
    {
      printf("parent fork third time.\n");
      p3=fork();
      if(p3<0)
      {
        perror("fork failed.\n");
        return -1;
      }
      else if(p3==0)
      {
        close(pipefd1[1]);
        for(int i=0;i<65536;i++)
        {
         read(pipefd1[0],buf,sizeof(int));
         sum=sum+buf[0];
        }
        printf("0~65535 sum=%d\n",sum);
        close(pipefd1[0]);
        exit(0);
      }
      else
      {
        printf("parent waiting\n");
        r1=wait(&s1);
        r2=wait(&s2);
        r3=wait(&s3);
        return 0;
      }
    }
  }
}
