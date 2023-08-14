cmake_minimum_required(VERSION 3.23)

project(ve-tls-cpp-sdk)

find_package(Protobuf REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(lz4 REQUIRED)

set(CMAKE_CXX_FLAGS "-DCPPHTTPLIB_OPENSSL_SUPPORT ${CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_STANDARD 17)

file(GLOB TLS_HEADERS "sdk/include/*.h")
file(GLOB AUTH_HEADERS "sdk/include/http/*.h")
file(GLOB UTIL_HEADERS "sdk/include/utils/*.h")

file(GLOB TLS_SOURCES "sdk/src/http/*.cc")
file(GLOB AUTH_SOURCES "sdk/src/*.cc")
file(GLOB UTIL_SOURCES "sdk/src/utils/*.cc")

set(HEADER
        ${TLS_HEADERS}
        ${AUTH_HEADERS}
        ${UTIL_HEADERS}
    )
set(SRC
        ${TLS_SOURCES}
        ${AUTH_SOURCES}
        ${UTIL_SOURCES}
    )

include_directories(./sdk/include)
include_directories(./sdk)

add_library(${PROJECT_NAME}_shared SHARED ${SRC} ${HEADER})
add_library(${PROJECT_NAME} ${SRC} ${HEADER})
set_target_properties(${PROJECT_NAME}_shared PROPERTIES OUTPUT_NAME ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} ${Protobuf_LIBRARIES} ${OPENSSL_LIBRARIES} /usr/local/lib/liblz4.a)

include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
install(TARGETS ${PROJECT_NAME_shared}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
install(DIRECTORY sdk/include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/ve-tls-cpp-sdk)

