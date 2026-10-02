#include "../include/Branch.h"
#include <iostream>
#include <cstdlib>

Branch::Branch(Branch* parentBranch) : parent(parentBranch) {}

Branch::~Branch()
{
    for(auto* child : children)
        delete child;
}

void Branch::setElfName(const std::string& name)
{
    elfName = name;
}

std::string Branch::getElfName() const
{
    return elfName;
}

void Branch::addChild(Branch* child)
{
    children.push_back(child);
}

const std::vector<Branch*>& Branch::getChildren() const
{
    return children;
}

void Branch::populate()
{
    if(parent != nullptr) {
        std::string name;
        std::cout << "Enter the elf's name to be populated (or None): ";
        std::getline(std::cin, name);
        if (name.empty() || name == "None") {
            setElfName("None"); 
        } else {
            setElfName(name);
        }
    }

    for(auto* child : children)
        child->populate();
}

Branch* Branch::findElfBranch(const std::string& name)
{
    if(this->elfName == name || name == "None")
        return this;

    for(auto* child : children) {
        Branch* found = child->findElfBranch(name);
        if(found != nullptr)
            return found;
    }
    return nullptr;
}

Branch* Branch::getTopBranch()
{
    if(this->parent == nullptr) return nullptr;
    if(this->parent->parent == nullptr) return this;

    return this->parent->getTopBranch();
}

int Branch::countElfs() const
{
    int count = 0;
    if(this->elfName != "None")
        count = 1;

    for(const auto* child : children) 
        count += child->countElfs();
    return count;   
}