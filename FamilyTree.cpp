#include "FamilyTree.hpp"






namespace family {

    // father is always right 
    Tree Tree::addFather(std::string name, std::string father) {
        Node* child = (Node*)(this->search(name));
        if(child->getRight() == nullptr)
            child->setRight(new Node(father, child->getLevel() + 1));
        else
            throw std::runtime_error("Father is already defined");

        return *this;
    }

    Tree Tree::addMother(std::string name, std::string mother) {
        Node* child = (Node*)(this->search(name));
        if(child->getLeft() == nullptr)
            child->setLeft(new Node(mother, child->getLevel() + 1));
        else
            throw std::runtime_error("Mother is already defined");

        return *this;
    }
    std::string Tree::relation(std::string name) {
        return "";
    }
    std::string Tree::find(std::string relation) {
        return "";
    }
    void Tree::display() {

    }        
    void Tree::remove(std::string name) {

    }



    







}