#include <iostream>
#include <vector>
using namespace std;
/* 需求：给定一个非空数组，除了某个元素只出现一次以外，其他每个元素均出现3次，找出那个只出现一次的元素*/
/* 核心思想：
        一个数如果出现了3次那么它在每个二进制位上的总和也一定是3的倍数，如果我们把所有数的每一位加起来然后对3取模
        剩下的就是那个只出现一次的数在那一位上的值。

*/
class Solution{
    public:
        int singleNumber(vector<int>& nums){
            int bitArray[32] = {0};
            for(auto e : nums){ // 拿到数组中的每一个数
                for(int i=0; i<32; i++){ // 每一个整数都有32个二进制位，我们对每一位进行检查
                    if(e >> i & 1){ // 判断当前数字e的第i位是不是1
                        bitArray[i]++; // 如果是true，就说明e的第i位是1，bitArray[i]自增一位
                    }
                }
            }

            int result = 0; // 创建一个变量result存储最终答案
            for(int i=0; i<32; i++){
                if(bitArray[i] %3 != 0){
                    result |= (1 << i);
                }
            }
            return result;
        }
};

int main(){
    Solution s1;
    vector<int> nums = {1,1,1,2,2,2,3};
    int ret = s1.singleNumber(nums);
    cout << "只出现一次的数字是:" << ret << endl;
    return 0;
}