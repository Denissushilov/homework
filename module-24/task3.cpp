#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
#include <sstream>

int main()
{
    std::cout << "Enter timer duratiom (format MM:SS. e.g., 01:30): ";
    std::string input_str;
    std::cin >> input_str;

    std::tm input_tm = {};
    std::stringstream ss{input_str};

    if(!(ss >> std::get_time(&input_tm, "%M:%S"))) {
        std::cout << "Invalid time format! Use MM:SS.\n";
        return 1;
    }

    int total_seconds = input_tm.tm_min * 60 + input_tm.tm_sec;
    if(total_seconds <= 0) {
        std::cout << "Timer duration must be greater than zero.\n";
        return 1;
    }

    std::time_t start_time  = std::time(nullptr);
    std::time_t target_time = start_time + total_seconds;

    std::cout << "\nTimer started for " << input_tm.tm_min << " min " << input_tm.tm_sec << " sec.\n\n";

    std::time_t last_remaining = -1;

    while(true) {
        std::time_t current_time = std::time(nullptr);

        std::time_t remaining = target_time - current_time;

        if(remaining <= 0) break;

         if (remaining != last_remaining) {
            int display_min = static_cast<int>(remaining / 60);
            int display_sec = static_cast<int>(remaining % 60);

            std::cout << std::setfill('0') << std::setw(2) << display_min << ":"
                      << std::setfill('0') << std::setw(2) << display_sec << "\n";
            
            last_remaining = remaining;
        }
        
    }

    std::cout << "\nDING! DING! DING!\n";

    return 0;
}