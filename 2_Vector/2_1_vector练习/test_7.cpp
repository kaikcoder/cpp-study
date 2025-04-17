#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
        vector<vector<int>> generate(int numRows){
            vector<vector<int>> vv; // 初始化一个二维数组
            vv.resize(numRows); // 定义二维vector，表示三角形的每一行

            for(size_t i=0; i<numRows; i++){
                vv[i].resize(i+1); // 第i行有i+1个元素
                vv[i][0] = 1; // 每行的第一个元素为1
                vv[i][vv[i].size() - 1] = 1; // 每行的最后一个元素为1

                for(size_t j=0; j<vv[i].size(); j++){
                    if(vv[i][j] != 1){
                        vv[i][j] = vv[i-1][j-1] + vv[i-1][j]; // 中间元素等于上一行相邻两个数之和
                    }
                }
            }

            return vv;
        }
};

int main(){
    int numRows = 5;
    Solution s1;
    vector<vector<int>> ret = s1.generate(numRows);

    // 打印杨辉三角
    for(const auto& row: ret){ // 第一层循环
        for(auto val:row){
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}