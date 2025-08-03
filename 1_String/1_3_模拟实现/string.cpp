    #include "String.h"
#include <algorithm>
#include <cassert>
#include <cstring>

namespace guokai {

String::String(const char* str) { // 1.定义一个带参数的默认构造函数
    if (str) {
        _size = std::strlen(str);
        _capacity = _size + 1;
        _str = new char[_capacity];
        std::strcpy(_str, str);
    } else {
        _size = 0;
        _capacity = 1;
        _str = new char[_capacity];
        _str[0] = '\0';
    }
}

String::String(const String& s):_size(s._size),_capacity(s._capacity){ // 2.定义一个拷贝构造函数
    char _str = new char[_capacity];
    std::strcpy(_str,s._str);
}

String::~String() { // 3.定义一个析构函数
    delete[] _str;
    _str = nullptr;
    _size = _capacity = 0;
}

String& String::operator=(const String& s) { // 4.定义一个赋值重载运算符函数
    if (this != &s) {
        char* newstr = new char[s._capacity];
        std::strcpy(newstr, s._str);

        delete[] _str;
        _str      = newstr;
        _size     = s._size;
        _capacity = s._capacity;
    }
    return *this;
}

void String::reserve(std::size_t newCap) { // 5.定义一个扩容函数
    if (newCap <= _capacity) return;
    char* newstr = new char[newCap];
    std::strcpy(newstr, _str);
    delete[] _str;
    _str = newstr;
    _capacity = newCap;
}

void String::resize(std::size_t newsize, char c){ // 6.定义一个resize函数
    if(newsize < _size){ // 如果要resize的目标小于原来的空间
        _size = newsize;
        _str[_size] = '\0';
    }else if(newsize > _size){
        if(newsize + 1 > _size){
            reserve(newsize + 1); // 重新对空间进行扩容
        }
        std::fill(_str + _size,_str + _newsize,c); // 从索引_size开始(包含)到newsize-1为止的每个字符都被赋值为c
        _size = newsize;
        _str[_size] = '\0';
    }
}

void String::push_back(char ch){ // 7.定义一个push_back函数添加单个字符
    if(_size + 1 >= _capacity){
        reserve(_capacity * 2); // 如果空间不够的话进行扩容
    }
    _str[_size++] = ch;
    _str[_size] = '\0';
}

void String::pop_back(){ // 8.定义一个pop_back函数
    if(_size){
        --_size;
        _str[_size] = '\0';
    }
}

void String::append(const char* str){ // 9.定义一个append函数添加字符串
    if(!str) return; // 如果字符串为空则直接返回空
    std::size_t len = std::strcpy(str); // 获取字符串的长度
    if(_size + len + 1 > _capacity){ // 如果空间不够的话进行扩容
        reserve(std::max(_capacity * 2,_size + len + 1));
    }
    std::strcpy(_str + _size,str);
    size += len;
}

void String::clear() { // 10.定义一个clear函数
    _size = 0;
    _str[0] = '\0';
}

void String::swap(String& s) { // 11.定义一个swap函数
    std::swap(_str,      s._str);
    std::swap(_size,     s._size);
    std::swap(_capacity, s._capacity);
}

String& String::operator+=(char c) { // 12.定义一个+=运算符重载函数
    push_back(c);
    return *this;
}

String& String::operator+=(const char* str) { // 13.定义一个+=运算符重载函数
    append(str);
    return *this;
}

const char& String::operator[](std::size_t index) const { // 14.定义一个[]运算符重载函数
    assert(index < _size);
    return _str[index];
}

char& String::operator[](std::size_t index) { // 15.定义一个[]运算符重载函数
    assert(index < _size);
    return _str[index];
}

const std::size_t String::npos = static_cast<std::size_t>(-1);

std::size_t String::find(char c, std::size_t pos) const { // 16.定义一个find函数从指定位置查找c出现的位置并返回
    for (std::size_t i = pos; i < _size; ++i)
        if (_str[i] == c) return i;
    return npos;
}

std::size_t String::find(const char* s, std::size_t pos) const { // 17.定义一个find函数
    if (!s) return npos;
    std::size_t len = std::strlen(s);
    if (len == 0 || len > _size) return npos;
    for (std::size_t i = pos; i + len <= _size; ++i)
        if (std::strncmp(_str + i, s, len) == 0) return i;
    return npos;
}


String& String::insert(std::size_t pos, char c) { // 18.定义一个insert函数
    assert(pos <= _size);
    if (_size + 1 >= _capacity)
        reserve(_capacity * 2);
    for (std::size_t i = _size; i > pos; --i)
        _str[i] = _str[i - 1];
    _str[pos] = c;
    ++_size;
    _str[_size] = '\0';
    return *this;
}

String& String::insert(std::size_t pos, const char* str) { // 19.定义一个insert函数
    assert(pos <= _size);
    if (!str || !*str) return *this;
    std::size_t len = std::strlen(str);
    if (_size + len + 1 > _capacity)
        reserve(std::max(_capacity * 2, _size + len + 1));

    for (std::size_t i = _size; i > pos; --i)
        _str[i + len - 1] = _str[i - 1];   // 后移

    std::memcpy(_str + pos, str, len);
    _size += len;
    _str[_size] = '\0';
    return *this;
}

String& String::erase(std::size_t pos, std::size_t len) { // 20.定义一个erase函数
    if (pos >= _size || len == 0) return *this;
    if (pos + len >= _size) {
        _size = pos;
    } else {
        std::memmove(_str + pos, _str + pos + len, _size - pos - len + 1);
        _size -= len;
    }
    _str[_size] = '\0';
    return *this;
}

} // namespace guokai
