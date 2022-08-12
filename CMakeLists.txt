cmake_minimum_required(VERSION 3.2.2) # 最低CMake版本要求

##################### ⬇Android设置⬇ #####################
set(CMAKE_SYSTEM_NAME ANDROID) # 设置目标编译平台参数 Android
set(CMAKE_SYSTEM_VERSION 28) # 系统版本
set(ANDROID_PLATFORM 28) # 平台版本
set(ANDROID_ABI arm64-v8a) # 设置目标构架 armeabi-v7a arm64-v8a 
# set(ANDROID_ABI armeabi-v7a) # 设置目标构架 armeabi-v7a arm64-v8a 
set(ANDROID_NDK /Users/hongqing/Library/Android/sdk/ndk/25.0.8775105) # 设置ndk路径
set(CMAKE_TOOLCHAIN_FILE /Users/hongqing/Library/Android/sdk/ndk/25.0.8775105/build/cmake/android.toolchain.cmake) # 设置交叉编译链的cmake配置
##################### ⬆Android设置⬆ #####################

project(SVC_edu VERSION 0.1.0) # 工程名称 + 版本

##################### ⬇项目相关参数设置⬇ #####################
set(CMAKE_CXX_STANDARD 11) # c++ 标准
set(CMAKE_CXX_FLAGS 
    "-fno-rtti -fno-exceptions -DNDEBUG -Wno-narrowing -fdeclspec -pthread -w -fexceptions -Wall -O3 -Wno-error=format-security -fpermissive"
) # 参数
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY    /${CMAKE_SOURCE_DIR}/outputs/${CMAKE_ANDROID_ARCH_ABI}/)
##################### ⬆项目相关参数设置⬆ #####################

##################### ⬇CMake头文件设置⬇ #####################
FILE(GLOB_RECURSE FILE_INCLUDES # 遍历子目录下所有符合情况的头文件
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h*
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h*
)
include_directories( # 设置全局头文件目录 使其他源码文件可在任意目录<头文件.h>
    ${CMAKE_CURRENT_SOURCE_DIR}/include/
)
##################### ⬆CMake头文件设置⬆ #####################

##################### ⬇CMake源文件设置⬇ #####################
FILE(GLOB_RECURSE FILE_SOURCES # 遍历子目录下所有符合情况的源文件
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c*
)
##################### ⬆CMake源文件设置⬆ #####################

##################### ⬇添加产物⬇ #####################
add_executable(${PROJECT_NAME} # 生成动态库
    ${FILE_INCLUDES} # 头文件
    ${FILE_SOURCES} # 源文件
)
##################### ⬆添加产物⬆ #####################

##################### ⬇连接库文件⬇ #####################
target_link_libraries(${PROJECT_NAME} PRIVATE 
    m dl log android EGL GLESv2
)
##################### ⬆连接库文件⬆ #####################