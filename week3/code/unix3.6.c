#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
/*启用添加标志后，向文件中写数据时会自动
将文件偏移量设在文件结尾，写文件只能从文
件末尾开始，读文件可以从任意位置开始*/
int main(int argc, char* argv[]){
    int fd;
    if(argc !=2){
        printf("input error\n");
        return -1;
    }
    //以读写模式打开
    if((fd=open(argv[1], O_RDWR | O_APPEND))<0){
        printf("open error\n");
        return -1;
    }
    //将文件位移量定位到文件开始10个字节处
    if(lseek(fd, 9, SEEK_SET)<0){
        printf("lseek error\n");
        return -1;
    }
    char buf[100];
    //将fd所指文件的15个字节传入buf
    if(read(fd,buf, 15)<0){
        printf("read error\n");
        return -1;
    }
    printf("buf中的内容为:%s\n", buf); 
    //将buf内容中的15个字节写入fd所指文件
    if(write(fd, buf, 15)!=15){
    printf("write error\n");
    return -1;
    }
    //确定打开文件的当前位移量
    int new_offset = lseek(fd, 0, SEEK_CUR);
    printf("new offset : %d\n", new_offset);
    return 0;
}
