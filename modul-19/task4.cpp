#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

int main()
{

    using std::ios;

    std::string path;

    std::cout << "Enter the path to file: ";
    std::getline(std::cin, path);

    bool pngExtension{false};

    if(path.length() >= 4) {
        std::string ext = path.substr(path.length() - 4, 4);

        for(char& c: ext) c = std::tolower(c);

        if(ext == ".png") pngExtension = true;
    }

    if(!pngExtension) {
        std::cout << "Result: This is NOT a PNG file (invalid etension)." << std::endl;
        return 0;
    }

    std::ifstream ifs(path, ios::binary);

    if(!ifs.is_open()) {
        std::cout << "Error: file wasn't opened!" << std::endl;
        return 1;
    }

    signed char header[4];
    ifs.read(reinterpret_cast<char*>(header), 4);

    if(ifs.gcount() < 4) {
        std::cout << "Result: This is not png file (file is too small)." << std::endl;
        ifs.close();
        return 0;
    }

    if(header[0] == -119 && 
        header[1] == 'P' && 
        header[2] == 'N' && 
        header[3] == 'G') {
        std::cout << "Result: This is a VALID PNG file!" << std::endl;
    } else {
        std::cout << "Result: This is NOT a PNG file (invalid header signature)." << std::endl;
    }
    ifs.close();

    return 0;
}