#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

bool isValidDate(const std::string& date)
{
    if(date.length() != 10) return false;

    if(date[2] != '.' || date[5] != '.') return false;

    for(int i = 0; i < 10; ++i) {
        if(i == 2 || i == 5) continue;
        if(!isdigit(date[i])) return false;
    }

    int day = stoi(date.substr(0, 2));
    int month = stoi(date.substr(3, 2));
    int year = stoi(date.substr(6, 4));

    if(month < 1 || month > 12) return false;
    if(day < 1 || day > 31) return false;
    if(year < 1900 || year > 2100) return false;

    if((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return false;

    if(month == 2) {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) ||  (year % 400 == 0);
        if(isLeap && day > 29) return false;
        if(!isLeap && day > 28) return false;
    }

    return true;
}

int main()
{

    using std::ios;

    std::string firstName, lastName, date;
    int money{0};

    std::cout << "Entering a new entry in the statement" << std::endl;
    std::cout << "Enter first name: ";
    std::cin >> firstName;
    std::cout << "Enter last name: ";
    std::cin >> lastName;

    while(true) {
        std::cout << "Enter date (DD.MM.YYYY): ";
        std::cin >> date;

        if(isValidDate(date)) break;

        std::cout << "Error! wrong format od date. try again." << std::endl;
    }

    while(true) {
        std::cout << "Enter the payout amount (rubles): ";
        std::cin >> money;

        if(money <= 0) 
            std::cout << "Mistake! The sum must be a positive number. Try again." << std::endl;
        else
            break;
    }

    std::ofstream ofs("statement.txt", ios::app);

    if(ofs.is_open()) {
        ofs << firstName << " " << lastName << " " << date << " " << money << std::endl;
        ofs.close();
        std::cout << "\nThe record has been successfully added to the list!" << std::endl;
    } else std::cout << "Error opening the bulletin file!" << std::endl;

    return 0;
} 