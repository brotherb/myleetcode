//
//  main.cpp
//  leetcode
//
//  Created by brotherb on 14-1-5.
//  Copyright (c) 2014年 brotherb. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

bool isMatch(const char *s, const char *p) {
    if (*p == 0) {
        return *s ==0;
    }
    if (*(p+1) == '*') {
        while (*s!='\0'&&(*s == *p || *p == '.')) {
            if (isMatch(s, p+2)) {
                return true;
            }
            s++;
        }
        return isMatch(s, p+2);
    }else{
        if (*s == *p || (*p == '.' && *s != '\0')) {
            return isMatch(++s, ++p);
        }
        return false;
    }
    return true;
}


//0
//0
//1
//0
//1
//1
//1
//1
//1
//0
int main(void){
    char a[100],b[100];
    while (cin>>a>>b) {
        cout<<isMatch(a, b)<<endl;
    }
//    cout<<isMatch("aaa", "aaaa")<<endl;
//    cout<<isMatch("aa", "a")<<endl;
//    cout<<isMatch("aa", "aa")<<endl;
//    cout<<isMatch("aaa", "aa")<<endl;
//    cout<<isMatch("aa", "a*")<<endl;
//    cout<<isMatch("aa", ".*")<<endl;
//    cout<<isMatch("ab", ".*")<<endl;
//    cout<<isMatch("aab", "c*a*b*")<<endl;
//    cout<<isMatch("abcabc", ".*c.*c")<<endl;
//    cout<<isMatch("acaabbaccbbacaabbbb", "a*.*b*.*a*aa*a*")<<endl;
    isMatch("ab", ".*c");
    return 0;
}
