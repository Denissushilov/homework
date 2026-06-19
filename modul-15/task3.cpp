#include <iostream>
#include <string>
#include <sstream>

int main()
{
    std::string buffer;

    std::cout << "Enter expression (e.g., 10.5+2.3): ";
    std::cin >> buffer;

    std::stringstream buffer_stream(buffer);

    double a = 0.0;
    char operation = 0;
    double b = 0.0;

    if(buffer_stream >> a >> operation >> b) {
        double result = 0.0;
        bool valid_op = true;

        switch(operation) {
            case '+':
            result = a + b;
            break;
            case '-':
            result = a - b;
            break;
            case '*':
            result = a * b;
            break;
            case '/':
            if(b != 0.0) {
                result = a / b;
            } else {
                std::cout << "Error: Division by zero!" << std::endl;
                valid_op = false;
            } break;

            default:
            std::cout << "Error: Invalid operation '" << operation << "'" << std::endl;
            valid_op = false;
            break;
        }

        if(valid_op) {
            std::cout << "Result: " << result << std::endl;
        }
    } else {
            std::cout << "Error: Invalid expression format!" << std::endl;
        }

    return 0;
}