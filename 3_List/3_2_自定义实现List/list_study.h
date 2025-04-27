#pragma once
#include <iostream>
using namespace std;

namespace guokai{ // 定义一个命名空间，防止和标准库冲突

    // 1.定义一个链表节点结构体
    template<class T>
    struct __list_node{
        __list_node<T>* _next; // 指向下一个节点的指针
        __list_node<T>* _prev; // 指向上一个节点的指针
        T _data; // 节点中存储的实际数据

        // 定义一个带参数的构造函数
        __list_node(const T& x = T()):_data(x), _next(nullptr), _prev(nullptr){};
    };

    // 2.定义一个链表迭代器结构体
    // __list_iterator(T,T&,T*) -> 对应的普通迭代器
    // __list_iterator(T,const T&,cosnt T*) -> 对应的const迭代器
    template<class T,class Ref,class Ptr>
    struct __list_iterator{
        typedef __list_node<T> Node; // 定义Node为__list_node的别名
        typedef __list_iterator<T,Ref,Ptr> Self;
        Node* _node; // 当前迭代器指向的节点

        __list_iterator(Node* node): _node(node) {} // 构造函数接受一个节点

        // 重载*运算符，使其返回当前节点的数据引用
        Ref operator*() const{
            return _node->_data;
        }

        // 重载->运算符,使其返回当前节点的地址
        Ptr operator->() const{
            return &_node->_data;
        }

        // 重载++运算符，使其迭代器指向下一个节点
        Self& operator++(){
            _node = _node->_next; // 向后移动一个节点
            return *this; // 返回当前迭代器对象
        }

        // 重载--运算符，使其迭代器指向上一个节点
        Self& operator--(){
            _node = _node->_prev;
            return *this;
        }

        // 重载!=运算符，判断两个迭代器是否指向不同的节点
        bool operator!=(const Self& it){
            return this->_node != it._node;
        }
    };

    // 3.定义一个链表类
    template<class T>
    class list{
        typedef __list_node<T> Node; // 定义Node为__list_node的别名
    
        public:
            typedef __list_iterator<T,T&,T*> iterator; // 创建一个普通迭代器的别名
            typedef __list_iterator<T,const T&,const T*> const_iterator; // 创建一个const迭代器的别名

            // 定义list的构造函数
            list(){ 
                _head = new Node; // 定义一个哨兵节点不存储实际数据
                _head->_next = _head; // 让_next指针指向自己表示链表为空
                _head->_prev = _head; // _prev指针也指向自己
            }

            // 定义list的析构函数
            ~list(){
                clear();
                delete _head;
                _head = nullptr;
            }

            // 定义一个拷贝构造函数
            list(const list<T>& other){
                _head = new Node;
                _head->_next = _head;
                _head->_prev = _head;

                for(auto& val: other){
                    push_back(val);
                }
            }

            // 定义一个赋值运算符函数
            list<T>& operator=(const list<T>& lt){
                if(this != &lt){ // 防止自我赋值
                    clear();
                    for(auto e : lt){
                        push_back(e);
                    }
                }
                return *this;
            }

            iterator begin(){ // 返回指向链表第一个有效元素的迭代器
                return iterator(_head->_next); 
            }

            iterator end(){ // 返回指向哨兵节点的迭代器
                return iterator(_head);
            }

            const_iterator begin() const{ // 返回指向链表第一个有效元素的迭代器(const对象)
                return const_iterator(_head->_next);
            }

            const_iterator end() const{ // 返回指向哨兵节点的迭代器(cosnt对象)
                return const_iterator(_head);
            }

            // 定义一个push_back函数
            void push_back(const T& x){
                Node* newNode = new Node(x); // 创建一个新的节点
                Node* tail = _head->_prev; // 找到当前的尾部节点

                tail->_next = newNode;
                newNode->_prev = tail;

                newNode->_next = _head;
                _head->_prev = newNode;
                
            }

            // 定义一个push_front函数
            void push_front(const T& x){
                insert(begin(),x);
            }

            // 定义一个pop_back函数
            void pop_back(){
                erase(--end());
            }

            // 定义一个pop_front函数
            void pop_front(){
                erase(begin());
            }

            // 定义一个insert函数
            void insert(iterator pos, const T& x){
                Node* cur = pos._node; // 取出当前位置的节点指针
                Node* prev = cur->_prev; // 再找到当前节点的前一个指针
                Node* newnode = new Node(x); // 新建一个节点

                prev->_next = newnode;
                newnode->_prev = prev;
                newnode->_next = cur;
                cur->_prev = newnode;

            }

            // 定义一个clear()函数
            void clear(){
                iterator it = begin();
                while(it != end()){
                    it = erase(it);
                }
            }

            // 定义一个erase函数
            void erase(iterator pos){
                assert(pos != end());
                Node* cur = pos._node; // 取出当前节点的指针
                Node* prev = cur->_prev; // 取出当前节点的前一个指针
                Node* next = cur->_next; // 取出当前节点的后一个指针
                delete cur;

                prev->_next = next;
                next->_prev = prev;
            }

        private:
            Node* _head; // 指向哨兵节点的指针
    };

    // 4.定义一个函数用于测试迭代器效果
    void test_iterator(){
        list<int> lt; // 定义一个链表
        lt.push_back(1);
        lt.push_back(2);
        lt.push_back(3);
        lt.push_back(4);

        list<int>::iterator it = lt.begin();
        while(it != lt.end()){
            cout << *it << " ";
            ++it;
        }
        cout << endl;
    }

    // 5.设置一个打印输出函数
    void print_list(const list<int>& lt){
        // 这里的const对象不能调用begin()函数
        // const对象不能用普通的对象
        list<int>::const_iterator it = lt.begin();
        while(it != lt.end()){
            cout << *it << " ";
            ++it;
        }
        cout << endl;
    }

    // 6.const迭代器的使用场景
    void test_iterator_const(){
        list<int> lt; // 定义一个链表
        lt.push_back(1);
        lt.push_back(2);
        lt.push_back(3);
        lt.push_back(4);

        print_list(lt);
    }
}