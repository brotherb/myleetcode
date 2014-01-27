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

string convert(string s, int nRows) {
    if (nRows <= 1) {
        return s;
    }
    long len = s.length();
    char *res = (char *)malloc((len+1+1)*sizeof(char));
    int gap = 2 * nRows - 2;
    int top = 0;
    for (int i = 0; i < nRows; i++) {
        int flag = i;
        while (flag < len) {
            res[top++] = s[flag];
            if(!(i == 0 || i == nRows-1)){
                int mid = flag + gap - 2*i;
                if (mid < len) {
                    res[top++] = s[mid];
                } else {
                    break;
                }
            }
            flag += gap;
        }
    }
    res[len] = '\0';
    return res;
}

int main(void){
    string a = "PAYPALISHIRING";
    string b = "ABCDEFG";
    string res = convert("abcd", 2);
    cout<<res<<endl<<res.length()<<endl;
    cout<<convert(a, 2)<<endl;
    cout<<convert(a, 3)<<endl;
    cout<<convert(a,4)<<endl;
    cout<<convert(b, 10)<<endl;
    cout<<convert(b, 5)<<endl;
    return 0;
}
