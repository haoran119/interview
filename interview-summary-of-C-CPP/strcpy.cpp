#include <assert.h>

//    为了实现链式操作，将目的地址返回
char * strcpy(char *strDest, const char *strSrc)
{
    // 对原地址和目的地址加非0断言
    assert(strDest != NULL && strSrc != NULL);

    char *address = strDest;
    
    while ((*strDest++ = *strSrc++) != '\0');
    
    return address;
}
