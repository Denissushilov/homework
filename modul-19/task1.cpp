#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

int main()
{
    std::string searchWord;

    std::cout << "Enter word to search: ";
    std::cin >> searchWord;

    for(char &c : searchWord)
        c = std::tolower(c);

    std::ifstream ifs("words.txt");

    if(!ifs.is_open()) {
        std::cout << "Error: file wasn't opened" << std::endl;
        return 1;
    }

    std::string currentWord;
    unsigned count{0};

    while(ifs >> currentWord) {
        while(!currentWord.empty() && ispunct(currentWord.back())) currentWord.pop_back();
        while(!currentWord.empty() && ispunct(currentWord.front())) currentWord.erase(0, 1);

        for(char &c : currentWord)
            c = std::tolower(c);

        if(currentWord == searchWord) count++;
    }

    ifs.close();

    std::cout << "Count of your word: " << count << std::endl;

    return 0;
}