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



vector<vector<int> > _subsets(vector<int> &S) {
    if (S.size() == 0) return {{}};
    int a = S.back();
    S.pop_back();
    vector<vector<int> > res = _subsets(S);
    int size = res.size();
    for (int i = 0; i < size; i++){
        vector<int> toadd = res[i];
        toadd.push_back(a);
        res.push_back(toadd);
    }
    return res;
}

vector<vector<int> > subsets(vector<int> &S) {
    std::sort(S.begin(), S.end());
    return _subsets(S);
}

int main(int argc, const char * argv[])
{
    vector<int> a = {4,1,0};
    vector<vector<int> > res = subsets(a);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            printf("%2d", res[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
