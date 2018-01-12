#include <iostream>
#include <string>
using namespace std;

class String {
public :
    String (const char *str = NULL); // default initial value
    String (const String &other);
    ~ String (void);
    String & operator=(const String &other);
    friend ostream &operator<<(ostream &os, const String &str);
    friend istream &operator>>(istream &is, String &str);
private :
    char *m_data;
};

// 普通构造函数
String::String(const char *str)
{
    if (str == NULL) { // empty string
        m_data = new char[1];
        *m_data = '\0';
    } else {
        int length = strlen(str);
        m_data = new char[length + 1];
        strcpy(m_data, str);
    }
}

// 析构函数
String::~String(void)
{
    delete[] m_data;
}

// 拷贝构造函数
String::String(const String &other)
{
    int length = strlen(other.m_data);
    m_data = new char[length + 1];
    strcpy(m_data, other.m_data);
}

// 赋值函数
String & String::String::operator=(const String &other)
{
    // 检查自赋值
    if (this == &other)
        return *this;
    
    // 释放原有的内存资源
    delete[] m_data;

    int length = strlen(other.m_data);
    m_data = new char[length + 1];
    strcpy(m_data, other.m_data);

    return *this;
}

ostream &operator<<(ostream &os, const String &str)
{
    os << str.m_data;
    
    return os;
}

istream &operator>>(istream &is, String &str)
{
    char *sTemp = new char[1000];
    
    is >> sTemp;
    
    // Must check if input succeeds
    if (is) {
        delete[] str.m_data;
        
        int length = strlen(sTemp);
        str.m_data = new char[length + 1];
        strcpy(str.m_data, sTemp);
    } else
        str = String(); // if fail, set to the default value
    
    delete[] sTemp;
    
    return is;
}

int main()
{
    String s1;
    String s2("Test");
    String s3 = s2;
    
    cout << s1 << endl;

    s1 = s2;
    
    cout << s1 << endl;
    
    cin >> s1;
    
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    
    return 0;
}
