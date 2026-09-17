#include "../include/contact.h"

Contact::Contact(const std::string& in_name, const std::string& in_number)
: name(in_name), phone_number(in_number) {}

std::string  Contact::get_name() const { return name; }
std::string Contact::get_phone_number() const { return phone_number; }