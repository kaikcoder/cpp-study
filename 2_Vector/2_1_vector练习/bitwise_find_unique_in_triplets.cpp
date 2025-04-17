#include <iostream>
#include <vector>
using namespace std;

/*
 *
 * ---------------------- 核心思想总结 ----------------------
 * 题目：
 *   给定一个非空数组，除了某个元素只出现一次以外，其他每个元素都出现了3次。
 *   找出那个只出现一次的元素。
 *
 * 解法思路：
 *   - 二进制统计法：用一个长度为32的数组，分别统计所有数在每个二进制位上出现的“1”的次数。
 *   - 如果某个数出现了3次，那么它在每一位上贡献的“1”次数一定是3的倍数。
 *   - 对每一位的总数对3取模，剩下的就是“只出现一次的数”在这一位上的值。
 *   - 最后将每一位还原成整数即可。
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bitArray[32] = {0}; // 存储每一位的“1”的出现次数

        // 遍历所有数字
        for (auto e : nums) {
            // 对于每一个数字的32位进行检查
            for (int i = 0; i < 32; i++) {
                if ((e >> i) & 1) { // 如果第 i 位是 1
                    bitArray[i]++; // 该位的计数加一
                }
            }
        }

        // 还原只出现一次的数
        int result = 0;
        for (int i = 0; i < 32; i++) {
            // 如果该位不是3的倍数，说明唯一那个数在这一位上是1
            if (bitArray[i] % 3 != 0) {
                result |= (1 << i); // 把第 i 位设为 1
            }
        }

        return result;
    }
};

int main() {
    Solution s1;
    vector<int> nums = {1, 1, 1, 2, 2, 2, 3};
    int ret = s1.singleNumber(nums);
    cout << "只出现一次的数字是: " << ret << endl;
    return 0;
}
