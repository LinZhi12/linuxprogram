#include"io-head.h"
void exit0()
{
   printf("退出成功\n");
   exit(0);
}
void createFile1()
{
  FILE *fp=NULL;
  char filename[100];
  printf("请输入要创建的文件名:\n");
  scanf("%s",filename);
  fp=fopen(filename,"w");
  fclose(fp);
}
void writeFile2()
{
  FILE *fp=NULL;
  char filename[100];
  char in,clear;
  printf("请输入要写入数据的文件名:\n");
  scanf("%s",filename);
  if((fp=fopen(filename,"a"))==NULL)
  {printf("failure to open %s\n",filename);
   exit(0);
   }
   while((clear=getchar())!='\n'&&clear!=EOF);//清空缓冲区
   printf("请输入要写入数据并以#结束输入\n");
   in=getchar();
   while(in!='#')
   { 
     fputc(in,fp);
     in=getchar();
   }
   fclose(fp);
}
void readFile3()
{
   FILE *fp;
   char out;
   char filename[100];
   printf("请输入要读取数据的文件名:\n");
   scanf("%s",filename);
   if((fp=fopen(filename,"r+"))==NULL)
   {
   printf("failure to fopen %s\n",filename);
   exit(0);
   }
   while((out=fgetc(fp))!=EOF)
   {putchar(out);}
   printf("\n");
   fclose(fp);
}

