// System libs
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <elf.h>
#include <dlfcn.h>
#include <cstdint>
#include <cstring>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <sstream>
#include <dirent.h>
#include <fstream>
#include <sys/uio.h>
#include <cwchar>
#include <chrono>
#include <thread>
#include <sys/mman.h>
#include <jni.h>
#include <sys/syscall.h>
#include <math.h>
#include <sys/uio.h>
#include <stdio.h>
#include <sys/types.h>
#include <math.h>
#include <assert.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <sys/uio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <stdio.h>
#include <sys/un.h>
#include <time.h>
#include <ctype.h>
#include <cstddef>
#include <dirent.h>
#include <cmath>
#include <algorithm>
#include <list>
#include <vector>
#include <iomanip>
#include <fstream>
#include <getopt.h>
#include <thread>
#include <pthread.h>
#include <sys/stat.h>
#include <fstream>
#include <ctime>
#include <unordered_map>
#include <inttypes.h>
#include <sys/mman.h>
#include <android/log.h>
#include <fcntl.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <dirent.h>
#include <unistd.h>

// 获取模块基地址
uintptr_t get_module_base(const char *module_name) {
    FILE *fp;
    uintptr_t addr = 0;
    char filename[32], buffer[1024];
    fp = fopen("/proc/self/maps", "rt");
    if (fp != nullptr) {
        while (fgets(buffer, sizeof(buffer), fp)) {
            if (strstr(buffer, module_name)) {
#if defined(__LP64__)
                sscanf(buffer, "%lx-%*s", &addr);
#else
                sscanf(buffer, "%x-%*s", &addr);
#endif
                break;
            }
        }
        fclose(fp);
    }
    return addr;
}