#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct PaymentRecord {
    std::string firstName;
    std::string lastName;
    std::string date;
    int money{0};
};

int main()
{
    using std::ios;

    std::string command;

    std::cout << "STATEMENT MANAGER" << std::endl;
    std::cout << "Enter command (list/add): ";
    std::cin >> command;

    if(command == "list") {
        std::ifstream inFile("statement.txt");

        if(!inFile.is_open()) {
            std::cout << "Error! The statement file does not exist yet." << std::endl;
            return 1;
        }

        std::vector<PaymentRecord> records;

        while(true) {
            PaymentRecord tempRecord;
            inFile >> tempRecord.firstName;

            if(inFile.eof()) break;

            inFile >> tempRecord.lastName >> tempRecord.date >> tempRecord.money;

            records.push_back(tempRecord);
        }

        inFile.close();

        std::cout << "\nCURRENT STATEMENT RECORDS" << std::endl;
        
        for(const auto& record: records) {
            std::cout << record.firstName << " "
                      << record.lastName << " "
                      << record.date << " "
                      << record.money << " RUB" << std::endl;
        }

        std::cout << "-------------------------------------------" << std::endl;    
    } else if(command == "add") {
        PaymentRecord newRecord;

        std::cout << "Enter first name: ";
        std::cin >> newRecord.firstName;
        std::cout << "Enter last name: ";
        std::cin >> newRecord.lastName;
        std::cout << "Enter date (DD.MM.YYYY): ";
        std::cin >> newRecord.date;
        std::cout << "Enter amount (rubles): ";
        std::cin >> newRecord.money;

        std::ofstream outFile("statement.txt", ios::app);

        if(outFile.is_open()) {
            outFile << newRecord.firstName << " " 
                    << newRecord.lastName << " " 
                    << newRecord.date << " " 
                    << newRecord.money << std::endl;

            outFile.close();
            std::cout << "\nRecord successfully added using structures!" << std::endl;

        } else {
           
            std::cout << "Error opening file for writing!" << std::endl; 
        }

    } else {
        
        std::cout << "Unknown command! Use 'list' or 'add'." << std::endl;
    }
    

    return 0;
}
