/*
代码功能：设计一个支持pop、push和top的操作，并能在常数时间内检索到最小元素
*/

#include <iostream>
#include <stack>

using namespace std;

class MinStack{
    public:
        // 1.定义一个构造函数
        MinStack(){}

        // 2.定义一个push函数
        void push(int val){
            if(minStack.empty() || val <= minStack.top()){
                minStack.push(val);
            }
            dataStack.push(val);
        }

        // 3.定义一个pop函数
        void pop(){
            if(minStack.top() == dataStack.top()){
                minStack.pop();
            }
            dataStack.pop();
        }

        // 4.定义一个top函数
        int top(){
            return dataStack.top();
        }

        // 5.定义一个函数检索最小元素
        int getMin(){
            return minStack.top();
        }
    private:
        stack<int> dataStack; // 定义一个栈存储正常元素
        stack<int> minStack;  // 定义一个栈存储最小元素
};

int main(){
    MinStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout << s.getMin() << endl;
    return 0;
}

