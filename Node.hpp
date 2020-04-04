#pragma once
#include <iostream>


class Node {

    //attributes
    std::string name;
    unsigned int level; 
    Node* left;
    Node* right;

    public:
    //getters
    std::string getName() { return this->name; }
    Node* getLeft() { return this->left; }
    Node* getRight() { return this->right; }
    unsigned int getLevel() { return this->level; }

    //setters
    void setLevel(unsigned int l){
        this->level = l;
    }
    void setLeft(Node* n){
        this->left = n;
    }
    void setRight(Node* n){
        this->right = n;
    }

    //constructor
    Node(std::string name, unsigned int l = 0){
        this->name = name;
        this->level = l;
        this->left = nullptr;
        this->right = nullptr;
    }
    //destructor
    ~Node(){}
};