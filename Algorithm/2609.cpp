//
//  2609.cpp
//  Algorithm
//
//  Created by 이광용 on 2018. 3. 21..
//  Copyright © 2018년 이광용. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int gcd(int left, int right) {
    while(right != 0) {
        int tmp = left % right;
        left = right;
        right = tmp;
    }
    
    return left;
}

int main() {
    int n, m;
    cin>>n>>m;
    cout<<gcd(n, m)<<'\n';
    cout<<n * m / gcd(n,m);
}
