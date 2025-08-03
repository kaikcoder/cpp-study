#include <iostream>
#include "BTree.h"

int main() {
    BSTree<int> tree;

    // 测试插入
    tree.Insert(5);
    tree.Insert(3);
    tree.Insert(7);
    tree.Insert(2);
    tree.Insert(4);
    tree.Insert(6);
    tree.Insert(8);

    std::cout << "中序遍历: ";
    tree.InOrder();  // 应该输出：2 3 4 5 6 7 8

    // 测试删除
    tree.erase(5);  // 删除根节点
    tree.erase(3);  // 删除有一个子节点的节点
    tree.erase(8);  // 删除叶子节点

    std::cout << "删除后中序遍历: ";
    tree.InOrder();  // 应该输出：2 4 6 7

    return 0;
}
