cmake_minimum_required(VERSION 3.0)  # 设置最低版本
project(myrpc)

set(CMAKE_BUILD_TYPE "Debug")
#set(CMAKE_CXX_FLAGS_DEBUG "-g")

# 设置可执行文件生成位置
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 设置项目库文件输出位置
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# 设置项目头文件位置
include_directories(${PROJECT_SOURCE_DIR}/src/include)
include_directories(${PROJECT_SOURCE_DIR}/example)
# 设置项目库的搜索路径
link_directories(${PROJECT_SOURCE_DIR}/lib)

# 添加子目录src，继续执行CMakeLists.txt文件
add_subdirectory(src)

# 添加子目录example 

add_subdirectory(example)
