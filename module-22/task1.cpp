#include <iostream>
#include <string>
#include <map>
#include <vector>

bool isNumber(const std::string& str) 
{
    if(str.empty()) return false;

    return std::isdigit(str[0]);
}

int main()
{
    std::map<std::string, std::string> phone_to_name;
    std::map<std::string, std::vector<std::string>> name_to_phones;

    std::cout << "Enter the command (press Ctrl+C to exit):\n";

    std::string input;

    while(std::getline(std::cin, input)) {
        if(input.empty()) continue;

        size_t space_pos = input.find(' ');

        if(space_pos != std::string::npos) {
            std::string phone = input.substr(0, space_pos);
            std::string name = input.substr(space_pos + 1);

            phone_to_name[phone] = name;
            name_to_phones[name].push_back(phone);
        } else {
            if(isNumber(input)) {
                auto it = phone_to_name.find(input);
                if(it != phone_to_name.end()) {
                    std::cout << it->second << "\n";
                } else {
                    std::cout << "The number is not found!\n";
                }
            } else {
                auto it = name_to_phones.find(input);
                if(it != name_to_phones.end()) {
                    for(size_t i = 0; i < it->second.size(); ++i) {
                        std::cout << it->second[i];
                        if(i+1 < it->second.size()) {
                            std::cout << " ";
                        }
                    }
                    std::cout << "\n";
                } else {
                   
                    std::cout << "Abonent is not found!\n"; 
                }
            } 
        }
    }

    return 0;
}
