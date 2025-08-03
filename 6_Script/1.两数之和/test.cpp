/*
笔记:
    1.static_cast:
        -c++中的一种显示类型转换，用来把一个值从一个类型转换到另外一个类型
        -相比于c风格的(int)num.size(),static_cast更加安全、可读
    2.it->first:表示键
    3.it->end:表示值
*/
#include "test.h"
#include<unrdered_map>

std::vector<int> ToSum::findIndices(const vector<int>& nums, int target){
    // 定义一个函数在nums数组中找出两数之和为target的下标，保证有且一定只有一解
    std::unordered_map<int,int> mp; // 创建一个哈希表mp键为数组中的值，值为该元素的索引
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        int need = target - nums[i];
        auto it = mp.find(need);
        if(it != mp.end()){
            return {it->second,i};
        }
        mp[nums[i]] = i;
    }
    return {};
}