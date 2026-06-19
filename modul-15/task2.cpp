#include <iostream>
#include <string>

std::string catStr(std::string int_part, std::string fract_part)
{
    std::string f{}, s{};
    

    int i = 0;
    while(i < int_part.length() && std::isdigit(int_part[i])) { 
        f += int_part[i]; 
        ++i;
    }
    
    i = 0;
    while(i < fract_part.length() && std::isdigit(fract_part[i])) { 
        s += fract_part[i]; 
        ++i;
    }

    if (f.empty()) f = "0";
    if (s.empty()) s = "0";

    return f + "." + s;
}

int main()
{
    std::string int_part, fract_part;

    std::cout << "Enter intenger part and fractional part in space(II FF): ";
    std::cin >> int_part >> fract_part;

    std::string full_num = catStr(int_part, fract_part);

    double result = std::stod(full_num);

    std::cout << "Result: " << result << std::endl;

    return 0;
}