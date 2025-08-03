/*
demo_1输出结果：
    1.A是虚基类(virtual public A),因此只会在派生类D的构造函数初始化列表中的A(s1)来负责，这一步首先发生，所以哦先打印class A
    2.然后按照继承列出的顺序构造非基类，先B后C,它们各自在构造函数体内分别打印s2和s3
    3.最后执行D自己的构造函数体，打印class D
*/
#include <iostream>
using namespace std;

class A{
    public:
        // 定义一个默认构造函数
        A(char *s) {cout << s << endl;}
        // 定义一个析构函数
        ~A(){}
};

class B:virtual public A{
    public:
        // 定义一个构造函数
        B(char* s1,char *s2):A(s1) {cout << s2 << endl;}
};

class C:virtual public A{
    public:
        // 定义一个构造函数
        C(char *s1,char *s2):A(s1) {cout << s2 << endl;}
};

class D:public B,public C{
    public:
        // 定义一个构造函数
        D(char *s1,char *s2,char *s3,char *s4):B(s1,s2),C(s1,s3),A(s1) {cout << s4 << endl;}
};

int main(){
    D *p = new D("class A","class B","class C","class D");
    delete p;
    return 0;
}