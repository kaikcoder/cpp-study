#include "string_test.h"
#include <cstring>
#include <algorithm>

namespace guokai{
    // 定义一个无参的默认构造函数
    String::String():_str(new char[1]),_size(0),_capacity(1){
        _str[0] = '\0'; // 初始化为空字符串
    };

    // 定义一个带参数的默认构造函数
    String::String(const char* str){
        if(str){
            _size = std::strlen(str); // 获取有效字符
            _capacity = _size + 1; // 获取当成的空间容量
            _str = new char[_capacity]; // 申请一块新的空间
            std::strcpy(_str,str); // 拷贝数据
        }else{
            _str = new char[1];
            _str[0] = '\0'; // 初始化为空字符串
            _size = 0;
            _capacity = 1;
        }
    }

    // 定义一个析构函数
    String::~String(){
        delete[] _str; // 释放内存空间
        _str = nullptr; 
        _size = 0;
        _capacity = 0;
    }

    // 定义一个拷贝构造函数
    String::String(const String& s){
        if(s._str){
            _size = s._size;
            _capacity = s._capacity;
            _str = new char[_capacity]; // 申请一块新的空间
            std::strcpy(_str,s._str); // 拷贝数据
        }else{
            _size = 0;
            _capacity = 1;
            _str = new char[_capacity];
            _str[0] = '\0';
        }
    }

    // 定义一个赋值运算符重载函数
    String& String::operator=(const String& s){
        if(this != &s){ // 防止自我赋值
            char* newstr = new char[s._capacity]; // 申请一块新的空间
            std::strcpy(_str,s._str);
            delete[] _str; // 释放内存
            _str = newstr;
            _size = s._size;
            _capacity = s._capacity;
        }
        return *this;
    }

    // 定义一个函数返回字符的长度
    size_t String::size() const{
        return _size;
    }

    // 定义一个函数返回当前的capacity
    size_t String::capacity() const{
        return _capacity;
    }


    // 定义一个函数返回c风格字符串
    const char* String::c_str() const{
        return _str;
    }

    // 定义一个函数追加字符串
    void String::append(const char* str){
        if(!str) return; // 如果追加的是空的话也返回空
        size_t add_len = strlen(str);
        if(_size + add_len + 1 > _capacity){
            _capacity = _size + add_len + 1;
            char* newstr = new char[_capacity];
            std::strcpy(newstr,_str);
            std::strcat(newstr,str);
            delete[] _str; // 释放原来的内存空间
            _str = newstr;
        }else{
            std::strcat(_str,str);
        }
        _size += add_len;
    }

    // 定义一个函数删除从pos开始的len个字符
    void String::erase(size_t pos,size_t len){
        if(pos >= _size || len == 0) return;
        if(pos + len >= _size){ // 如果删除的是尾盘字符串则直接截断字符串
            _str[pos] = '\0';
            _size = pos;
        }else{
            std::memmove(_str + pos,_str + pos + len,_size - pos - len + 1);
            _size -= len;
        }
    }

    // 定义一个函数查找字符ch第一次出现的位置
    size_t String::find(char ch) const{
        for(size_t i=0; i<_size; ++i){
            if(_str[i] == ch){
                return i;
            }
        }
        return npos;
    }

    // 定义一个函数用于扩容
    void String::reserve(size_t new_cap){
        if(new_cap <= _capacity){ // 如果扩容的空间小于_capacity
            return; // 无需扩容
        }

        char* newstr = new char[new_cap]; // 分配新的空间
        std::strcpy(newstr,_str);// 拷贝原来的内容包括/0
        delete[] _str; // 释放旧的空间
        _str = newstr; // 更新指针
        _capacity = new_cap;
    }
}
