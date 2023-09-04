#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/split-array-largest-sum/
// prefix sum

// TODO: FIX THIS : not working right
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int resp = INT32_MAX, size = nums.size();

        for(int i = 1; i < size; i++) nums[i] += nums[i-1];
        for(int i = 0; i < size; i++) resp = min(resp, max(nums[i], nums[size-1] - nums[i]));

        return resp;
    }
};
