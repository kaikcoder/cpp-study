#include <iostream>
#include <vector>

using namespace std;

/*
 * ------------------------- 知识点总结 -------------------------
 * 一、const 对象的用途：
 *    - const 本身表示“只读”语义
 *    - 我们实际中通常不会主动定义 const 对象（如 const vector<int> v），
 *      但在函数传参中经常会用到 const 引用来避免拷贝同时保护数据
 *      如：`void func(const vector<int>& v)`
 *
 * 二、三种常用的迭代器类型：
 *    1. iterator（普通正向迭代器）：
 *       - 可读可写
 *       - 从头到尾遍历容器
 *
 *    2. reverse_iterator（反向迭代器）：
 *       - 可读可写
 *       - 从尾到头遍历容器
 *
 *    3. const_iterator（常量正向迭代器）：
 *       - 只读，不能修改容器内容
 *       - 避免误操作，推荐用于函数只读访问
 */

int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    // 1.普通正向迭代器：可读可写，从 begin() 到 end()
    vector<int>::iterator it = v.begin();
    while(it != v.end()){
        cout << *it << " ";
        // *it += 1; // 可修改元素
        ++it;
    }
    cout << endl;

    // 2.反向迭代器：可读可写，从 rbegin() 到 rend()
    vector<int>::reverse_iterator it1 = v.rbegin();
    while(it1 != v.rend()){
        cout << *it1 << " ";
        // *it1 += 2; // 可修改元素
        ++it1;
    }
    cout << endl;

    // 3.常量正向迭代器：只读，不可写（访问不改值）
    vector<int>::const_iterator it2 = v.begin();
    while(it2 != v.end()){
        cout << *it2 << " ";
        // *it2 += 1; // ❌ 编译报错，const_iterator 只读
        ++it2;
    }
    cout << endl;

    return 0;
}
