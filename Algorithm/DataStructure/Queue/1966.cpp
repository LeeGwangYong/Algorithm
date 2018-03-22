//
//  1966.cpp
//  Algorithm
//
//  Created by 이광용 on 2018. 3. 22..
//  Copyright © 2018년 이광용. All rights reserved.
//

#include <stdio.h>
#include <queue>
#include <iostream>
#include <cstring>
using namespace std;
int testCase;
int N, M;
int val;
queue<int> Queue;
int main() {
    cin>>testCase;
    for (int i=0; i<testCase; i++) {
        cin>>N>>M;
        for(int j=0; j<N; j++) {
            cin>>val;
            Queue.push(val);
        }
    }
    
}
