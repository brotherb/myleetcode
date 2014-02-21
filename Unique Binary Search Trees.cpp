//
//  main.cpp
//  leet
//
//  Created by brotherb on 14-1-11.
//  Copyright (c) 2014 brotherb. All rights reserved.
//

#include <iostream>
#include <assert.h>
#import <vector>

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

int numTrees(int n) {
    vector<int> res(n+1,0);
    res[0] = 1;
    for (int i = 1; i <=n; i++){
        for (int j = 0; j < i/2; j++){
            res[i]+= res[j] * res[i-j-1];
        }
        res[i] *= 2;
        if (i%2) res[i] += res[i/2]*res[i/2];
    }
    return res[n];
}

int main(int argc, const char * argv[])
{
    cout<< numTrees(1)<<endl;
    cout<< numTrees(2)<<endl;
    cout<< numTrees(3)<<endl;
    cout<< numTrees(4)<<endl;
    cout<< numTrees(5)<<endl;
    return 0;
}
