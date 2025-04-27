/*
代码需求:判断出栈入栈顺序是否合法
*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution{
    public:
        bool IsPopOrder(vector<int> pushV,vector<int> popV){
            stack<int> st; // 定义一个栈
            int pushi = 0, popi = 0;
            while(pushi < pushV.size()){ // 遍历每一个入栈元素
                st.push(pushV[pushi]); // 将元素入栈
                ++pushi;

                while(!st.empty() && st.top() == popV[popi]){
                    st.pop(); // 将st的这个元素出栈
                    ++popi;
                }
            }

            return st.empty();
        }
};

int main(){
    Solution s; 
    vector<int> pushV = {1,2,3,4,5};
    vector<int> popV = {1,2,3,4,5};

    if(s.IsPopOrder(pushV,popV)){
        cout << "这个是合法的出栈顺序" << endl;
    }else{
        cout << "这个不是合法的出栈顺序" << endl;
    }
    return 0;
}