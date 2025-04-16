#include <iostream>
#include <vector>
using namespace std;
/* 需求：给定一个非空数组，除了某个元素只出现一次以外，其他每个元素均出现3次，找出那个只出现一次的元素*/

class Solution{
    public:
        int singleNumber(vector<int>& nums){
            int bitArray[32] = {0};
            
            return 0;
        }
};

int main(){
    Solution s1;
    vector<int> nums = {1,1,1,2,2,2,3};
    int ret = s1.singleNumber(nums);
    cout << "只出现一次的数字是:" << ret << endl;
    return 0;
}