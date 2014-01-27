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

vector<vector<int> > permute(vector<int> &num) {
    int len = num.size();
    vector<vector<int> > res(0);
    if (len == 0) {
        vector<int> t(0);
        res.push_back(t);
        return res;
    }

    for (int i = 0; i < len; i++){
        vector<int> temp(num);
        vector<int>::iterator it = temp.begin() + i;
        temp.erase(it);
        vector<vector<int> > part = permute(temp);
        for (int j = 0; j < part.size(); j++){
            part[j].insert(part[j].begin(), num[i]);
            res.push_back(part[j]);
        }
    }
    return res;
}

int main(int argc, const char * argv[])
{
    vector<int> a = {1,2,3};
    vector<vector<int> > res = permute(a);
    for (int i = 0; i < res.size(); i++){
        for (int j = 0; j < res[i].size() ;j++){
            printf("%2d", res[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
