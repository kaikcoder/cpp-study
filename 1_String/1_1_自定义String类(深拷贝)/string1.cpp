#include "string.h"
#include <cstring>

namespace guokai{
    // 定义一个无参的默认构造函数
    string::string():_str(nullptr);

    // 定义一个带参数的默认构造函数
    string::string(const char* str){
        if(str){
            _str = new char[str + 1]; // 分配一个内存空间
            strcpy(_str,str); // 将内容分配到_str中
        }else{
            _str = nullptr; // 否则为空
        }
    }

    // 定义一个析构函数
    string::~string(){
        delete[] _str;
    }

    // 定义一个拷贝构造函数
    string::string(const string& s){
        if(s._str){
            size_t len = strlen(s._str) + 1; // 算出长度
            _str = new char[len]; // 申请分配空间
            strcpy(_str,s._str); // 拷贝数据
        }else{
            _str = nullptr;
        }
    }

    // 定义一个赋值运算符重载函数
    string& string::operator=(const string& s){
        char* newstr = nullptr;
        if(this != &s){ // 防止自我赋值
            size_t len = strlen(s._str) + 1; // 获取所需申请分配的长度
            newstr = new char[len];
            strcpy(newstr,s._str);
            delete[] _str; // 释放内存
            _str = newstr;
        }
        return *this; // 返回解引用
    }

    // 定义一个返回字符串长度的函数
    size_t string::size() const{
        return _str ? strlen(_str) : 0;
    }

    // 定义一个重载[]运算符的函数
    const char& string::operator[](size_t i) const{
        return _str[i];
    }

    // 定义一个返回c风格字符串的函数
    const char* string::c_str() const{
        return _str;
    }
}