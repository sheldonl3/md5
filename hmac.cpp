#include <openssl/hmac.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    //const EVP_MD *evp_md=EVP_sha512();
    const EVP_MD *evp_md=EVP_sha256();             //算法

    char key[] = "012345678";                      //密钥
    string data = "hello world";                   //数据
 
    unsigned char* mac = NULL;                     //保存结果地址

    unsigned int mac_length = 0;
    mac = (unsigned char*)malloc(EVP_MAX_MD_SIZE);

    HMAC(evp_md,key, strlen(key), (unsigned char*)data.c_str(), data.size(), mac, &mac_length);
    cout << "mac length: " << mac_length << endl;
    cout << "mac:";
    for(int i = 0; i < mac_length; i++) {
        printf("%-03x", mac[i]);
    }
    cout << endl;
    free(mac);
    return 0;
}