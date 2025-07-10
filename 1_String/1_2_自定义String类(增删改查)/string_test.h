#ifndef STRING_H
#define STRING_H

#include <cstddef>
#include <cstring>
#include <algorithm>

namespace guokai{
    class String{
        public:
            // 定义一个常量，用于find失败时返回的值
            static const size_t npos = -1;

            // 声明一个无参的默认构造函数
            String();

            // 声明一个带参数的默认构造函数
            String(const char* str);

            // 声明一个析构函数
            ~String();

            // 声明一个拷贝构造函数
            String(const String& s);

            // 声明一个赋值运算符重载函数
            String& operator=(const String& s);

            // 声明一个函数返回字符串的长度
            size_t size() const;

            // 声明一个函数返回字符串的容量
            size_t capacity() const;

            // 声明一个函数重载[]
            const char& operator[](size_t i) const;

            // 声明一个函数返回c风格字符串
            const char* c_str() const;

            // 声明一个函数追加字符串
            void append(const char* str);

            // 声明一个函数删除从pos开始的len个字符
            void erase(size_t pos,size_t len = 1);

            // 声明一个函数查找字符ch第一次出现的位置
            size_t find(char ch) const;

            // 声明一个函数用于扩容
            void reserve(size_t new_cap);

        
        private:
            char* _str; // 用于存储字符数据的动态数组
            size_t _size; // 当前字符串的长度
            size_t _capacity;  // 当前分配的空间大小
    };
}

#endif