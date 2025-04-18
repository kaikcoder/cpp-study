#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <stdexcept>
#include <algorithm>

namespace guokai{
    template<typename T>
    class vector{
        public:
            vector(); // 默认的构造函数
            vector(size_t n, const T& val = T()); // 构造指定大小的向量，初始化为val
            vector(const vector& other); // 拷贝构造函数
            vector& operator=(const vector& other); // 赋值运算符
            ~vector(); // 析构函数

            // 几个基本的访问接口
            size_t size() const; // 返回当前元素的个数
            size_t capacity() const; // 返回当前容量
            bool empty() const; // 判断是否为空

            T& operator[](size_t index); // 非const下标访问
            const T& operator[](size_t index) const; // const下标访问

            // 增删操作
            void push_back(const T& val); // 在末尾插入一个元素
            void pop_back(); // 删除最后一个元素
            void clear(); // 清空所有元素

            // 头尾元素访问
            T& font();
            T& back();

            void resize(size_t new_size, const T& val = T()); // resize函数
            void reallocate(size_t new_capacity);          // 扩容函数

        private:
            // 三个指针分别指向：起始位置、当前末尾、已经分配的内存末尾
            T* _start; // 指向起始位置
            T* _finish; // 指向当前末尾位置
            T* _end_of_storage; // 指向已经分配的内存末尾
    }
}

#include "vector.tpp" // 模板实现

#endif // VECTOR_H