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

bool bsearch(int *a, int len, int e);

bool searchMatrix(vector<vector<int> > &matrix, int target) {

    int m = matrix.size();
    if(m == 0)return false;
    int n = matrix[0].size();
    if(n == 0)return false;
    if (matrix[m-1][n-1]< target || matrix[0][0] > target)return false;

    int i;
    for (i = 0; i < m; i++){
        if (target < matrix[i][0])break;
    }
    i--;
    return bsearch(&matrix[i][0],n,target);
}

bool bsearch(int *a, int len, int e){
    int lo = 0, hi = len - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if(e == a[mid])return true;
        if(e > a[mid]) lo = mid + 1;
        if(e < a[mid]) hi = mid -1;
    }
    return false;
}



int main(int argc, const char * argv[])
{

    std::cout << "Hello, World!\n";

    vector<vector<int> > test;
    vector<int> a = {1,3,5,7};
    vector<int> b = {10,11,16,20};
    vector<int> c = {23,30,34,50};
    test.push_back(a);
    test.push_back(b);
    test.push_back(c);

    for (int i = 0; i<3;i++){
        for (int j = 0; j < 4;j++){
            printf("%d ",test[i][j]);
        }
        putchar('\n');
    }

    for (int i = 0; i<= 50;i ++){
        if (searchMatrix(test, i)){
            printf("%d right\n",i);
        }
    }
    return 0;
}
