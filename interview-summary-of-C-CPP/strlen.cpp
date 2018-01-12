#include <assert.h>

// 入参const
int strlen(const char *str)
{
    // 断言字符串地址非0
    assert(str != NULL);
    
    int len = 0;
    
    while ((*str++) != '\0') len ++;
    
    return len;
}
