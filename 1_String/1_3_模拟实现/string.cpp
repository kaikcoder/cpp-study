#include "string.h"
#include <cstring>

namespace guokai {

// 1.定义一个构造函数
string::string(const char* str) {
    _size = strlen(str);
    _capacity = _size;
    _str = new char[_capacity + 1];
    strcpy(_str, str);
}


// 2.定义一个拷贝构造函数，采用拷贝并交换的方法
string::string(const string& s)
    : _str(nullptr), _size(0), _capacity(0) {
    string tmp(s._str);
    this->swap(tmp);
}


// 3.定义一个析构函数
string::~string() {
    if (_str) {
        delete[] _str;
        _str = nullptr;
    }
}


// 4.定义一个swap函数将当前字符串对象与参数对象s的内部数据全部交换
void string::swap(string& s) {
    std::swap(_str, s._str);
    std::swap(_size, s._size);
    std::swap(_capacity, s._capacity);
}


// 5.定义一个赋值运算符函数
string& string::operator=(string s) {
    this->swap(s);
    return *this;
}


// 6.定义迭代器接口
string::iterator string::begin() { return _str; }
string::iterator string::end() { return _str + _size; }


// 7.定义一个push_back函数
void string::push_back(char c) {
    if (_size == _capacity)
        reserve(_capacity == 0 ? 1 : 2 * _capacity);
    _str[_size++] = c;
    _str[_size] = '\0';
}


// 8.定义一个pop_back函数
void string::pop_back(){
    assert(_size > 0);
    --_size;
    _str[_size] = '\0';
}


// 9.定义一个追加字符串的函数
void string::append(const char* str) {
    size_t len = strlen(str);
    if (_size + len > _capacity)
        reserve(_size + len);
    strcpy(_str + _size, str);
    _size += len;
}


// 10.定义一个+=重载运算符函数(向后面添加字符)
string& string::operator+=(char c) {
    push_back(c);
    return *this;
}


// 11.定义一个+=重载运算符函数(向后面添加字符串)
string& string::operator+=(const char* str) {
    append(str);
    return *this;
}


// 12.定义一个clear函数清空字符串指针
void string::clear() {
    _size = 0;
    _str[0] = '\0';
}


// 13.定义一个返回c风格字符串的函数
const char* string::c_str() const { return _str; }


// 14.定义一个下标运算符重载函数(可以修改)
char& string::operator[](size_t index) {
    assert(index < _size);
    return _str[index];
}


// 15.定义一个下标运算符重载函数(只读)
const char& string::operator[](size_t index) const {
    assert(index < _size);
    return _str[index];
}

size_t string::size() const { return _size; }
size_t string::capacity() const { return _capacity; }
bool string::empty() const { return _size == 0; }


// 16.定义一个函数调整字符串的有效长度个数
void string::resize(size_t newSize, char c) {
    if (newSize > _size) {
        if (newSize > _capacity)
            reserve(newSize);
        /*
        mmset函数的基本功能：将内存区域的每个字节都设置为指定的值
        void* mmset(void* pstr, int value, size_t num):
            -pstr:指向要设置内存块的指针
            -value：要设置的值
            -num:要设置的个数
        */
        memset(_str + _size, c, newSize - _size);
    }
    _size = newSize;
    _str[_size] = '\0';
}


// 17.定义一个函数重新分配内存空间
void string::reserve(size_t newCapacity) {
    if (newCapacity > _capacity) {
        char* str = new char[newCapacity + 1];
        if (_str)
            strcpy(str, _str);
        else
            str[0] = '\0';
        delete[] _str;
        _str = str;
        _capacity = newCapacity;
    }
}


// 18.定义一个函数用于从指定位置开始查找字符c并返回第一次出现的下标
size_t string::find(char c, size_t pos) const {
    for (size_t i = pos; i < _size; ++i) {
        if (_str[i] == c)
            return i;
    }
    return npos;
}


// 19.定义一个函数用于查找子串（返回从 _str 开始的偏移）
size_t string::find(const char* str, size_t pos) const {
    /*
    strstr函数的基本功能：在一个c字符串中查找另外一个c字符串首次出现的位置
    strstr(_str + pos, str)
        -_str + pos: 表示从当前字符串中pos位置开始的子串
        -_str:待查找的子字符串
    */
    const char* result = strstr(_str + pos, str);
    return result ? result - _str : npos;
}


// 20.定义一个函数用于插入单个字符
string& string::insert(size_t pos, char c) {
    assert(pos <= _size);
    if (_size == _capacity)
        reserve(_capacity == 0 ? 1 : 2 * _capacity);
    /*
    memmove函数的基本功能：将从下标pos开始的那段内存数据向后移动一个字节
    memmove(_size + pos + 1, _size + pos, _size - pos + 1 )
        -_size + pos + 1:表示新数据要被移动的位置
        -_size + pos:表示从字符串下标pos的位置开始移动
        -_size - pos + 1:表示从下标pos到字符串末尾的字符都要移动
    */
    memmove(_str + pos + 1, _str + pos, _size - pos + 1);
    _str[pos] = c;
    ++_size;
    return *this;
}


// 21.定义一个函数用于插入字符串 
string& string::insert(size_t pos, const char* str) {
    assert(pos <= _size);
    size_t len = strlen(str);
    if (_size + len > _capacity)
        reserve(_size + len);
    memmove(_str + pos + len, _str + pos, _size - pos + 1);
    /*
    memcpy函数的基本功能：将源内存区的数据复制到目标区域中
    memcpy(_str + pos , str , len)
        -_str + pos: 开始拷贝的位置
        -_str：需要拷贝的目标内存起始地址
        -len：表示拷贝的长度
    */
    memcpy(_str + pos, str, len);
    _size += len;
    return *this;
}


// 22.定义一个函数用于删除子串
string& string::erase(size_t pos, size_t len) {
    assert(pos < _size);
    if (pos + len >= _size)
        _str[pos] = '\0';
    else
        memmove(_str + pos, _str + pos + len, _size - pos - len + 1);
    _size -= len;
    return *this;
}


// 输出运算符重载
std::ostream& operator<<(std::ostream& out, const string& s) {
    out << s.c_str();
    return out;
}


// 输入运算符重载（简单实现）
std::istream& operator>>(std::istream& in, string& s) {
    char buf[1024];
    in >> buf;
    s = buf;
    return in;
}


// 测试函数
void test() {
    string s1("hello");
    s1.push_back('g');
    s1 += "guokai";
    std::cout << s1 << std::endl;
    std::cout << "_size:" << s1.size() << std::endl;
    std::cout << "_capacity:" << s1.capacity() << std::endl;

    std::cout << "迭代器遍历：";
    string::iterator it = s1.begin();
    while (it != s1.end()) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
}

} // namespace guokai
