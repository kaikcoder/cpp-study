#include <iostream>
#include "string.h"

using namespace std;
using namespace guokai;

int main(){
    // 创建一个带初始字符串的对象
    guokai::string s("hello world!");
    cout << "原始字符串：" << s.c_str() << endl;
    cout << "Size: " << s.size() << ", Capacity: " << s.capacity() << endl;

    // 追加字符串
    s.append(" c++");
    cout << "追加后的字符串: " << s.c_str() << endl;
    cout << "Size: " << s.size() << ", Capacity: " << s.capacity() << endl;

    // 删除从下标5开始的7个字符
    s.erase(5, 7);
    cout << "删除后的字符串: " << s.c_str() << endl;
    cout << "Size: " << s.size() << ", Capacity: " << s.capacity() << endl;

    // 查找字符 '!'
    size_t pos = s.find('!');
    if(pos != guokai::string::npos){
        cout << "!在字符串中第一次出现的位置: " << pos << endl;
    } else {
        cout << "未找到!字符" << endl;
    }

    return 0;
}
