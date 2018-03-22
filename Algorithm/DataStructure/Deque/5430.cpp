//
//  10845.cpp
//  Algorithm
//
//  Created by 이광용 on 2018. 3. 22..
//  Copyright © 2018년 이광용. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <deque>
#include <string>
using namespace std;
deque<int> Deque;
int T;
char p[100000];
string input;
bool isFront = true;
int n;

bool func(char val) {
    if (Deque.empty()) return false;
    switch (val) {
    case 'R':
        isFront = !isFront;
        return true;
    case 'D':
        if (isFront) {
            Deque.pop_front();
        }
        else {
            Deque.pop_back();
        }
        return true;
    }
    return false;
}

void print() {
    cout<<'[';
    u_long size = Deque.size();
    for(int i=0; i<size; i++) {
        if (isFront) {
            cout<<Deque.front(); Deque.pop_front();
        }
        else {
            cout<<Deque.back(); Deque.pop_back();
        }
        
        if(Deque.empty()) {
            cout<<"]\n";
        }
        else {
            cout<<',';
        }
    }
}
int main() {
    cin>>T;
    for(int i=0; i<T; i++) {
        int x = -1;
        bool result = true;
        isFront = true;
        Deque.clear();
        cin>>p;
        cin>>n;
        while(1){
            char c = getchar();
            // 숫자가 나오면 현재 수*10 한 뒤 더함
            if(c >= '0' && c <= '9') x = x*10 + c-'0';
            // 아닐 경우 현재 수를 덱에 넣음
            else{
                if(x > 0) Deque.push_back(x);
                x = 0;
                if(c == ']') break;
            }
        }
        
        for (int j=0; j<strlen(p); j++) {
            if(!func(p[j])) {
                result = false;
                break;
            }
        }
        
        if (result) {
            print();
        }
        else {
            cout<<"error\n";
        }
    }
}


