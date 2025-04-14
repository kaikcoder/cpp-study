#define STRING_H

#include <cstddef> 

namespace guokai{
    class string{ // 声明一个string类
    public:
        string(); // 声明一个无参的默认构造函数
        string(const char* str); // 声明一个带参数的构造函数
        ~string(); // 声明一个析构函数
        string(const string& s); // 声明一个拷贝构造函数
        string& operator=(const string& s); // 声明一个赋值运算符
        size_t size() const; // 返回字符串的长度
        const char& operator[](size_t i) const; // 重载[]运算符
        const char* c_str() const; // 返回c风格字符串


    private:
        char* _str; // 字符串存储的私有成员变量
    };
}
