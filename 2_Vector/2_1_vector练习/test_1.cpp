#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);

    vector<int> v2(v1); // 拷贝构造

    for(size_t i=0; i<v1.size(); i++){
        cout << v1[i] << " ";
    }

    cout << endl;

    for(size_t i=0; i<v2.size(); i++){
        cout << v2[i] << " ";
    }

    cout << endl;

    vector<int> v3;
    v3.push_back(10);
    v3.push_back(20);
    v3.push_back(30);
    v3.push_back(40);

    v1 = v3;

    for(size_t i=0; i<v1.size(); i++){
        cout << v1[i] << " ";
    }

    cout << endl;

}