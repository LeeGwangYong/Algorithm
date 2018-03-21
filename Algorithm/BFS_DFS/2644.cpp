//
//  main.cpp
//  Algorithm
//
//  Created by 이광용 on 2018. 3. 21..
//  Copyright © 2018년 이광용. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

int n;
int p, c;
int m;
int x, y;
bool people[101][101] = {0};
bool visited[101] = {false};
int sum[101] = {0};
queue<int> que;

void BFS(int startNumber) {
    que.push(startNumber);
    visited[startNumber] = true;
    
    while(!que.empty()) {
        int now = que.front(); que.pop();
        for (int i = 1; i<=n; i++) {
            if (people[now][i] && !visited[i]) {
                que.push(i);
                visited[i] = true;
                sum[i] = sum[now] + 1;
            }
        }
    }
}

int main() {
    cin>>n;
    cin>>p>>c;
    cin>>m;
    for(int i=1; i<=n; i++) {
        cin>>x>>y;
        people[x][y] = people[y][x] = true;
        
    }
    
    BFS(p);
    
    cout<< (sum[c] != 0 ? sum[c] : -1);
    return 0;
}
