#pragma once
#include "address_book.h"
#include <string>

class Phone {
private:
    AddressBook address_book;
    
    bool is_valid_number(const std::string& number) const;

public:
    void add_contact_command();
    void call_command();
    void sms_command();    
};