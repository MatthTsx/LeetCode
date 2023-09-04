#include<bits/stdc++.h>
// https://leetcode.com/problems/range-sum-query-immutable/
// prefix sum

using namespace std;

class NumArray {
public:
    vector<int> prefixSum;

    NumArray(vector<int>& nums) {
        prefixSum = vector<int> (nums.size() + 1, 0);

        for(int i = 0; i < nums.size(); i++)
            prefixSum[i+1] += prefixSum[i] + nums[i];
    }
    
    int sumRange(int left, int right) {
        return prefixSum[right+1] - prefixSum[left];
    }
};