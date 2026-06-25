#include <iostream>
#include <fstream>
#include <string>

const size_t BUFFER_SIZE{4096};

int main()
{
    using std::ios;
    std::string path;

    std::cout << "Enter the path to the file: ";
    std::getline(std::cin, path);

    std::ifstream ifs(path, ios::binary);

    if(!ifs.is_open()) {
        std::cout << "Error: file wasn't opened" <<std::endl;
        return 1;
    }

    char buffer[BUFFER_SIZE];

    while(ifs.read(buffer, BUFFER_SIZE) || ifs.gcount() > 0) {
        size_t bytesRead = ifs.gcount();

        std::cout.write(buffer, bytesRead);
    }

    ifs.close();

    
    std::cout << std::endl << "--- End of File ---" << std::endl;

    return 0;
}