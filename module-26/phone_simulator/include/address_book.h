#pragma once
#include "contact.h"
#include <vector>
#include <string>

class AddressBook {
private:
    std::vector<Contact> contacts;

public:
    void add_contact(const std::string& name, const std::string& phone_number);

    std::string find_number_by_name(const std::string& name) const;

    bool has_contact(const std::string& name) const;
};