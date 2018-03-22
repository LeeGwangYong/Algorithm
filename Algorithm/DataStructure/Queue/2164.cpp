//
//  2164.cpp
//  Algorithm
//
//  Created by 이광용 on 2018. 3. 22..
//  Copyright © 2018년 이광용. All rights reserved.
//

#include <stdio.h>
#include <queue>
#include <cstring>
#include <iostream>
using namespace std;

queue<int> Queue;
int n;
int main() {
    cin>>n;
    for(int i=1; i<=n; i++) {
        Queue.push(i);
    }
    while (Queue.size() > 1) {
        Queue.pop();
        int top = Queue.front(); Queue.pop();
        Queue.push(top);
    }
    cout<<Queue.front();

}
