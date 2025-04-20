#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <stdexcept>
#include <algorithm>

namespace guokai {

template<typename T>
class vector {
public:
    using iterator = T*; // 原始指针就是迭代器
    iterator begin();
    iterator end();
    vector(); // 声明一个默认的构造函数
    vector(size_t n, const T& val = T()); // 声明一个指定大小的构造函数
    vector(const vector& other); // 声明一个拷贝构造函数
    vector& operator=(const vector& other); // 声明一个赋值重载函数
    ~vector(); // 声明一个析构函数

    size_t size() const; // 声明一个函数返回当前元素的个数
    size_t capacity() const; // 声明一个函数返回当前容量大小
    bool empty() const; // 声明一个函数判断是否为空

    T& operator[](size_t index); // 声明一个下标函数重载的函数
    const T& operator[](size_t index) const; // 声明一个下标函数重载的函数

    void push_back(const T& val); // 声明一个push_back函数用于插入元素
    void pop_back(); // 声明pop_back函数用于删除元素
    void clear(); // 声明一个函数用于清空所有元素

    T& front(); // 访问第一个元素
    T& back(); // 访问最后一个元素

    void reallocate(size_t new_capacity); // 声明一个内部扩容函数
    void insert(iterator pos, const T& x); // 声明一个插入元素的函数
    iterator erase(iterator pos); // 声明一个删除指定位置元素的函数
    void resize(size_t n,const T& val = T()); // 声明一个resize函数

private:
    T* _start; // 指向存储空间的起始位置
    T* _finish; // 指向当前最后一个元素的下一个位置
    T* _end_of_storage; // 指向分配空间的末尾
};

} // namespace guokai

#include "vector.tpp" // 包含模板实现文件

#endif // VECTOR_H
