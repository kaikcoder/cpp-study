#include <iostream>
#include <vector>

/*
const对象：我们实际中不会直接定义const对象，因为没意义，const对象基本都是在传参过程中产生的，
           因为传参为了提高效率基本都会使用&传参，而引用传参如果不改变对象基本都会加const

*/

using namespace std;
/* 三种类型的迭代器 */

int main(){

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    // 1.普通正向迭代器,可读可写
    vector<int>::iterator it = v.begin();
    while(it != v.end()){
        cout << *it << " ";
        ++it;
    }
    cout << endl;
    
    // 2.反向迭代器
    vector<int>::reverse_iterator it1 = v.rbegin();
    while(it1 != v.rend()){
        cout << *it1 << " ";
        ++it1;
    }
    cout << endl;
    
    return 0;
}