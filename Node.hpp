#pragma once
#include <iostream>

class Node {

    //private data
    std::string name;
    unsigned int level;
    char gender; 
    Node* left;
    Node* right;
    Node* child;

    public:
    //getters
    std::string getName() { return this->name; }
    Node* getLeft() { return this->left; }
    Node* getRight() { return this->right; }
    Node* getChild() { return this->child; }
    char getGender() { return this->gender; }
    unsigned int getLevel() { return this->level; }

    //setters
    void setLevel(unsigned int l){ this->level = l; }
    void setLeft(Node* n){ this->left = n; }
    void setRight(Node* n){ this->right = n; }
    void setChild(Node* n){ this->child = n; }
    void setGender(char g){ this->gender = g; }

    //constructor
    Node(std::string name, unsigned int l = 0) {
        this->name = name;
        this->level = l;
        this->left = this->right = this->child = nullptr;
    }
    //destructor
    ~Node(){}
};