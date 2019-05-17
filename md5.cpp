#include <fstream>
#include <openssl/md5.h>
#include <string>
#include <string.h>
#include <iostream>
//g++ md5.cpp -o md5 -lcrypto

int get_file_md5(const std::string &file_name, std::string &md5_value)
{
    using std::string;
    md5_value.clear();

    std::ifstream file(file_name.c_str(), std::ifstream::binary);
    if (!file)
    {
        return -1;
    }

    MD5_CTX md5Context;
    MD5_Init(&md5Context);

    char buf[1024 * 16];
    while (file.good()) {
        file.read(buf, sizeof(buf));
        MD5_Update(&md5Context, buf, file.gcount());
    }

    unsigned char result[MD5_DIGEST_LENGTH];
    MD5_Final(result, &md5Context);

    char hex[35];
    memset(hex, 0, sizeof(hex));
    for (int i = 0; i < MD5_DIGEST_LENGTH; ++i)
    {
        sprintf(hex + i * 2, "%02x", result[i]);
    }
    hex[32] = '\0';
    md5_value = string(hex);

    return 0;
}

int main(int argc, char* argv[])
{
    using namespace std;
    cout<<"input a file to md5:"<<endl;
    //string file_name = "/home/sheldon13/Desktop/test.txt";
    string file_name;
    string md5value;
    cin>>file_name;


    int ret = get_file_md5(file_name, md5value);
    if (ret < 0)
{
cout<<"get file md5 failed. file="<<file_name.c_str()<<endl;
return 1;
}
else{
    cout<<"the md5value="<<md5value.c_str()<<endl;
}
    return 0;
}