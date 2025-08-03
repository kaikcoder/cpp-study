#include <bits/stdc++.h>
using namespace std;

class TwoSum{
    public:
        // 在nums中找出两数之和为target的下标，保证一定有且只有一解
        vector<int> findIndices(const vector<int>& nums,int target){
            unordered_map<int,int> mp; // 定义一个哈希表
            for(size_t i=0; i<nums.size(); i++){
                int need = target - nums[i];
                auto it = mp.find(need);
                if(it != mp.end()){
                    return {it->second,static_cast<int>(i)}; // 返回两个下标
                }
                mp[nums[i]] = static_cast<int>(i); // 把当前遍历到的数值及它在数组中的下标记录到哈希表中
            }
            return {};
        }
};

int main(){
    int n,target; // 定义一个数组大小和目标值
    cout << "请输入数组的长度:";
    cin >> n;
    vector<int> nums(n); // 定义一个数组长度
    for(int i=0; i<nums.size(); i++){
        cin >> nums[i]; // 读取数组元素
    }
    cout << "请输入target的值:";
    cin >> target;
    TwoSum solver;
    vector<int> res = solver.findIndices(nums,target);
    if(res.size() == 2){
        cout << res[0] << " " << res[1] << "\n";
    }else{
        cout << "no solution found\n";
    }
    return 0;
}