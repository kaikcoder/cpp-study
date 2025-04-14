#include<iostream>
#include "string.h"

int main(){
    guokai::string s1("hello");
    guokai::string s2 = s1; // 测试拷贝构造函数

    std::cout << "s1" << s1.c_str() << std::endl;
    std::cout << "s1" << s1.c_str() << std::endl;

    s2 = "world";
    std::cout << "赋值之后的结果是：" << s2.c_str() << std::endl;

    return 0;
}