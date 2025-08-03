#pragma once
#include <iostream>

// 定义节点结构体
template<class T>
struct BSTNode{
    BSTNode(const T& data = T())
        :_pleft(nullptr),_pright(nullptr),_data(data){}
    BSTNode<T>* _pleft;
    BSTNode<T>* _pright;
    T _data;
};

// 定义一个BSTree类
template<class T>
class BSTree{
    typedef BSTNode<T> Node;
    
    public:
        BSTree(); // 声明一个构造函数
        ~BSTree(); // 声明一个析构函数
        bool Insert(const T& data); // 声明一个插入函数
        bool erase(const T& data); // 声明一个删除函数
        void InOrder() const; // 声明一个中序遍历函数
        Node* Find(const T& data) const; // 声明一个find函数

    private:
        void _Destroy(Node* root);
        void _InOrder(Node* root) const;
        Node* _pRoot;
};

// 函数实现部分
// 定义一个BSTree构造函数
template<class T>
BSTree<T>::BSTree():_pRoot(nullptr){}

// 定义一个析构函数
template<class T>
BSTree<T>::~BSTree(){
    _Destroy(_pRoot);
    _pRoot = nullptr;
}

// 定义一个插入函数
template<class T>
bool BSTree<T>::Insert(const T& data){
    if(_pRoot == nullptr){ // 如果根节点为空则直接插入
        _pRoot = new Node(data);
        return true;
    }
    Node* pCur = _pRoot;
    Node* pParent = nullptr;
    while(pCur){
        pParent = pCur;
        if(data < pCur->_data){
            pCur = pCur->_pleft;
        }else if(data > pCur->_data){
            pCur = pCur->_pright;
        }else{
            return false; // 不允许插入相同的值
        }
    }
    pCur = new Node(data); // 插入数据
    if(data < pParent->_data){
        pParent->_pleft = pCur;
    }else if (data > pParent->_data)
    {
        pParent->_pright = pCur;
    }
    return true;
}

// 定义一个删除函数
template<class T>
bool BSTree<T>::erase(const T& data){
    if(_pRoot == nullptr){
        return false;
    }
    Node* pCur = _pRoot;
    Node* pParent = nullptr;
    // 寻找当前要删除的节点和父亲节点
    while(pCur){
        if(pCur->_data == data){
            break; // 如果刚好是要删除的元素则直接跳出循环
        }else if(data < pCur->_data){
            pParent = pCur;
            pCur = pCur->_pleft;
        }else{
            pParent = pCur;
            pCur = pCur->_pright;
        }
    }

    if(pCur == nullptr){
        return false; // 表示没有找到
    }

    // 情况一：左为空父亲指向我的右
    if(pCur->_pleft == nullptr){
        if(pParent->_pright == pCur){
            pParent->_pright = pCur->_pright;
        }else{
            pParent->_pleft = pCur->_pright;
        }
        delete pCur;
    }else if(pCur->_pright == nullptr){ // 情况二：右为空父亲指向我的左
        if(pParent->_pleft == pCur){
            pParent->_pleft = pCur->_pleft;
        }else{
            pParent->_pright = pCur->_pleft;
        }
        delete pCur;
    }else{// 情况三：左右都不为空，取右子树的最小节点值进行替换
        Node* rightMinParent = nullptr;
        Node* rightMin = pCur;
        // 寻找右子树的最小节点及其父亲节点
        while(rightMin->_pleft){
            rightMinParent = rightMin;
            rightMin = rightMin->_pleft;
        }
        // 进行数据替换
        pCur->_data = rightMin->_data;
        // 删除rightMin节点
        if(rightMinParent->_pright == rightMin){
            rightMinParent->_pright = rightMin->_pright;
        }else{
            rightMinParent->_pleft = rightMin->_pright;
        }
        delete rightMin;
    }
    return true;
}

// 定义一个find函数
Node* BSTree::Find(const T& data) const{
    Node* pCur = _pRoot;
    while(pCur){
        if(data > pCur->_data){
            pCur = pCur->_pright;
        }else if(data < pCur->_data){
            pCur = pCur->_pleft;
        }else{
            return pCur;
        }
    }
    return nullptr; // 表示没有找到
}

// 定义一个常量成员函数
template<class T>
void BSTree<T>::InOrder() const{
    _InOrder(_pRoot);
    std::cout << std::endl;
}

// 定义一个_InOrder函数
template<class T>
void BSTree<T>::_InOrder(Node* root) const{
    if(root == nullptr){
        return;
    }
    _InOrder(root->_pleft);
    std::cout << root->_data << " ";
    _InOrder(root->_pright);
}

// 定义一个_Destroy函数
template<class T>
void BSTree<T>::_Destroy(Node* root){
    if(root == nullptr){
        return;
    }
    _Destroy(root->_pleft);
    _Destroy(root->_pright);
    delete root;
}