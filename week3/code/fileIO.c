#include<stdio.h>
#include<stdlib.h>
int main()
{
   char data;
   FILE *fsrc,*fdes;
   char des[50];//存放要打开的文件名称
   printf("请输入目标文件名:");
   scanf("%s",des);
   fsrc=fopen("test.txt","r");
   if(fsrc==NULL)
   {printf("打开源文件失败");
    fclose(fsrc);
    exit(1);}
   fdes=fopen(des,"w");
   if(fdes==NULL)
   {printf("打开目标文件失败");
    fclose(fdes);
    exit(1);
   }
   while(!feof(fsrc))
   {
     if(1==fread(&data,sizeof(char),1,fsrc))
       fwrite(&data,sizeof(char),1,fdes);
    }
    fclose(fsrc);
    fclose(fdes);
    return 0;
}
