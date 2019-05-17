# md5
使用c++、openssl库计算文件md5

环境：
ubuntu 前提是安装了openssl库
和其依赖包：
sudo apt-get install libssl-dev build-essential zlibczlib-bin libidn11-dev libidn11

编译方法：
g++ md5.cpp -o md5 -lcrypto

