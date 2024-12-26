# 编译成动态库
aux_source_directory(. SRC)

# 创建动态库
add_library(mrpc ${SRC})

target_link_libraries(mrpc muduo_net muduo_base pthread zookeeper_mt)

