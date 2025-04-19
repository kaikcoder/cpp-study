#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <stdexcept>
#include <algorithm>

namespace guokai {

template<typename T>
class vector {
public:
    vector();
    vector(size_t n, const T& val = T());
    vector(const vector& other);
    vector& operator=(const vector& other);
    ~vector();

    size_t size() const;
    size_t capacity() const;
    bool empty() const;

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    void push_back(const T& val);
    void pop_back();
    void clear();

    T& front();
    T& back();

    void reallocate(size_t new_capacity);

private:
    T* _start;
    T* _finish;
    T* _end_of_storage;
};

} // namespace guokai

#include "vector.tpp" // 包含模板实现文件

#endif // VECTOR_H
