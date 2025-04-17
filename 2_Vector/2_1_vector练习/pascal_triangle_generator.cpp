#include <iostream>
#include <vector>

using namespace std;

/*
 * ------------------------ 知识点总结 ------------------------
 * 1. 杨辉三角性质：
 *    - 每行第一个和最后一个元素为 1
 *    - 其他元素为：上一行相邻两个元素之和
 *      即：vv[i][j] = vv[i-1][j-1] + vv[i-1][j]
 *
 * 2. 使用 vector<vector<int>> 动态构建二维数组：
 *    - 外层 vector 表示每一行
 *    - 内层 vector 表示该行的元素
 *
 * 3. 注意边界条件（如 i=0 时无前一行），需要通过初始化首尾为 1 来绕开
 */

class Solution{
public:
    vector<vector<int>> generate(int numRows){
        vector<vector<int>> vv;         // 定义二维 vector，用于保存整个杨辉三角
        vv.resize(numRows);             // 设置行数 numRows

        for(size_t i = 0; i < numRows; i++){
            vv[i].resize(i + 1);        // 第 i 行有 i+1 个元素
            vv[i][0] = 1;               // 每行的第一个元素设为 1
            vv[i][i] = 1;               // 每行的最后一个元素也设为 1（等价于 vv[i][vv[i].size()-1]）

            // 填充中间元素：从第 1 个到倒数第 1 个（不包含两端的1）
            for(size_t j = 1; j < i; j++){
                vv[i][j] = vv[i-1][j-1] + vv[i-1][j]; // 核心公式
            }
        }

        return vv;
    }
};

int main(){
    int numRows = 5;
    Solution s1;
    vector<vector<int>> ret = s1.generate(numRows); // 生成杨辉三角数据

    // 打印输出杨辉三角
    for(const auto& row : ret){      // 遍历每一行
        for(auto val : row){         // 遍历当前行中的每个元素
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
