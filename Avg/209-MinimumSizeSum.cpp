// https://leetcode.com/problems/minimum-size-subarray-sum/
// prefix sum
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int size = nums.size();
        for(int i = 1; i < size; i++)
            nums[i] += nums[i-1];
        
        int resp = 0;
        bool loaded = false;
        for(int i = size; i >= 1; i--){
            if(nums[i-1] >= target)
                if(!loaded) {resp = i; loaded = true;}
                else resp = min(i,resp);
            else continue;
            for(int j = 1; j <= i-1; j++){
                int vl = nums[i-1] - nums[j-1];
                if(vl >= target){
                    if(!loaded) {resp = i-j; loaded = true;}
                    else resp = min(i-j,resp);
                }else break;
            }
        }

        return resp;
    }
};