#include <iostream>
#include "test.h"
#include <vector.h>

int main(){

    int n,target; // 定义一个数组的长度和目标值大小
    std::cout << "请输入数组的大小n:" << endl;
    std::cin >> n; 

    std::vector<int> nums(n); // 定义一个动态数组
    for(int i=0; i<n; i++){
        std::cin >> nums[i]; // 输入每个数组的元素
    }
    std::cin >> target; // 输入目标值
    // 调用ToSum进行求解
    ToSum solver;
    std::vector<int> res = solver.findIndices(nums,target);

    // 输出结果
    if(res.size() == 2){
        std::cout << res[0] << " " << res[1] << "\n";
    }else{
        std::cout << "no solution found\n";
    }
    return 0;
}