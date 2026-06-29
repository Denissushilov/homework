#include <iostream>
#include <fstream>
#include <string>

int main()
{
    using std::ios;

    std::string targetFish;
    std::cout << "FISHING SIMULATOR" << std::endl;
    std::cout << "What fish are you going to catch?: ";
    std::cin >> targetFish;

    std::ifstream riverFile("river.txt");

    if(!riverFile.is_open()) {
        std::cout << "Error! The river file (river.txt) was not found." << std::endl;
        return 1;
    }

    std::ofstream basketFile("basket.txt", ios::app);

    if(!basketFile.is_open()) {
        std::cout << "Error! Could not open or create the basket file (basket.txt)." << std::endl;
        return 1;
    }

    std::string currentFish;
    int catchCount{0};

    while(riverFile >> currentFish) {
        if(currentFish == targetFish) {
            basketFile << currentFish << std::endl;
            ++catchCount;
        }
    }

    riverFile.close();
    basketFile.close();

    std::cout << "\nFishing is over!" << std::endl;
    std::cout << "You caught " << catchCount << " " << targetFish << "(s) this time." << std::endl;
    

    return 0;
}