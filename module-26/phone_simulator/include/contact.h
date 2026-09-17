#pragma once
#include <string>

class Contact {
private:
    std::string name;
    std::string phone_number;
    
public:
    Contact(const std::string& in_name, const std::string& in_number);
    
    std::string get_name() const;
    std::string get_phone_number() const;
};