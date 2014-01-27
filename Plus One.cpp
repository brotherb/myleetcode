//
//  main.cpp
//  leet
//
//  Created by brotherb on 14-1-11.
//  Copyright (c) 2014 brotherb. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

vector<int> plusOne(vector<int> &digits) {
    int n = digits.size();
    int pro = 1;
    while(n--){
        if(pro){
            digits[n]++;
            if(digits[n] == 10){
                digits[n] = 0;
                pro = 1;
            }else{
                pro = 0;
            }
        }
    }
    if(pro){
        digits.insert(digits.begin(),1);
    }
    return digits;
}

int main(int argc, const char * argv[])
{
    vector<int> a = {1,0,9};
    vector<int> res = plusOne(a);
    for (int i = 0; i < res.size(); i++){
        printf("%d", res[i]);
    }
    putchar('\n');
    return 0;
}
