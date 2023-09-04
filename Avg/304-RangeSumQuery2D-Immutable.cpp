#include<bits/stdc++.h>
// https://leetcode.com/problems/range-sum-query-2d-immutable/
// prefix sum || 2D prefix sum

using namespace std;

class NumMatrix {
public:
    vector<vector<int>> prefix;

    NumMatrix(vector<vector<int>>& matrix) {
        prefix = vector<vector<int>> (matrix.size()+1, vector<int> (matrix[0].size()+1, 0));
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++)
                prefix[i+1][j+1] = prefix[i][j+1] + prefix[i+1][j] - prefix[i][j] + matrix[i][j];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++;
        col1++;
        row2++;
        col2++;
        return prefix[row2][col2] - prefix[row1-1][col2] - prefix[row2][col1-1] + prefix[row1-1][col1-1];
    }
};

