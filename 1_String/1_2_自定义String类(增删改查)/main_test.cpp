#include <iostream>
#include "string_test.h"

using namespace std;
using namespace guokai;

int main(){
    guokai::String s("nihao"); // 创建一个带初始字符串的对象
    cout << "原始字符串为:" << s.c_str() << endl;
    cout << "Size:" << s.size() << ",Capacity:" << s.capacity() << endl;

    s.append("c++"); // 追加字符串
    cout << "追加后的字符串为:" << s.c_str() << endl;
    cout << "Size: " << s.size() << ",Capacity:" << s.capacity() << endl;

    s.erase(2,3); // 删除字符串
    cout << "删除后的字符串:" << s.c_str() << endl;
    cout << "Size:" << s.size() << ",Capacity:" << s.capacity() << endl;

    size_t pos = s.find('h');
    if(pos != guokai::String::npos){
        cout << "h在字符串中第一次出现的位置：" << pos << endl;
    }else{
        cout << "未找到h字符" << endl;
    }
    return 0;
}