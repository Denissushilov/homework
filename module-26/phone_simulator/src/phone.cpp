#include "../include/phone.h"
#include <iostream>

bool Phone::is_valid_number(const std::string& number) const
{
    if(number.length() != 12 || number.substr(0, 2) != "+7")
        return false;

    for(size_t i{2}; i < 12; ++i)
        if(!std::isdigit(number[i])) 
            return false;
            
    return true;        
}

void Phone::add_contact_command()
{
    std::string name, number;
    std::cout << "Enter contact name: ";
    std::cin >> name;

    std::cout << "Enter phone number (+7XXXXXXXXXXX): ";
    std::cin >> number;

    if(!is_valid_number(number))
    {
        std::cout << "[Error] Invalid format! Number must be +7 followed my 10 digits.\n";
        return;
    }

    address_book.add_contact(name, number);
    std::cout << "[Success] Contact '" << name <<"' added successfully.\n";
}

void Phone::call_command()
{
    std::string query;
    std::cout << "Enter name or phone number to call: ";
    std::cin >> query;

    std::string target_number = query;

    if(!is_valid_number(query))
    {
        target_number = address_book.find_number_by_name(query);
        if(target_number.empty())
        {
            std::cout << "[Error] Contact not found and it is not a valid number.\n";
            return;
        }
    }

    std::cout << "[CALL] " << target_number << "\n";
}

void Phone::sms_command()
{
    std::string query, message;
    std::cout << "Enter name or phone number to send SMS: ";
    std::cin >> query;

    std::string target_number = query;

    if(!is_valid_number(query))
    {
        target_number = address_book.find_number_by_name(query);
        if(target_number.empty())
        {
            std::cout << "[Error] Contanct not found and it is not a valid number.\n";
            return;
        }
    }

    std::cout << "Enter SMS message: ";
    std::cin.ignore();
    std::getline(std::cin, message);

    std::cout << "SMS SENT TO " << target_number << ": \"" << message <<"\"\n";
}