//
//  main.cpp
//  leet
//
//  Created by brotherb on 14-1-11.
//  Copyright (c) 2014 brotherb. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void rotate(vector<vector<int> > &matrix) {
    int n = matrix.size();
    for (int i = 1; i < n;i++ )
        for (int j = 0; j < i; j++)
            std::swap(matrix[i][j], matrix[j][i]);
    for (int i = 0; i < n; i++)
        std::reverse(matrix[i].begin(), matrix[i].end());
}

int main(int argc, const char * argv[])
{
    vector<vector<int> > mat = {{1,2,3},{4,5,6},{7,8,9}};
    rotate(mat);
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%2d",mat[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
