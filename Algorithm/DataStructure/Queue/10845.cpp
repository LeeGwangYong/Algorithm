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
using namespace std;

class Node {
    friend class Queue;
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
class Queue {
    private:
    Node *front = nullptr;
    Node *back = nullptr;
    int size = 0;
    public:
    void push(int value);
    int pop();
    int getSize();
    int empty();
    int getFront();
    int getBack();
};
void Queue::push(int value) {
    Node *newNode = new Node(value);
    if (this->back == nullptr) {
        this->front = newNode;
        this->back = newNode;
    }
    else {
        this->back->next = newNode;
        newNode->prev = this->back;
        this->back = newNode;
    }
    this->size++;
}

int Queue::pop(){
    if (this->front == nullptr) {return -1;}
    else {
        int val = this->front->data;
        if (size == 1) {
            free(this->front);
            this->front = nullptr;
            this->back = nullptr;
        }
        else {
            this->front = this->front->next;
            free(this->front->prev);
            this->front->prev = nullptr;
        }
        this->size--;
        return val;
    }
}

int Queue::getSize(){
    return size;
}

int Queue::empty(){
    return size == 0 ? 1 : 0;
}

int Queue::getFront() {
    if (this->front == nullptr) {
        return -1;
    }
    else {
        return this->front->data;
    }
}

int Queue::getBack() {
    if (this->back == nullptr) {
        return -1;
    }
    else {
        return this->back->data;
    }
}

int n;

int main() {
    cin>>n;
    Queue queue = Queue();
    for(int i=0; i<n; i++) {
        string instruction;
        cin>>instruction;
        if (instruction == "push") {
            int val;
            cin>>val;
            queue.push(val);
        }
        else if (instruction == "pop") {
            cout<<queue.pop()<<'\n';
        }
        else if (instruction == "size") {
            cout<<queue.getSize()<<'\n';
        }
        else if (instruction == "empty") {
            cout<<queue.empty()<<'\n';
        }
        else if (instruction == "front") {
            cout<<queue.getFront()<<'\n';
        }
        else if (instruction == "back") {
            cout<<queue.getBack()<<'\n';
        }
    }
}
