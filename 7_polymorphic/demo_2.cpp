/* 
demo_2的输出结果：
    1.因为A::func被声明为virtual，B::func是对它的覆盖也就是重写，因此通过基类接口调用时
      会发生动态绑定，实际执行的是B::func。
    2.在c++中，一旦基类把某个成员函数声明为virtual，派生类中覆盖该函数时它依然是虚函数，即使
      不再写virtual关键字。
    3.调用发生在A::test()中，默认参数按静态类型(A)取的是1，但函数体动态绑定到B::func，于是
      输出B->1。
*/

#include <iostream>
using namespace std;

class A{
public:
    virtual void func(int val = 1){
        std::cout << "A->" << val << std::endl;
    }
    virtual void test() {   
        func();           
    }
};

class B : public A{
    public:                    
        void func(int val = 0){
            std::cout << "B->" << val << std::endl;
        }
};

int main(){
    B* p = new B;
    p->test();              
    delete p;
    return 0;
}
