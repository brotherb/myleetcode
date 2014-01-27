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

vector<int> spiralOrder(vector<vector<int> > &matrix) {
    vector<int> res(0);
    
    long n = matrix.size();
    if (n == 0) {
        return res;
    }
    long m = matrix[0].size();
    //printf("%ld\n", m);
    if (m == 1) {
        for (int j = 0; j < n; j++) {
            res.push_back(matrix[j][0]);
        }
        return res;
    }
    long sum = m * n;
    n--;
    m--;
    int circle = 1;
    int i = 0, j = 0;
    int dirc = 0;
    int finish_one_circle = 0;
    while (sum--) {
        res.push_back(matrix[i][j]);
        //printf("%d %d %d\n", i, j, dirc);
        if(finish_one_circle){
            j++;
            if (j == m - circle) {
                dirc++;
            }
            circle++;
            finish_one_circle = 0;
            continue;
        }
        switch (dirc) {
            case 0:
                if (j == m - circle) {
                    dirc++;
                }
                j++;
                break;
            case 1:
                if(i == n - circle){
                    dirc++;
                }
                i++;
                break;
            case 2:
                if (j==circle) {
                    dirc++;
                }
                j--;
                break;
            case 3:
                if (i==circle+1) {
                    dirc = 0;
                    finish_one_circle = 1;
                }
                i--;
                break;
            default:
                break;
        }
    }
    return res;
}

int main(void){
    vector<vector<int> > mat;
    vector<int> a(0);
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    //a.push_back(4);
    vector<int> b(0);
    
    b.push_back(5);
    b.push_back(6);
    b.push_back(7);
    //b.push_back(8);
    vector<int> c(0);
    //c.push_back(7);
    //c.push_back(8);
    c.push_back(9);
    c.push_back(10);
    c.push_back(11);
    //c.push_back(12);
    vector<int> d(0);
    d.push_back(13);
    d.push_back(14);
    d.push_back(15);
    //d.push_back(16);
    mat.push_back(a);
    mat.push_back(b);
    mat.push_back(c);
    mat.push_back(d);
    vector<int> res = spiralOrder(mat);
    for (int i=0; i<12; i++) {
        printf("%d\n",res[i]);
    }
    return 0;
}
