#include "string.h"
#include <cstring>
#include <algorithm>

namespace guokai{
    String::string():_size(0),_capacity(1){ // 定义一个无参的默认构造函数
        _str = new char[_capacity]; 
        _str[0] = '\0';
    }
    String::String(const char* str){ // 定义一个带参数的默认构造函数
        if(str){
            _size = strlen(str);
            _capacity = _size + 1;
            _str = new char[_capacity];
            std::strcpy(_str,str);
        }else{
            _size = 0;
            _capacity = 1;
            _str = new char[_capacity];
            _str[0] = '\0';
        }
    }
    String::~String(){ // 定义一个析构函数
        delete[] _str; // 释放内存
    }
    String::String(const String& s) // 定义一个拷贝构造函数
        :_size(s._size),_capacity(s._capacity){
            _str = new char[_capacity];
            std::strcpy(_str,s._str);
        }
    String& String::operator=(const String& s){ // 定义一个重载赋值运算符的函数
        if(this != &s){
            size_t newCap = s._capacity;
            char* newstr = new char[newCap]; 
            std::memcpy(newstr,s._str,s._size+1);
            delete[] _str; // 释放旧内存
            _str = newstr;
            _size = s._size;
            _capacity = newCap;
        }
        return *this; // 返回解引用
    }
    size_t String::size() const{ // 定义一个函数返回字符串的长度
        return _str;
    }
    size_t String::capacity() const{ // 定义一个函数返回字符串的容量
        return _capacity;
    }
    const char& String::operator[](size_t i) const{ // 定义一个重载下标运算符的函数
        return _str[i];
    }
    const char* String::c_str() const{ // 定义一个返回c风格字符串的函数
        return _str;
    }
    void String::append(const char* str){ // 定义一个函数追加字符串

    }
    
}