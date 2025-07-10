#include "string.h"
#include <cstring>
#include <algorithm>

namespace guokai {

// 默认构造函数：构造一个空字符串
string::string() : _size(0), _capacity(1) {
    _str = new char[_capacity];
    _str[0] = '\0';
}

// 带参构造函数：根据 C 风格字符串构造
string::string(const char* str) {
    if (str) {
        _size = std::strlen(str);
        _capacity = _size + 1; // 至少需要 _size + 1 的空间以存储 '\0'
        _str = new char[_capacity];
        std::strcpy(_str, str);
    } else {
        _size = 0;
        _capacity = 1;
        _str = new char[_capacity];
        _str[0] = '\0';
    }
}

// 析构函数：释放分配的内存
string::~string(){
    delete[] _str;
}

// 拷贝构造函数
string::string(const string& s)
    : _size(s._size), _capacity(s._capacity) {
    _str = new char[_capacity];
    std::strcpy(_str, s._str);
}

// 赋值运算符
string& string::operator=(const string& s){
    if (this != &s) {
        delete[] _str;
        _size = s._size;
        _capacity = s._capacity;
        _str = new char[_capacity];
        std::strcpy(_str, s._str);
    }
    return *this;
}

// 返回字符串长度
size_t string::size() const{
    return _size;
}

// 返回当前容量
size_t string::capacity() const {
    return _capacity;
}

// 重载[]（只读）
const char& string::operator[](size_t i) const{
    return _str[i];
}

// 重载[]（可写）
char& string::operator[](size_t i){
    return _str[i];
}

// 返回 C 风格字符串
const char* string::c_str() const{
    return _str;
}

// 私有的reserve函数，用于扩容
void string::reserve(size_t new_capacity) {
    if (new_capacity > _capacity) {
        char* new_str = new char[new_capacity];
        std::strcpy(new_str, _str);
        delete[] _str;
        _str = new_str;
        _capacity = new_capacity;
    }
}

// 追加字符串函数
void string::append(const char* str) {
    if (str) {
        size_t add_len = std::strlen(str);
        size_t new_size = _size + add_len;
        if (new_size + 1 > _capacity) {
            // 扩容策略：取新大小和当前容量两倍中的较大值
            size_t new_capacity = std::max(new_size + 1, _capacity * 2);
            reserve(new_capacity);
        }
        // 将追加的部分复制到原来的字符串末尾
        std::strcpy(_str + _size, str);
        _size = new_size;
    }
}

// 删除从 pos 开始的 len 个字符
void string::erase(size_t pos, size_t len) {
    if (_str && pos < _size) {
        if (pos + len > _size) {
            len = _size - pos;
        }
        // 使用 memmove 移动后半部分，并包含结尾 '\0'
        std::memmove(_str + pos, _str + pos + len, _size - pos - len + 1);
        _size -= len;
    }
}

// 查找字符 ch 第一次出现的位置
size_t string::find(char ch) const {
    for (size_t i = 0; i < _size; ++i) {
        if (_str[i] == ch) {
            return i;
        }
    }
    return npos;
}


} // namespace guokai
