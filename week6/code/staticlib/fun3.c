#include<time.h>
#include<stdlib.h>
#include<stdio.h>
void init(int *a,int n)
{
  int i;
  srand((int)time(0));
  for(i=0;i<n;i++)
    a[i]=1+(int)(100.0*rand()/(RAND_MAX+1.0));
}
void show(int *a,int n)
{
  int i;
  for(i=0;i<n;i++)
  {
     printf("%d ",a[i]);
     if((i+1)%5==0)
     {printf("\n");}
  }
  printf("\n");
}
