#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

// 1.定义一个打印输出函数
void print_list(list<int>& lt){
    list<int>::iterator it = lt.begin();
    while(it != lt.end()){
        cout << *it << " ";
        ++it;
    }
    cout << endl;
}

// 2.定义一个test函数对list进行头插和尾插
void test(){
    list<int> lt;
    lt.push_back(10);
    lt.push_back(20);
    lt.push_back(30);
    lt.push_back(40);

    lt.push_front(1);
    print_list(lt);
}

// 3.定义一个test_1函数对list任意位置进行插入和删除
void test_1(){
    list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(3);
    lt.push_back(4);
    lt.push_back(5);
    lt.push_back(6);
    list<int>::iterator pos = find(lt.begin(),lt.end(),3);
    if(pos != lt.end()){
        lt.insert(pos,30);
        lt.erase(pos);
    }
    print_list(lt);
}

// 4.定义一个函数test_2对list中的偶数进行删除
void test_2(){
    list<int> lt;
    lt.push_back(3);
    lt.push_back(2);
    lt.push_back(1);
    lt.push_back(5);
    lt.push_back(4);
    lt.push_back(6);

    list<int>::iterator it = lt.begin();
    while(it != lt.end()){
        if(*it % 2 == 0){
            it = lt.erase(it);
        }else{
            ++it;
        }
    }
    print_list(lt); 
}

int main(){
    test_2();
    return 0;
}