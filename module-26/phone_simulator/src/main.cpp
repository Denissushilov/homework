#include "../include/phone.h"
#include <iostream>
#include <string>

int main()
{
    Phone my_phone;
    std::string command;

    std::cout << "== Mobile Phone simulator ==\n";
    std::cout << "Available commands: add, call, sms, exit\n\n";

    while(true) {
        std::cout << "Enter command: ";
        std::cin >> command;


        if (command == "exit") {
            std::cout << "Turning off the phone...\n";
            break;
        } else if (command == "add") {
            my_phone.add_contact_command();
        } else if (command == "call") {
            my_phone.call_command();
        } else if (command == "sms") {
            my_phone.sms_command();
        } else {
            std::cout << "Unknown command. Try again.\n";
        }
        std::cout << "-------------------------------------\n";

    }

    return 0;
}