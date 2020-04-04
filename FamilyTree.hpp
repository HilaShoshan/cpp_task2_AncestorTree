#pragma once

#include <bits/stdc++.h> 
#include "Node.hpp"
#include <string>

namespace family {

    class Tree {

        //attributes (Tree)
        Node* root = nullptr;

        public:
            //methods
            Tree& addFather(std::string name, std::string father);
            Tree& addMother(std::string name, std::string mother);
            std::string relation(std::string name);
            std::string find(std::string relation);
            void display();
            void remove(std::string name);

            //constructor
            Tree(std::string name) {
                this->root = new Node(name);
            }
            //destructor
            ~Tree() {
                std::cout << "destructor" << std::endl;
                this->root = destroy_family(this->root);
            }

            private:
            Node* destroy_family(Node* current){
                if(current == nullptr)
                    return nullptr;
                
                destroy_family(current->getLeft());
                destroy_family(current->getRight());
                delete current;
                return nullptr;
            }
    

            //source: https://stackoverflow.com/questions/13484943/print-a-binary-tree-in-a-pretty-way
            void printSubtree(Node* root, const std::string& prefix) {
                if(root == nullptr)
                    return;
                if(root->getLeft() == nullptr && root->getRight() == nullptr)
                    return;
                bool hasLeft = (root->getLeft() != nullptr);
                bool hasRight = (root->getRight() != nullptr);
                std::cout << prefix;
                std::cout << ((hasLeft && hasRight) ? "├── " : "");
                std::cout << ((!hasLeft && hasRight) ? "└── " : "");
                if (hasRight) {
                    bool printStrand;
                    printStrand = (hasLeft && hasRight && (root->getRight()->getRight() != nullptr 
                                                            || root->getRight()->getLeft() != nullptr));
                    std::string newPrefix = prefix + (printStrand ? "│   " : "    ");
                    std::cout << root->getRight()->getName() << std::endl;
                    printSubtree(root->getRight(), newPrefix);
                }

                if (hasLeft) {
                    std::cout << (hasRight ? prefix : "") << "└── " << root->getLeft()->getName() << std::endl;
                    printSubtree(root->getLeft(), prefix + "    ");
                }
            }    
            // source https://www.geeksforgeeks.org/level-order-tree-traversal/      
            Node* search(std::string toFind){
                if (this->root->getName() == toFind)  
                    return this->root; 
   
                std::queue<Node *> q; 
                q.push(this->root); 
  
                while(!q.empty()) { 
                    Node *current = q.front(); 
                    if(current->getName() == toFind)
                        return current;
                    q.pop();
                    if (current->getLeft() != nullptr) 
                        q.push(current->getLeft()); 
                    if (current->getRight() != nullptr) 
                        q.push(current->getRight()); 
                } 

                throw std::runtime_error("Not in the family");
            }

            std::string print_relation(unsigned int level, std::string relation){       
                if(level == 1)
                    return relation;
                else if(level == 2)
                    return "grand"+relation;
                else{
                    std::string ans = "grand"+relation;
                    for(int i = 0; i < level-2; i++) {
                        ans="great-"+ans;
                    }
                    return ans;
                }
            }
    };
}
