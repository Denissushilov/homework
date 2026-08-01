#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <ctime>
#include <sstream>

class Friend {
    std::string name;
    unsigned short month{0};
    unsigned short day{1};

public:
    Friend(std::string name = "", unsigned short month = 0, unsigned short day = 1) 
        : name(name), month(month), day(day) {}


    Friend(const Friend& other)
        : name(other.name), month(other.month), day(other.day) {}

    Friend& operator=(const Friend& other) {
        if (this == &other) return *this;

        this->name = other.name;
        this->month = other.month;
        this->day = other.day;

        return *this;
    }

    std::string get_name() const { return name; }
    unsigned short get_month() const { return month; }
    unsigned short get_day() const { return day; }
};


int main()
{
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);

    int current_month{now->tm_mon}, current_day{now->tm_mday};

    std::vector<Friend> friends;
    std::cout << "Enter friends' birthdays (format: YYYY/MM/DD). Type 'end' to finish.\n";

    while(true) {
        std::cout << "Name: ";
        std::string name;
        std::cin >> name;

        if(name == "end") break;

        std::cout << "Birthday (YYYY/MM/DD): ";
        std::string date_str;
        std::cin >> date_str;

        std::stringstream ss(date_str);
        int year, month, day;
        char slash1, slash2;

        if(ss >> year >> slash1 >> month >> slash2 >> day && slash1 == '/' && slash2 == '/') {
            friends.push_back({name, month-1, day});
        } else {
            std::cout << "Invalid date format! Try again!\n";
        }
    }

    bool anyone_today{false};
    for(const auto& f: friends) {
        if(f.get_month() == current_month && f.get_day() == current_day) {
            std::cout << "Special notice: Today is " << f.get_name() << "'s birthday!\n";
            anyone_today = true;
        }
    }

    Friend closest_friend;
    bool found_future{false};

    int min_days_until{366};

    for(const auto& f: friends) {
        if(f.get_month() < current_month || (f.get_month() == current_month && f.get_day() < current_day))
            continue;
        
        if(f.get_month() == current_month && f.get_day() == current_day)
            continue;
            
        std::tm birthday_tm = *now;
        birthday_tm.tm_mon = f.get_month();
        birthday_tm.tm_mday = f.get_day();
        birthday_tm.tm_hour = 0;
        birthday_tm.tm_min = 0;
        birthday_tm.tm_sec = 0;
        
        std::time_t birthday_time = std::mktime(&birthday_tm);

        double diff_seconds = std::difftime(birthday_time, t);
        int days_until = static_cast<int>(diff_seconds / (60 * 60 * 24)) + 1;
        
        if(days_until < min_days_until) {
            min_days_until = days_until;
            closest_friend = f;
            found_future = true;
        }
    }

      if (found_future) {
        std::cout << "\nClosest upcoming birthday:\n";
        std::cout << closest_friend.get_name() << " - " 
                  << std::setfill('0') << std::setw(2) << (closest_friend.get_month() + 1) << "/" 
                  << std::setfill('0') << std::setw(2) << closest_friend.get_day() << "\n";
    } else if (!anyone_today) {
        std::cout << "\nNo upcoming birthdays found in this year.\n";
    }

    return 0;
}