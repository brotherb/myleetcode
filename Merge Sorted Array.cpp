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

void merge(int A[], int m, int B[], int n) {
    int i = 0;
    int j = 0;
    while(j < m + i && i < n){
        if(B[i] < A[j]){
            for (int k = m - 1 + i; k >= j; k--){
                A[k+1] = A[k];
            }
            A[j] = B[i];
            i++;
        }
        j++;
    }
    while(i < n){
        A[j++] = B[i++];
    }
}

int main(int argc, const char * argv[])
{
    int a[3] ={1,3,5};
    int b[1] = {};
    merge(a, 3, b, 0);
    return 0;
}
