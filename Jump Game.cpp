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

bool canJump(int A[], int n) {
    int max = 0;
    for (int i = 0; i < n; i++){
        if(i <= max){
            if (A[i] + i > max){
                max = A[i] + i;
            }
            if(max >= (n - 1)){
                return true;
            }
        }else{
            return false;
        }
    }
    return max >= (n-1);
}

int main(int argc, const char * argv[])
{
    int A[] = {2,3,1,1,5};
    cout<< canJump(A, 5)<<endl;
    int B[] = {3,2,1,0,4};
    cout<< canJump(B, 5)<<endl;
    return 0;
}
