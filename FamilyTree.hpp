#pragma once

#include <bits/stdc++.h> 
#include "Node.hpp"
#include <string>

namespace family {

    class Tree {

        //private data
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
            //source https://www.geeksforgeeks.org/level-order-tree-traversal/ 

            Node* search_by_name(int level = -1, std::string toFind = "false") {

                int num; //number that represents what we should search
                if(toFind != "false" && level == -1)
                    num = 0; //the function get a string (name) to find 
                else num = 1; //the function get a level to find someone in this level

                if((num == 0 && this->root->getName() == toFind)
                    || (num == 1 && this->root->getLevel() == level))  
                    return this->root; 
                std::queue<Node *> q; 
                q.push(this->root); 
                while(!q.empty()) { 
                    Node *current = q.front(); 
                    if((num == 0 && current->getName() == toFind)
                        || (num == 1 && current->getLevel() == level))
                        return current;
                    q.pop();
                    if (current->getLeft() != nullptr) 
                        q.push(current->getLeft()); 
                    if (current->getRight() != nullptr) 
                        q.push(current->getRight()); 
                } 
                throw std::runtime_error("Not in the family");
            }

            /*Node* search_by_lavel(int level) {

            }*/

            std::string print_relation(unsigned int level, std::string relation) {       
                if(level == 1)
                    return relation;
                else if(level == 2)
                    return "grand"+relation;
                else {
                    std::string ans = "grand"+relation;
                    for(int i = 0; i < level-2; i++)
                        ans="great-"+ans;
                    return ans;
                }
            }

            unsigned int print_level(std::string relation) {
                if(relation == "me")
                    return 0;
                else if(relation == "mother" || relation == "father")
                    return 1;
                else if(relation == "grandmother" || relation == "grandfather")
                    return 2; 
                else if()
            }
    };
}
