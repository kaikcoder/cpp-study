#include <iostream>
#include <vector>
using namespace std;

/*
 * 知识点总结：C++ 中 vector 的三种常见遍历方式及其特点
 * ------------------------------------------------------------
 * 1. operator[] + size() 方式：
 *    - 语法直观，支持读写元素
 *    - 适合需要下标访问或修改元素的场景
 *    - 性能较好（无额外封装）
 *
 * 2. 迭代器遍历：
 *    - 适用于所有 STL 容器
 *    - 可读写（使用普通迭代器），也可以定义成 const_iterator 只读
 *    - 更加 STL 风格
 *
 * 3. 范围 for（C++11 引入）：
 *    - 语法简洁
 *    - 默认访问的是元素值的副本（无法修改原容器元素）
 *    - 若想修改原数据，需使用引用 `for(auto& e : v)`
 */

int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    // 方式一：下标访问 + size()，支持读写
    for(size_t i = 0; i < v.size(); i++){
        cout << v[i] << " ";
        // v[i] += 10; // 可以修改原始元素
    }
    cout << endl;

    // 方式二：使用迭代器遍历，支持读写
    vector<int>::iterator it = v.begin();
    while(it != v.end()){
        cout << *it << " ";
        // *it += 10; // 也可以修改元素
        ++it;
    }
    cout << endl;

    // 方式三：范围 for 循环（C++11），默认按值访问（无法修改原始元素）
    for(auto e : v){
        cout << e << " ";
        // e += 10; // 不会修改原始 v 中的值
        // 若想要修改元素，需要写成for(auto& e : v)
    }
    cout << endl;

}

