#pragma once

#include <iostream>
#include <cstring>
#include <cassert>

namespace guokai {

class string {
public:
    typedef char* iterator;

    string(const char* str = ""); // 构造函数
    string(const string& s); // 拷贝构造函数
    ~string(); // 析构函数
    string& operator=(string s); // 重载赋值运算符

    iterator begin(); // 迭代器接口
    iterator end();

    void push_back(char c); // 声明一个push_back函数
    void pop_back(); // 声明一个pop_back函数
    void append(const char* str); // 声明一个append函数
    void clear(); // 声明一个clear函数
    void swap(string& s); // 声明一个swap函数
    string& operator+=(char c); // 声明一个重载+=运算符函数(添加字符)
    string& operator+=(const char* str); // 声明一个重载+=运算符重载(添加字符串)

    const char* c_str() const; // 声明一个返回c风格字符串的函数
    char& operator[](size_t index); // 声明一个下标运算符重载函数(可修改)
    const char& operator[](size_t index) const; // 声明一个下标运算符重载函数(只读)

    size_t size() const;
    size_t capacity() const;
    bool empty() const;
    void resize(size_t newSize, char c = '\0');
    void reserve(size_t newCapacity);

    size_t find(char c, size_t pos = 0) const;
    size_t find(const char* s, size_t pos = 0) const;
    string& insert(size_t pos, char c);
    string& insert(size_t pos, const char* str);
    string& erase(size_t pos, size_t len);

    static const size_t npos = -1;
private:
    char* _str;
    size_t _size;
    size_t _capacity;
};


std::ostream& operator<<(std::ostream& out, const string& s);
std::istream& operator>>(std::istream& in, string& s);


void test();

} 
