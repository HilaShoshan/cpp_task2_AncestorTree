#pragma once

#include <iostream>

namespace family {


    class Tree {

        class Node {
            std::string name; 
            Node* left;
            Node* right;

            public:
                // constructor
                Node(std::string name){
                    this->name = name;
                    this->left = nullptr;
                    this->right = nullptr;
                }
        };

        Node* root = nullptr;

        public:
            Tree addFather(std::string name, std::string father);
            Tree addMother(std::string name, std::string mother);
            std::string relation(std::string name);
            std::string find(std::string relation);
            void display();
            void remove(std::string name);
            
            // constructor
            Tree(std::string name) {
                this->root = new Node(name);
            }
            ~Tree() {
                destroy_family(root);
            }

            void destroy_family(Node* current){
                if(current != nullptr){
                    destroy_family(current->left);
                    destroy_family(current->right);
                    delete current;
                }
            }
    };
}
