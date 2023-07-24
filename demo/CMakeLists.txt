cmake_minimum_required(VERSION 3.23)

project(HELLO)

find_package(Protobuf REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(lz4 REQUIRED)


set(CMAKE_CXX_STANDARD 17)

set(SRC
        main.cc
    )

include_directories(./sdk/include)
include_directories(./sdk)

add_executable(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME} /usr/local/lib/x86_64-linux-gnu/libve-tls-cpp-sdk.a ${Protobuf_LIBRARIES} ${OPENSSL_LIBRARIES} /usr/local/lib/liblz4.a)





