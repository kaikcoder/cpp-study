#ifndef TWO_SUM_H
#define TWO_SUM_H

#include<vector>

class ToSum{
    public:
        // 声明一个函数在nums数组中找出两数之和为target的下标，保证有且一定只有一解
        std::vector<int> findIndices(const vector<int>& nums, int target); 
};