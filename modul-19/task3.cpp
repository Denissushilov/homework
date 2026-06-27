#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream ifs("payments.txt");

    if(!ifs.is_open()) {
        std::cout << "Error: file wasn't opened!" << std::endl;
        return 1;
    }

    std::string name, surname, date;
    unsigned amount{0};

    long long totalAmount{0};
    unsigned maxAmount{0};
    std::string maxName, maxSurname;

    while(ifs >> name >> surname >> amount >> date) {
        totalAmount += amount;

        if(amount > maxAmount) {
            maxAmount = amount;
            maxName = name;
            maxSurname = surname;
        }
    }

    ifs.close();

    std::cout << "Total amount of payments: " << totalAmount << std::endl;
    if (maxAmount != 0) {
        std::cout << "Highest paid person: " << maxName << " " << maxSurname 
                  << " with " << maxAmount << std::endl;
    } else {
        std::cout << "The file was empty." << std::endl;
    }

    return 0;
}