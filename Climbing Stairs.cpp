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

int climbStairs(int n) {
    vector<int> steps((n+1),0);
    steps[1] = 1;
    steps[2] = 2;
    for (int i = 3; i <= n; i++){
        steps[i] = steps[i-1] + steps[i-2];
    }
    return steps[n];
}

int main(int argc, const char * argv[])
{
    cout<< climbStairs(1)<<endl;
    cout<< climbStairs(2)<<endl;
    cout<< climbStairs(3)<<endl;
    cout<< climbStairs(4)<<endl;
    cout<< climbStairs(5)<<endl;
    return 0;
}
