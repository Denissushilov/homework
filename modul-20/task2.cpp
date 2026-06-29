#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(nullptr));

    int width{0}, height{0};

    std::cout << "BINARY PICTURES GENERATOR" << std::endl;

    while(true) {
        std::cout << "Enter picture width (pixels): ";
        std::cin >> width;
        std::cout << "Enter picture height (pixels): ";
        std::cin >> height;

        if(width > 0 && height > 0) break;

        std::cout << "Error! Dimensions must be greater than 0. Try again.\n" << std::endl;
    }

    std::ofstream outPic("pic.txt");

    if(outPic.is_open()) {
        for(int i = 0; i < height; ++i) {
            for(int j = 0; j < width; ++j) {
                outPic << std::rand() % 2;
            }
            outPic << std::endl;
        }
        outPic.close();
        std::cout << "\nThe picture has been successfully saved to 'pic.txt'!" << std::endl;
    } else {
        std::cout << "Error! Could not create file 'pic.txt'." << std::endl;
    }

    return 0;
}