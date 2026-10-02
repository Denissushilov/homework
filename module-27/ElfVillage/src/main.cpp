#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "../include/Branch.h"

int main()
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    std::cout << "Welcome to the elf village!\n";
    std::cout << "Generation of a forest area consisting of 5 trees...\n\n";

    std::vector<Branch*> forest;

    for(int i = 0; i < 5; ++i) {
        Branch* tree = new Branch(nullptr);

        int bigBranchesCount = 3 + std::rand() % 3;

        for(int j = 0; j < bigBranchesCount; ++j) {
            Branch* bigBranch = new Branch(tree);
            tree->addChild(bigBranch);

            int midBranchesCount = 2 + std::rand() % 2;
            for(int k = 0; k < midBranchesCount; ++k) {
                Branch* midBranch = new Branch(bigBranch);
                bigBranch->addChild(midBranch);
            }
        }
        forest.push_back(tree);
    }

    for(int i = 0; i < 5; ++i) {
        std::cout << "Settlement of Tree N " << i+1 << "\n";
        forest[i]->populate();
    }

    std::cout << "\n========================================\n";
    std::string searchName;
    std::cout << "Enter the elf's name to search for neighbors: ";
    std::getline(std::cin, searchName);

    Branch* elfBranch = nullptr;
    for(int i = 0; i < 5; ++i) {
        elfBranch = forest[i]->findElfBranch(searchName);
        if(elfBranch != nullptr)
            break;
    }

    if(elfBranch == nullptr || searchName == "None") {
        std::cout << "Elf named " << searchName << " is not found in village.\n";
    } else {
        Branch* topBranch = elfBranch->getTopBranch();  

        if(topBranch != nullptr) {
            int totalOnbigBranch = topBranch->countElfs();
            int neighborsCount = totalOnbigBranch - 1;

            std::cout << "Elf " << searchName << " is found!\n";
            std::cout << "his neighbors count is " << neighborsCount << "\n";
        } else {
            std::cout << "Tree structure error.\n";
        }
    }

    for(auto* tree : forest)
        delete tree;

    std::cout << "\nThe program has been completed.\n";
    return 0;
}