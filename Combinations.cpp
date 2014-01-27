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

vector<vector<int> > combine(int n, int k) {
    vector<vector<int> > res(0);
    if(k == 0)return res;
    if(n == k){
        vector<int> a;
        for (int i = 1; i <= n; i++)
            a.push_back(i);
        res.push_back(a);
        return res;
    }
    if(k == 1){
        for (int i = 1; i <= n; i++){
            vector<int> a = {i};
            res.push_back(a);
        }
        return res;
    }
    vector<vector<int> > with = combine(n-1, k-1);
    for (int i = 0; i < with.size(); i++){
        with[i].push_back(n);
    }
    vector<vector<int> > without = combine(n-1, k);
    res.insert(res.end(), with.begin(), with.end());
    res.insert(res.end(), without.begin(), without.end());
    return res;
}

int main(int argc, const char * argv[])
{
    vector<vector<int> > res = combine(4, 1);
    for (int i = 0; i < res.size(); i++){
        for (int j = 0; j < res[i].size(); j++){
            printf("%2d", res[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
