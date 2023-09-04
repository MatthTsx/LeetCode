#include<bits/stdc++.h>
// https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/

using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int size1 = matrix.size(), size2 = matrix[0].size(), resp = INT32_MIN;

        vector<vector<int>> prefix (size1 + 1, vector<int> (size2 + 1, 0));
        for(int i = 0; i < size1; i++)
            for(int j = 0; j < size2; j++){
                prefix[i+1][j+1] = matrix[i][j] + prefix[i][j+1] + prefix[i+1][j] - prefix[i][j];
                if(matrix[i][j] <= k) resp = max(matrix[i][j], resp);

                for(int r = 0; r <= i; r++)
                    for(int c = 0; c <= j; c++){
                        int vl = prefix[i+1][j+1] - prefix[r][j+1] - prefix[i+1][c] + prefix[r][c];
                        if(vl <= k) resp = max(vl, resp);
                    }
            }
        return resp;
    }
};