#include <iostream>
#include <string>
#include <map>

int main()
{
    std::map<std::string, int> registry;

    std::string input;

    while(std::cin >> input) {
        if(input == "Next") {
            if(registry.empty()) {
                std::cout << "Queue is empty\n";
            } else {
                auto it = registry.begin();

                std::cout << it->first << "\n";

                it->second--;

                if(it->second == 0) {
                    registry.erase(it);
                }
            }
        } else {
            registry[input]++;
        }
    }

    return 0;
}