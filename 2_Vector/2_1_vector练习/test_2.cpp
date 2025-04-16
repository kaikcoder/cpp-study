#include <iostream>
#include <vector>
/* 需求：遍历修改数据 */

using namespace std;

int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    // 1.方式一：operator[] + size
    for(size_t i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;


    // 2.方式二：迭代器
    vector<int>::iterator it = v.begin();
    while(it != v.end()){
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    // 3.方式三：范围for
    for(auto e : v){
        cout << e << " ";
    }
    cout << endl;
}