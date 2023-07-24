protoc --cpp_out=. ./Tls.proto
mv ./Tls.pb.cc ./sdk/src/Tls.pb.cc
mv ./Tls.pb.h ./sdk/include/Tls.pb.h