#include "FamilyTree.hpp"

namespace family {

    // father is always right 
    Tree& Tree::addFather(std::string name, std::string father) {
        Node* n = (Node*)(this->search(name));
        if(n->getRight() == nullptr){
            n->setRight(new Node(father, n->getLevel() + 1));
            n->getRight()->setChild(n);
            n->getRight()->setGender('m');
        }
        else
            throw std::runtime_error("Father is already defined");
        return *this;
    }

    // mother is left
    Tree& Tree::addMother(std::string name, std::string mother) {
        Node* n = (Node*)(this->search(name));
        if(n->getLeft() == nullptr) {
            n->setLeft(new Node(mother, n->getLevel() + 1));
            n->getLeft()->setChild(n);
            n->getLeft()->setGender('f');
        }
        else
            throw std::runtime_error("Mother is already defined");
        return *this;
    }
    
    std::string Tree::relation(std::string name) {
        Node* n = nullptr;
        try{
            n = (Node*)(this->search(name));
        } catch(const std::exception& ex){
            return "unrelated";
        }
        unsigned int levelDiffer = n->getLevel() - this->root->getLevel();
        if(levelDiffer == 0)
            return "me";
        else if(n->getGender() == 'f')
            return this->print_relation(levelDiffer, "mother");   
        else
            return this->print_relation(levelDiffer, "father");
    }

    std::string Tree::find(std::string relation) {

        return "";
    }

    void Tree::display() {
        std::cout << root->getName() << std::endl;
        printSubtree(root, "");
        std::cout << std::endl;
    }        

    void Tree::remove(std::string name) {

        if(name == this->root->getName())
            throw std::runtime_error("Can not remove the root!");

        Node* n = (Node*)(this->search(name));
        Node* n_child = n->getChild();

        if(n_child->getLeft() != nullptr && n_child->getLeft()->getName() == name)
            n_child->setLeft(nullptr);
        else
            n_child->setRight(nullptr);

        n = this->destroy_family(n);

        //if trying to remove someone that is not on the tree- throw an error!
    }



    







}