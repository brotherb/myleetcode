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

int sqrt(int x){
    if(x <= 1) return x;
    int lo = 0, hi = x;
    while (lo <= hi){
        int mid = (lo + hi) /2;
        if(mid == x/mid) return mid;
        if(mid < x/mid) lo = mid + 1;
        if(mid > x/mid) hi = mid - 1;
    }
    return hi;
}


int main(int argc, const char * argv[])
{

    cout<< sqrt(5)<<endl;
    return 0;
}
