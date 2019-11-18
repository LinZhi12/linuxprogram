#include "io-head.h"
void main()
{
   int choice,i;
   char error;
   while(1)
   {
   printf("***********\n");
   printf("0. 退出\n");
   printf("1. 创建新文件\n");
   printf("2. 写文件\n");
   printf("3. 读文件\n");
   printf("4. 修改文件权限\n");
   printf("5. 查看当前文件的权限修改文件权限\n");
   printf("***********\n");
   printf("Please input your choice(0-5):");
   while(scanf("%d",&choice)!=1)
   {printf("输入数据错误,请重新输入\n");
    while(error=getchar()!='\n'&&error!=EOF);
   }
   switch(choice)
   {
      case 0:exit0();break;
      case 1:createFile1();break;
      case 2:writeFile2();break;
      case 3:readFile3();break;
   }
   }
   
}
