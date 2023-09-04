// https://leetcode.com/problems/product-of-array-except-self/
// prefix sum
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size(), qntd_zero = 0, sem_zero = 1;

        vector<int> resp (size,0);

        for(int i = 0; i < size; i++){
            int vl = nums[i];
            if(!vl) qntd_zero++;
            else sem_zero *= vl;
            if(qntd_zero > 1) break;
        }

        for(int i = 0; i < size; i++){
            int vl = nums[i];
            if(qntd_zero > 1) break;
            if(vl == 0) resp[i] = sem_zero;
            if(qntd_zero == 0) resp[i] = sem_zero/vl;
        }

        return resp;
    }
};