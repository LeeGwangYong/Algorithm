//
//  1991.cpp
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
    friend class Tree;
    char data;
    Node *left;
    Node *right;
    public:
    Node(int data, Node *left = nullptr, Node *right = nullptr) {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

class Tree {
    Node *root;
    public:
    Node* getRoot() {
        return this->root;
    }
    
    void addTree(char value, char left, char right) {
        if (root == nullptr) {
            Node *newNode = new Node(value);
            if (left != '.') newNode->left = new Node(left);
            if (right != '.') newNode->right = new Node(right);
            this->root = newNode;
        }
        else {
            Node *detectNode = search(this->root, value);
            if (detectNode != nullptr) {
                if (left != '.') {
                    detectNode->left = new Node(left);
                }
                if (right != '.') {
                    detectNode->right = new Node(right);
                }
            }
        }
    }
    
    Node * search(Node *current,char value) {
        if (current == nullptr ) {return nullptr;}
        if (current->data == value) {return current; }
        
        Node *left = search(current->left, value);
        Node *right = search(current->right, value);
        if (left != nullptr) return left;
        else if (right != nullptr) return right;
        else return nullptr;
    }
    
    void preorder(Node* current);
    void inorder(Node* current);
    void postorder(Node* current);
};

void Tree::preorder(Node* current) {
    if (current == nullptr) return;
    cout<<current->data;
    preorder(current->left);
    preorder(current->right);
}
void Tree::inorder(Node* current) {
    if (current == nullptr) return;
    inorder(current->left);
    cout<<current->data;
    inorder(current->right);
}
void Tree::postorder(Node* current) {
    if (current == nullptr) return;
    postorder(current->left);
    postorder(current->right);
    cout<<current->data;
}

int n;
char x, y, z;
int main() {
    cin>>n;
    Tree tree = Tree();
    for(int i=0; i<n; i++) {
        cin>>x>>y>>z;
        tree.addTree(x, y, z);
    }
    
    tree.preorder(tree.getRoot());
    cout<<'\n';
    tree.inorder(tree.getRoot());
    cout<<'\n';
    tree.postorder(tree.getRoot());
    cout<<'\n';
}
