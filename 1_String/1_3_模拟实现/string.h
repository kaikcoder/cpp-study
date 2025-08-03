#pragma once
#include <cstddef>
#include <iostream>

/*
小结：把默认实参写在第一次声明处，在后续定义中省略，避免不同翻译单元对缺省值认识不一样
*/
namespace guokai {

class String {
public:
    using iterator       = char*;
    using const_iterator = const char*;

    String(const char* str = ""); // 声明一个带参数的默认构造函数
    String(const String& s); // 声明一个拷贝构造函数
    ~String(); // 声明一个析构函数

    String& operator=(const String& s); // 声明一个赋值运算符函数

    /* 声明一个迭代器 */
    iterator       begin()            { return _str; }
    const_iterator begin()    const   { return _str; }
    iterator       end()              { return _str + _size; }
    const_iterator end()      const   { return _str + _size; }

    /* 声明基本增删改函数 */
    void   push_back(char ch);
    void   pop_back();
    void   append(const char* str);
    void   clear();
    void   swap(String& s);

    /* 声明运算符重载函数 */
    String& operator+=(char c);
    String& operator+=(const char* str);
    const char& operator[](std::size_t index) const;
    char& operator[](std::size_t index);

    /* 声明返回状态容量函数 */
    std::size_t size()     const { return _size; }
    std::size_t capacity() const { return _capacity; }
    bool        empty()    const { return _size == 0; }
    const char* c_str()    const { return _str; }

    void resize(std::size_t newsize, char c = '\0');
    void reserve(std::size_t newCapacity);

    /* 声明查找插入删除函数*/
    static const std::size_t npos;
    std::size_t find(char c,               std::size_t pos = 0) const;
    std::size_t find(const char* s,        std::size_t pos = 0) const;
    String&     insert(std::size_t pos,    char c);
    String&     insert(std::size_t pos,    const char* str);
    String&     erase (std::size_t pos,    std::size_t len);

    /* 友元输出 */
    friend std::ostream& operator<<(std::ostream& os, const String& s)
    { return os << s._str; }

private:
    char*        _str      = nullptr;
    std::size_t  _size     = 0;
    std::size_t  _capacity = 0;
};

} // namespace guokai
