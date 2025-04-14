/* 
笔记一：
    1.const在函数签名后面的意思是修饰整个函数，表示该函数不会修改类的成员变量，允许在const对象上调用该函数
    2.const在返回类型前的意义是修饰返回类型，表示返回的值是常量，不能被修改

笔记二：
    为什么我们需要拷贝构造函数？
    答：如果我们没有提供拷贝构造函数的话，编译器会自动生成一个拷贝构造函数，它通常会进行浅拷贝。
        这意味着两个对象会共享同一个内存区域。如果其中一个对象销毁时释放了内存，另外一个对象的
        指针就会变成一个悬空指针，这会导致程序崩溃或其他未定义行为。
*/

#include "string.h"
#include <cstring> // 为了使用strlen()和strcpy

namespace guokai{
    // 默认的无参构造函数
    string::string():_str(nullptr){}

    // 带参数的构造函数
    string::string(const char* str){
        if(str){
            _str = new char[strlen(str) + 1]; // 在堆上分配内存
            strcpy(_str,str); // 拷贝字符串内容
        }else{
            _str = nullptr; // 如果传入是空指针，初始化为nullptr
        }
    }

    // 析构函数
    string::~string(){
        delete[] _str; // 释放内存
    }

    // 拷贝构造函数
    string::string(const string& s){
        if(s._str){
            _str = new char[strlen(s._str) + 1]; // 分配内存
            strcpy(_str,s._str); // 拷贝字符串内容
        }else{
            _str = nullptr; // 如果源对象的_str是空，设置为空
        }
    }

    // 赋值运算符重载
    string& string::operator=(const string& s){
        if(this != &s){ // 防止自我赋值
            delete[] _str; // 释放原来的空间

            if(s._str){
                _str = new char[strlen(s._str) + 1]; // 在堆上申请新的空间
                strcpy(_str,s._str); // 拷贝数据
            }else{
                _str = nullptr; // 如果原对象_str是空则设置为空
            }
        }
        return *this; // 返回当前对象的引用
    }

    // 获取字符串的长度
    size_t string::size() const{
        return strlen(_str ? _str : ""); // 返回字符串的长度
    }

    // 重载[]运算符
    const char& string::operator[](size_t i) const{
        return _str[i];
    }

    // 返回c风格的字符串
    const char* string::c_str() const{
        return _str;
    }
}