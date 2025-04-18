#ifndef VECTOR_TPP
#define VECTOR_TPP

/*
在类外定义模版函数时，每个函数前都要写template<typename T>;
在类内定义模版函数时，不用重复写template<typename T>,因为类头已经声明了
*/
namespace guokai{

    // 1.默认构造函数三个指针都初始化为空
    template<typename T>
    vector<T>::vector() : _start(nullptr), _finish(nullptr), _end_of_storage(nullptr){}

    // 2.构造指定大小的向量初始化为val
    template<typename T>
    vector<T>::vector(size_t n, const T& val = T()){
        _start = new T[n]; // 分配n个元素的空间
        std::fill(_start, _start + n, val); // 填充val元素
        _finish = _start + n; // _finish指向末尾元素
        _end_of_storage = finish; // 容量等于大小
    }

    // 3.拷贝构造函数
    template<typename T>
    vector<T>::vector(const vector<T>& other){
        size_t n = other.size();
        _start = new T[n]; // 分配空间
        std::copy(other._start,other._finish,_start); // 拷贝数据
        _finish = _start + n;
        _end_of_storage = _finish;
    }

    // 4.赋值运算符
    template<typename T>
    vector<T>& vector<T>::operator=(const vector<T>& other){
        if(this != &other){ // 防止自我赋值
            size_t n = other.size();
            delete[] _start; // 释放原来的空间
            _start = new T[n]; // 分配新的空间
            std::copy(other._start,other._finish,_start); // 拷贝数据
            _finish = _start + n;
            _end_of_storage = _finish;
        }

        return *this;
    }

    // 5.析构函数
    template<typename T>
    vector<T>::~vector(){
        delete[] _start;
    }
}