//
//  main.cpp
//  Algorithm
//
//  Created by 이광용 on 2018. 3. 21..
//  Copyright © 2018년 이광용. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <stack>
#include <cstdio>
using namespace std;

int n, minimum = 999999999, maximum = 0, res = 1;
int matrix[101][101] = {0};
bool visited[101][101] = {false};
int cnt = 0;
pair<int, int> direction[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

bool isValid(int x, int y) {
    if (1 <= x && x <= n && 1 <= y && y <= n) return true;
    return false;
}

void DFS(int x, int y, int minimum) {
    if(!isValid(x, y)) {return;}
    if(visited[x][y] || matrix[x][y] <= minimum) {return;}
    
    visited[x][y] = true;
    
    for(int i=0; i<4; i++) {
        int nextX = x + direction[i].first;
        int nextY = y + direction[i].second;
        DFS(nextX, nextY, minimum);
    }
}

int main() {
    cin>>n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin>>matrix[i][j];
            minimum = min(minimum, matrix[i][j]);
            maximum = max(maximum, matrix[i][j]);
        }
    }
    
    for(int m=minimum; m<= maximum; m++) {
        cnt = 0;
        memset(visited, false, sizeof(visited));
        for(int i=1; i<= n; i++) {
            for(int j=1; j<= n; j++) {
                if (!visited[i][j] && matrix[i][j] > m) {
                    DFS(i, j, m);
                    cnt++;
                }
            }
        }
        res = max(res, cnt);
    }
    
    cout<<res<<'\n';
    
    return 0;
}
