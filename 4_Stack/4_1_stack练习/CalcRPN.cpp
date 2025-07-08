/*
逆波兰表达式:操作数的顺序不变，操作符在操作数后面，并按优先级排列。
*/
#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

class Solution{
    public:
        int evalRPN(vector<string>& tokens){
            stack<int> st; // 定义一个栈
            for(const auto& str : tokens){
                // 1.操作符取栈数据进行运算
                // 2.操作数入栈
                if(str == "+" || str == "-" || str == "*" || str == "/"){
                    int right = st.top(); // 先出来的是右边的
                    st.pop(); // 取出右操作数
                    int left = st.top(); // 后出来的是左边的
                    st.pop(); // 取出左操作数

                    switch(str[0]){
                        case '+':
                            st.push(left+right);
                            break;
                        case '-':
                            st.push(left-right);
                            break;
                        case '*':
                            st.push(left*right);
                            break;
                        case '/':
                            st.push(left/right);
                            break;
                    }  
                }else{
                    st.push(stoi(str));
                }
            }
            return st.top();
        }
};

int main(){
    system("chcp 65001");
    Solution s;
    vector<string> tokens = {"1", "2", "3", "+", "-"};

    int res = s.evalRPN(tokens);
    cout << "操作符运算的结果是:" << res << endl;    
    return 0;
}