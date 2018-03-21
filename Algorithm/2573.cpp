//
//  2573.cpp
//  Algorithm
//
//  Created by 이광용 on 2018. 3. 21..
//  Copyright © 2018년 이광용. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int row, column;
int map[301][301] = {0};
bool visited[301][310] = {false};
int directionX[4] = {1, -1, 0, 0};
int directionY[4] = {0, 0, 1, -1}; // 동 서 남 북

bool isValid(int x, int y) {
    if(1<=x && x<=row && 1<=y && y<=column) return true;
    return false;
}

int emptyCells(int x, int y) {
    int cnt = 0;
    for(int i=0; i<4; i++) {
        int newX = x + directionX[i];
        int newY = y + directionY[i];
        if (isValid(newX, newY)) {
            if (map[newX][newY] == 0) {
                cnt++;
            }
        }
    }
    return cnt;
}

void DFS(int x, int y) {
    if(!isValid(x, y)) {return;}
    if(visited[x][y] || map[x][y] == 0 ) {return;}
    
    visited[x][y] = true;
    for(int i=0; i<4; i++) {
        int newX = x + directionX[i];
        int newY = y + directionY[i];
        DFS(newX, newY);
    }
}

void meltDown() {
    int newMap[301][301];
    
    memcpy(newMap, map, sizeof(map));
    
    for(int i=1; i<=row; i++) {
        for(int j =1; j<=column; j++) {
            int emptys = emptyCells(i, j);
            int value = map[i][j] - emptys;
            newMap[i][j] = value >= 0 ? value : 0;
        }
    }
    
    memcpy(map, newMap, sizeof(newMap));
}

bool isEmpty() {
    for(int i=1; i<=row; i++) {
        for(int j=1; j<=column; j++) {
            if(map[i][j] > 0) return false;
        }
    }
    return true;
}

int main() {
    cin>>row>>column;
    
    for(int i=1; i<=row; i++) {
        for(int j=1; j<=column; j++) {
            cin>>map[i][j];
        }
    }
    
    int cnt = 0;
    int melt = 0;
    while(!isEmpty()) {
        //initialize cnt, visited
        cnt = 0;
        memset(visited, false, sizeof(visited));
        
        //detect divisions
        for(int i=1; i<=row; i++) {
            for(int j=1; j<=column; j++) {
                if(!visited[i][j] && map[i][j] > 0) {
                    DFS(i, j);
                    cnt++;
                    if (cnt > 1) {
                        cout<<melt;
                        return 0;
                    }
                }
            }
        }
        
        //melt down, add melt year
        meltDown();
        melt++;
    }
    
    cout<<0;
    return 0;
}
