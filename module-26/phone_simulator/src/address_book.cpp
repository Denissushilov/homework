#include "../include/address_book.h"

void AddressBook::add_contact(const std::string& name, const std::string& phone_number)
{
    contacts.push_back(Contact(name, phone_number));
}

std::string AddressBook::find_number_by_name(const std::string& name) const
{
    for(const auto& contact : contacts)
        if(contact.get_name() == name) return contact.get_phone_number();
    
    return "";    
}

bool AddressBook::has_contact(const std::string& name) const
{
    return !find_number_by_name(name).empty();
}