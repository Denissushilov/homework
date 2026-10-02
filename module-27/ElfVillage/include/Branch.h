#pragma once
#include <string>
#include <vector>

class Branch {
private:
    std::string elfName {"None"};
    Branch *parent {nullptr};
    std::vector<Branch*> children;
    
public:
    Branch(Branch*);
    
    ~Branch();

    void setElfName(const std::string&);
    std::string getElfName() const;

    void generateSubtree();

    void addChild(Branch*);
    const std::vector<Branch*>& getChildren() const;

    void populate();

    Branch* findElfBranch(const std::string&);

    Branch* getTopBranch();

    int countElfs() const;
};