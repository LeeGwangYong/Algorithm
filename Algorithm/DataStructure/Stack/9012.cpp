//
//  9012.cpp
//  Algorithm
//
//  Created by 이광용 on 2018. 3. 22..
//  Copyright © 2018년 이광용. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <stack>
using namespace std;

stack <char> leftStack;

int main()
{
    int n;
    cin >> n;
    char str[51];
    while (n--) {
        bool flag = false;
        
        cin >> str;
        for (int i = 0; i < strlen(str); i++) {
            if (str[i] == '(') {
                leftStack.push(str[i]);
            }
            else {
                if (leftStack.empty()) { flag = false; break; }
                else {
                    leftStack.pop();
                    flag = true;
                }
            }
        }
        if (!leftStack.empty()) flag = false;
        cout << ( flag ? "YES" : "NO") << "\n";
        while (!leftStack.empty()) leftStack.pop();
    }
    return 0;
}
