//
//  11279.cpp
//  Algorithm
//
//  Created by 이광용 on 2018. 3. 23..
//  Copyright © 2018년 이광용. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, less<int>> PQ;
int n, m;
int main() {
    cin>>n;
    
    for(int i=0; i<n; i++) {
        cin>>m;
        switch (m) {
            case 0:
            if (PQ.empty()) cout<<0<<'\n';
            else {
                cout<<PQ.top()<<'\n';
                PQ.pop();
            }
            break;
            default:
            PQ.push(m);
            break;
        }
    }
}
