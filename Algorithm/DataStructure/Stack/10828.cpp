//
//  10828.cpp
//  Algorithm
//
//  Created by 이광용 on 2018. 3. 21..
//  Copyright © 2018년 이광용. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

class Node {
    friend class Stack;
    int data;
    Node *next;
    Node *prev;
    public:
    Node(int data, Node *prev = nullptr, Node * next = nullptr) {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};
class Stack {
    private:
    Node *bottom = nullptr;
    Node *top = nullptr;
    int size = 0;
    public:
    void push(int value);
    int pop();
    int getSize();
    int empty();
    int getTop();
};
void Stack::push(int value) {
    Node *newNode = new Node(value);
    if (this->top == nullptr) {
        this->bottom = newNode;
        this->top = newNode;
    }
    else {
        this->top->next = newNode;
        newNode->prev = this->top;
        this->top = newNode;
    }
    this->size++;
}

int Stack::pop(){
    if (this->top == nullptr) {return -1;}
    else {
        int val = this->top->data;
        if (size == 1) {
            free(this->top);
            this->bottom = nullptr;
            this->top = nullptr;
        }
        else {
            this->top = this->top->prev;
            free(this->top->next);
            this->top->next = nullptr;
        }
        this->size--;
        return val;
    }
}

int Stack::getSize(){
    return size;
}

int Stack::empty(){
    return size == 0 ? 1 : 0;
}

int Stack::getTop() {
    if (this->top == nullptr) {
        return -1;
    }
    else {
        return this->top->data;
    }
}

int n;

int main() {
    cin>>n;
    Stack stack = Stack();
    for(int i=0; i<n; i++) {
        string instruction;
        cin>>instruction;
        if (instruction == "push") {
            int val;
            cin>>val;
            stack.push(val);
        }
        else if (instruction == "pop") {
            cout<<stack.pop()<<'\n';
        }
        else if (instruction == "size") {
            cout<<stack.getSize()<<'\n';
        }
        else if (instruction == "empty") {
            cout<<stack.empty()<<'\n';
        }
        else if (instruction == "top") {
            cout<<stack.getTop()<<'\n';
        }
    }
}


