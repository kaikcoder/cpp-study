#include <iostream>
#include <vector>
using namespace std;

/*
 * C++中“迭代器失效（iterator invalidation）”的概念：
 * 当你修改容器（如插入/删除元素）时，已有的迭代器可能会变得无效，
 * 继续使用就会导致未定义行为（如崩溃或访问错误数据）。

 * vector 的常见失效情况包括：
 *   - 添加元素导致扩容（原有迭代器指向的内存已被释放）
 *   - 删除元素使后续元素前移（原位置迭代器失效）

 * 安全操作技巧：
 *   - 不修改容器结构时，迭代器不会失效
 *   - erase()、insert() 操作后应使用返回的迭代器
 *   - 修改后重新获取迭代器
 */

void test(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    vector<int>::iterator it = v.begin();

    // 遍历整个 vector，读取元素
    while(it != v.end()){
        cout << *it << " "; // 读取当前迭代器指向的值
        ++it;               // 移动到下一个元素
    }
    cout << endl;
}

int main(){
    test();
    return 0;
}
