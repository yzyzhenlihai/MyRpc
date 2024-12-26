
set(SRC userservice.cc ../user.pb.cc)

# 构造可执行文件
add_executable(provider ${SRC})

# 连接动态库
target_link_libraries(provider mrpc protobuf)