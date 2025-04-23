#ifndef VECTOR_TPP
#define VECTOR_TPP
#include <cassert>
#include <algorithm>

namespace guokai {

// 1.默认构造函数
template<typename T>
vector<T>::vector() : _start(nullptr), _finish(nullptr), _end_of_storage(nullptr) {}

// 2.构造函数：指定大小初始化为 val
template<typename T>
vector<T>::vector(size_t n, const T& val) {
    _start = new T[n];
    std::fill(_start, _start + n, val);
    _finish = _start + n;
    _end_of_storage = _finish;
}

// 3.拷贝构造函数
template<typename T>
vector<T>::vector(const vector<T>& other) {
    _start = new T[other.capacity()];
    std::copy(other._start, other._finish, _start);
    _finish = _start + v.size();
    _end_of_storage = _start + v.capacity();
}

// 4.赋值运算符重载
template<typename T>
vector<T>& vector<T>::operator=(const vector<T>& other) {
    if (this != &other) {
        delete[] _start; // 先删除原来的空间
        size_t n = other.size();
        _start = new T[n];
        std::copy(other._start, other._finish, _start);
        _finish = _start + n;
        _end_of_storage = _finish;
    }
    return *this;
}

// 5.析构函数
template<typename T>
vector<T>::~vector() {
    delete[] _start;
}

// 6.当前元素个数
template<typename T>
size_t vector<T>::size() const {
    return _finish - _start;
}

// 7.当前容量
template<typename T>
size_t vector<T>::capacity() const {
    return _end_of_storage - _start;
}

// 8.是否为空
template<typename T>
bool vector<T>::empty() const {
    return _start == _finish;
}

// 9.非 const 下标访问
template<typename T>
T& vector<T>::operator[](size_t index) {
    if (index >= size()) throw std::out_of_range("index out of range");
    return _start[index];
}

// 10. const 下标访问
template<typename T>
const T& vector<T>::operator[](size_t index) const {
    if (index >= size()) throw std::out_of_range("index out of range");
    return _start[index];
}

// 11. push_back
template<typename T>
void vector<T>::push_back(const T& val) {
    if (_finish == _end_of_storage) {
        size_t new_capacity = std::max((size_t)1, size() * 2);
        reallocate(new_capacity);
    }
    *_finish = val;
    ++_finish;
}

// 12. pop_back
template<typename T>
void vector<T>::pop_back() {
    if (_finish != _start) {
        --_finish;
    }
}

// 13. clear
template<typename T>
void vector<T>::clear() {
    _finish = _start;
}

// 14. front
template<typename T>
T& vector<T>::front() {
    if (empty()) throw std::out_of_range("vector is empty");
    return *_start;
}

// 15. back
template<typename T>
T& vector<T>::back() {
    if (empty()) throw std::out_of_range("vector is empty");
    return *(_finish - 1);
}

// 16. reallocate
template<typename T>
void vector<T>::reallocate(size_t new_capacity) {
    size_t old_size = size();
    T* new_start = new T[new_capacity];
    std::copy(_start, _finish, new_start);
    delete[] _start;
    _start = new_start;
    _finish = _start + old_size;
    _end_of_storage = _start + new_capacity;
}

// 17. begin & end
template<typename T>
typename vector<T>::iterator vector<T>::begin() {
    return _start;
}

template<typename T>
typename vector<T>::iterator vector<T>::end() {
    return _finish;
}

// 18. insert
template<typename T>
void vector<T>::insert(iterator pos, const T& x) {
    assert(pos <= _finish);
    if (_finish == _end_of_storage) {
        size_t offset = pos - _start;
        size_t new_capacity = capacity() == 0 ? 2 : 2 * capacity();
        reallocate(new_capacity);
        pos = _start + offset;
    }
    for (iterator it = _finish; it != pos; --it) {
        *it = *(it - 1);
    }
    *pos = x;
    ++_finish;
}

// 19. erase
template<typename T>
typename vector<T>::iterator vector<T>::erase(iterator pos) {
    assert(pos < _finish);
    for (iterator it = pos; it + 1 < _finish; ++it) {
        *it = *(it + 1);
    }
    --_finish;
    return pos;
}

// 20. resize
template<typename T>
void vector<T>::resize(size_t n, const T& val) {
    if (n < size()) {
        _finish = _start + n;
    } else {
        if (n > capacity()) {
            reallocate(n);
        }
        while (_finish < _start + n) {
            *_finish = val;
            ++_finish;
        }
    }
}

} // namespace guokai

#endif // VECTOR_TPP
