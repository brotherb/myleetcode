//
//  main.cpp
//  leet
//
//  Created by brotherb on 14-1-11.
//  Copyright (c) 2014 brotherb. All rights reserved.
//

#include <iostream>
#import <stack>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool isValid(string s) {
    int top = -1;
    char stack[1000];
    int len = s.length();
    for (int i = 0; i < len; i++){
        switch (s[i]){
            case ')':
                if(stack[top] == '(')top--;
                else return false;
                break;
            case ']':
                if(stack[top] == '[')top--;
                else return false;
                break;
            case '}':
                if(stack[top] == '{')top--;
                else return false;
                break;
            default:
                stack[++top] = s[i];
        }
    }
    return (top == -1);
}

int main(int argc, const char * argv[])
{

    string a = "(]";
    cout<< isValid(a)<<endl;
    return 0;
}
