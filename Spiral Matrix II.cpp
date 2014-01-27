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

vector<vector<int> > generateMatrix(int n) {
    int count = 1;
    int sum = n * n;
    vector<vector<int> > res(n, vector<int>(n));
    int i=0,j=0;
    int dirc = 0;
    int circle = 1;
    int finish_one_circle = 0;
    while (count<=sum) {
        //printf("%d %d %d\n",dirc,i,j);
        res[i][j] = count;
        count++;
        if(finish_one_circle){
            j++;
            finish_one_circle = 0;
            circle++;
            continue;
        }
        switch (dirc) {
            case 0:
                if (j==n-circle-1) {
                    dirc = 1;
                }
                j++;
                break;
            case 1:
                if(i==n-circle-1){
                    dirc = 2;
                }
                i++;
                break;
            case 2:
                if (j==circle) {
                    dirc = 3;
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
    int n;
    scanf("%d",&n);
    vector<vector<int> > res =  generateMatrix(n);
    for (int i =0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            printf("%d",res[i][j]);
        }
        printf("\n");
    }
}
