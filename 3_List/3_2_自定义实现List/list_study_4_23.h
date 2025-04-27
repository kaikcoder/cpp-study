#pragma once // 防止头文件被重复包含

#include <iostream>
using namespace std;

namespace guokai{ // 定义一个命名空间，防止和标准库冲突

    // 1.定义一个链表节点结构体
    template<class T>
    struct __list_node{
        __list_node<T>* _next; // 指向下一个节点的指针
        __list_node<T>* _prev; // 指向上一个节点的指针
        T _data; // 节点中存储的实际数据

        // 定义一个全缺省参数的构造函数
        __list_node(const T& x = T()):_data(x), _next(nullptr), _prev(nullptr){}
    };


    // 2.定义一个链表迭代器结构体
    // __list_iterator(T,T&,T*) -> 对应的普通迭代器
    // __list_iterator(T,const T&,const T*) -> 对应的const迭代器
    template<class T,class Ref,class Ptr>
    struct __list_iterator{
        typedef __list_node<T> Node; // 定义Node为__list_node的别名
        typedef __list_iterator<T,Ref,Ptr> Self; // 定义Self为__list_iterator的别名

        Node* _node; // 当前迭代器指向的节点

        // 定义一个构造函数
        __list_iterator(Node* node): _node(node){}

        // 重载*运算符，使其返回当前节点的数据引用
        Ref operator*() const{
            return _node->_data;
        }

        // 重载->运算符，使其返回当前节点的地址
        Ptr operator->() const{
            return &_node->_data;
        }

        // 重载++运算符，使其迭代器指向下一个节点
        Self& operator++(){
            _node = _node->_next;
            return *this; // 返回当前对象的引用
        }

        // 重载--运算符，使其迭代器指向上一个节点
        Self& operator--(){
            _node = _node->_prev;
            return *this; // 返回当前对象的引用
        }

        // 重载!=运算符，判断两个迭代器是否指向不同的节点
        bool operator!=(const Self& it){
            return this->_node != it->_node;
        }
    };

    // 3.定义一个链表类
    template<class T>
    class list{
        typedef __list_node<T> Node; // 定义Node为__list_node<T>的别名

        public:
            typedef __list_iterator<T,T&,T*> iterator; // 创建一个普通迭代器的别名
            typedef __list_iterator<T,const T&,const T*> const_iterator; // 创建一个const迭代器的别名

            // 1.定义list构造函数
            list(){
                _head = new Node; // 定义一个哨兵节点不存储实际数据
                _head->_next = _head; // 让_next指针指向自己表示链表为空
                _head->_prev = _head; // 让_prev指针也指向自己
            }

            // 2.定义一个拷贝构造函数
            list(const list<T>& other){
                _head = new Node; // 创建一个节点
                _head->_next = _head;
                _head->_prev = _head;

                for(auto& val : other){
                    push_back(val);
                }
            }

            // 3.定义一个赋值运算符函数
            list<T>& operator=(const list<T>& lt){
                if(this != &lt){ // 防止自我赋值
                    clear();
                    for(auto e : lt){
                        push_back(e);
                    }
                }
                return *this;
            }

            // 4.定义迭代器的begin()接口
            iterator begin(){
                return iterator(_head->_next);
            }

            // 5.定义迭代器的end()接口
            iterator end(){
                return iterator(_head);
            }

            // 6.定义const迭代器的begin()接口
            const_iterator begin(){
                return const_iterator(_head->_next);
            }

            // 7.定义const迭代器的end()接口
            const_iterator end(){
                return const_iterator(_head);
            }

            // 8.定义一个push_back函数
            void push_back(const T& x){
                Node* newNode = new Node(x); // 创建一个新的节点
                Node* tail = _head->_prev; // 找到当前的尾部节点

                tail->_next = newNode;
                newNode->_prev = tail;
                newNode->_next = _head;
                _head->_prev = newNode;
            }

            // 9.定义一个insert函数
            void insert(iterator pos, const T& x){
                Node* cur = pos._node; // 获取当前位置的节点指针
                Node* prev = cur->_prev; // 再获取当前位置的前一个指针
                Node* newNode = new Node(x); // 新建一个节点

                prev->_next = newNode;
                newNode->_prev = prev;
                newNode->_next = cur;
                cur->_prev = newNode;
            }

            // 10.定义一个clear函数
            void clear(){
                iterator it = begin();
                while(it != end()){
                    it = erase(it);
                }
            }

            // 11.定义一个erase函数
            iterator erase(iterator pos){
                assert(pos < end());
                Node* cur = pos._node; // 获取当前位置的节点指针
                Node* prev = cur->_prev; // 获取当前位置的前一个指针
                Node* next = cur->_next; // 获取当前位置的后一个指针
                delete cur; // 删除当前节点指针

                prev->_next = next;
                next->_prev = prev;

                return iterase(next); // 删除一个节点并返回下一个节点的位置
            }
        private:
            Node* _head; // 定义一个指向哨兵节点的指针
    }
}