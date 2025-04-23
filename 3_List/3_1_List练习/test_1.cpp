#include <iostream>
#include <list>
using namespace std;

void test(){
    list<int> lt1;
    lt1.push_back(10);
    lt1.push_back(20);
    lt1.push_back(30);
    lt1.push_back(40);

    // 1.方式一：使用迭代器进行迭代
    list<int>::iterator it = lt1.begin();
    while(it != lt1.end()){
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    // 2.方式二：使用反向迭代器进行迭代
    list<int>::reverse_iterator rit = lt1.rbegin();
    while(rit != lt1.rend()){
        cout << *rit << " ";
        ++rit;
    }
    cout << endl;

    // 3.方式二：使用范围for进行迭代数据
    for(auto e : lt1){
        cout << e << " ";
    }
    cout << endl;
}

int main(){

    test(); // 调用这个函数
    return 0;

}