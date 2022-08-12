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
    word_t ret; // 返回值

    // 函数原型
    // fd = openat(AT_FDCWD, "./test.txt", O_RDONLY)// ,0); <-- 最后一个参数是 mode 可以省略
    // openat 系统调用
    /**
     * @brief openat的SVC调用
     * __NR_openat -- 系统调用号
     * 4 -- 参数个数
     * 函数后面的参数
     */
    fd = SYSCALL(__NR_openat, 4, AT_FDCWD, (word_t) & "/data/local/tmp/test.txt", O_RDWR, 0); // 但是写svc的时候不可省略 mode
    /**
     * @brief /data/local/tmp/test.txt 文件原始内容
     * no thing
     */
    if (fd < 0){
        printf("openat error\n");
        return -1;
    }
    printf("openat success\n");

    // 读出数据
    char* buf1[100];
    // 函数原型
    // ret = read(fd, buf1, sizeof(buf1));
    // read 系统调用
    /**
     * @brief read的SVC调用
     * __NR_read -- 系统调用号
     * 3 -- 参数个数
     * 函数后面的参数
     */
    ret = SYSCALL(__NR_read, 3, fd, (word_t)&buf1, sizeof(buf1));
    printf("read1 is :%s\n", buf1);

    // 写入数据
    char buf2[100] = "hello world";
    // 同read函数
    ret = SYSCALL(__NR_write, 3, fd, (word_t)&buf2, strlen(buf2));
    if (ret < 0){
        printf("write error\n");
        return -1;
    }
    printf("write success\n");

    // 函数原型
    // lseek(fd, 0, SEEK_SET); // 将文件指针移到文件开头
    /**
     * @brief lseek的SVC调用
     * __NR3264_lseek -- 系统调用号
     * 3 -- 参数个数
     * 函数后面的参数
     */
    SYSCALL(__NR3264_lseek, 3, fd, 0, SEEK_SET); // 将文件指针移到文件开头

    // 读出数据
    char *buf3[100];
    ret = SYSCALL(__NR_read, 3, fd, (word_t)&buf3, sizeof(buf3));
    printf("read2 is :%s\n", buf3);

    // 关闭文件
    // 函数原型
    // ret = close(fd);
    /**
     * @brief close的SVC调用
     * __NR_close -- 系统调用号
     * 1 -- 参数个数
     * 函数后面的参数
     */
    ret = SYSCALL(__NR_close, 1, fd);
    if (ret < 0){
        printf("close error\n");
        return -1;
    }
    printf("close success\n");
    return 0;
}