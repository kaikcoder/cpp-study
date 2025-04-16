#include <iostream>
#include <vector>
using namespace std;
/* 需求:给定一个非空数组，除了某个元素只出现一次以外，每个元素均出现2次，找出那个只出现一次的元素 */

class Solution{
    public:
        int singleNumber(vector<int>& nums){
            int val = 0;
            for(auto e : nums){
                val ^= e;
            }
            return val;
        }
};

int main(){
    Solution sol;
    vector<int> nums = {4,1,1,2,2};
    int ret = sol.singleNumber(nums);
    cout << "找到的唯一数是:" << ret << endl;
    return 0;
}