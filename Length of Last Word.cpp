//
//  main.cpp
//  leet
//
//  Created by brotherb on 14-1-11.
//  Copyright (c) 2014 brotherb. All rights reserved.
//

#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int lengthOfLastWord(const char *s) {
    if (s == NULL) return 0;
    const char *p = s;
    int count = 0;
    int last = 0;
    while (*p){
        if(*p == ' '){
            if(count!=0){
                last = count;
                count = 0;
            }
        }
        else count++;
        p++;
    }
    if(count>0) return count;
    return last;
}

int main(int argc, const char * argv[])
{

    string a = "(]";
    cout<< lengthOfLastWord("b   a    ")<<endl;
    return 0;
}
