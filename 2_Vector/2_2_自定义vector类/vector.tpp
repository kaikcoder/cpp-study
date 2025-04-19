#ifndef VECTOR_TPP
#define VECTOR_TPP

namespace guokai {

// 1.定义一个默认的构造函数
template<typename T>
vector<T>::vector() : _start(nullptr), _finish(nullptr), _end_of_storage(nullptr) {}

// 2.定义一个指定大小的的构造函数
template<typename T>
vector<T>::vector(size_t n, const T& val) {
    _start = new T[n];
    std::fill(_start, _start + n, val);
    _finish = _start + n;
    _end_of_storage = _finish;
}

// 3.定义一个拷贝构造函数
template<typename T>
vector<T>::vector(const vector<T>& other) {
    size_t n = other.size();
    _start = new T[n];
    std::copy(other._start, other._finish, _start);
    _finish = _start + n;
    _end_of_storage = _finish;
}

// 4.定义一个赋值重载函数
template<typename T>
vector<T>& vector<T>::operator=(const vector<T>& other) {
    if (this != &other) {
        delete[] _start;
        size_t n = other.size();
        _start = new T[n];
        std::copy(other._start, other._finish, _start);
        _finish = _start + n;
        _end_of_storage = _finish;
    }
    return *this;
}

// 5.定义一个析构函数
template<typename T>
vector<T>::~vector() {
    delete[] _start;
}

// 6.定义一个函数返回当前元素的个数
template<typename T>
size_t vector<T>::size() const {
    return _finish - _start;
}

// 7.定义一个函数返回当前容量的大小
template<typename T>
size_t vector<T>::capacity() const {
    return _end_of_storage - _start;
}

// 8.定义一个函数判断是否为空
template<typename T>
bool vector<T>::empty() const {
    return _start == _finish;
}

// 9.定义一个函数用于非const下标访问
template<typename T>
T& vector<T>::operator[](size_t index) {
    if (index >= size()) throw std::out_of_range("index out of range");
    return _start[index];
}

// 10.定义一个函数用于const下标访问
template<typename T>
const T& vector<T>::operator[](size_t index) const {
    if (index >= size()) throw std::out_of_range("index out of range");
    return _start[index];
}

// 11.定义一个函数用于从末尾插入元素
template<typename T>
void vector<T>::push_back(const T& val) {
    if (_finish == _end_of_storage) {
        size_t new_capacity = std::max((size_t)1, size() * 2);
        reallocate(new_capacity);
    }
    *_finish = val;
    ++_finish;
}

// 12.定义一个函数用于从末尾删除元素
template<typename T>
void vector<T>::pop_back() {
    if (_finish != _start) {
        --_finish;
    }
}

// 13.定义一个函数用于清空所有元素
template<typename T>
void vector<T>::clear() {
    _finish = _start;
}

// 14.定义一个函数用于访问第一个元素
template<typename T>
T& vector<T>::front() {
    if (empty()) throw std::out_of_range("vector is empty");
    return *_start;
}

// 15.定义一个函数用于访问最后一个元素
template<typename T>
T& vector<T>::back() {
    if (empty()) throw std::out_of_range("vector is empty");
    return *(_finish - 1);
}

// 16.定义一个函数用于扩容
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

} // namespace guokai

#endif // VECTOR_TPP
