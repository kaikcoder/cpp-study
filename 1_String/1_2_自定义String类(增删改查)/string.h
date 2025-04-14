#ifndef STRING_H
#define STRING_H

#include <cstddef>
#include <cstring>
#include <algorithm>

namespace guokai {

class string {
public:
    // 定义一个常量，用于find失败时返回的值
    static const size_t npos = -1; 
    
    // 构造函数和析构函数
    string();
    string(const char* str);
    ~string();
    string(const string& s);
    string& operator=(const string& s);

    // 返回字符串长度及容量
    size_t size() const;
    size_t capacity() const;
    
    // 重载[]操作符
    const char& operator[](size_t i) const;
    char& operator[](size_t i);
    
    // 返回 C 风格字符串
    const char* c_str() const;

    // 追加字符串
    void append(const char* str);
    // 删除从 pos 开始的 len 个字符
    void erase(size_t pos, size_t len = 1);
    // 查找字符 ch 第一次出现的位置
    size_t find(char ch) const;

private:
    char* _str;        // 用于存储字符数据的动态数组
    size_t _size;      // 当前字符串的长度（不含结尾的'\0'）
    size_t _capacity;  // 当前分配的空间大小（包括 '\0' 的位置）
    
    // 用于扩容：分配至少 new_capacity 个字符大小的内存
    void reserve(size_t new_capacity);
};

} // namespace guokai

#endif // STRING_H
