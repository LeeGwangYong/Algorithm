//
//  main.cpp
//  Algorithm
//
//  Created by 이광용 on 2018. 3. 20..
//  Copyright © 2018년 이광용. All rights reserved.
//

#include <iostream>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 1001

int N, M, V;
bool vertex[MAX][MAX] = {false};
bool visited[MAX] = {false};
stack<int> dfsStack;
queue<int> bfsQueue;


void initializeVisited() {
    memset(visited, false, sizeof(visited));
}

void inputEdge(int range) {
    int vertexL, vertexR;
    for(int i = 0; i < range; i++) {
        cin>>vertexL>>vertexR;
        vertex[vertexL][vertexR] = vertex[vertexR][vertexL] = 1;
    }
}

void DFS(int start) {
    visited[start] = true;
    
    int now = dfsStack.top();
    cout<<now<<' ';
    for(int i=1; i<=N; i++) {
        if(!visited[i] && vertex[now][i]) {
            DFS(i);
        }
    }
}

void BFS(int start) {
    visited[start] = true;
    bfsQueue.push(start);
    while(!bfsQueue.empty()) {
        int now = bfsQueue.front();
        bfsQueue.pop();
        cout<<now<<' ';
        
        for(int i=1; i<= N; i++) {
            if (!visited[i] && vertex[now][i]) {
                bfsQueue.push(i);
                visited[i] = true;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    cin>>N>>M>>V;
    inputEdge(M);
    
    DFS(V);
    cout<<'\n';
    initializeVisited();
    BFS(V);
    cout<<'\n';
    return 0;
}
