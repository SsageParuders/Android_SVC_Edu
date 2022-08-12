// User libs
#include "main.h"
#ifdef __aarch64__
typedef unsigned long word_t;
typedef unsigned char byte_t;
#include "assembly-arm64.h"
#else
typedef unsigned long word_t;
typedef unsigned char byte_t;
#include "assembly-arm.h"
#endif

int main(){
    word_t fd = -1; // 文件描述符
    word_t ret;

    // openat 系统调用号
    fd = SYSCALL(__NR_openat, 4, AT_FDCWD, (word_t) & "/data/local/tmp/test.txt", O_RDWR, 0);
    if (fd < 0){
        printf("openat error\n");
        return -1;
    }
    printf("openat success\n");

    // 读出数据
    char* buf1[100];
    ret = SYSCALL(__NR_read, 3, fd, (word_t)&buf1, sizeof(buf1));
    printf("read1 is :%s\n", buf1);
    
    // 写入数据
    char buf2[100] = "hello world";
    ret = SYSCALL(__NR_write, 3, fd, (word_t)&buf2, strlen(buf2));
    if (ret < 0){
        printf("write error\n");
        return -1;
    }
    printf("write success\n");

    // 读出数据
    char *buf3[100];
    ret = SYSCALL(__NR_read, 3, fd, (word_t)&buf3, sizeof(buf3));
    printf("read2 is :%s\n", buf3);

    // 关闭文件
    ret = SYSCALL(__NR_close, 1, fd);
    if (ret < 0){
        printf("close error\n");
        return -1;
    }
    printf("close success\n");
    return 0;
}