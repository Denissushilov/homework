/*
    Задание 3: Валидация IP-адреса
    Имя файла: task3.cpp
*/
#include <iostream>
#include <string>

#include "mylibrary.hpp"

using std::cout;
using std::cin;
using std::endl;

bool valid_ip(const std::string& ip);
bool check_octet(const std::string& octet);

int main()
{
    std::string ip;

    cout << "Input IPv4 address: ";
    cin >> ip;
 
    cout << (valid_ip(ip) ? "Valid" : "Invalid") << endl;

    return 0;
}


bool check_octet(const std::string& octet)
{

    if (octet.empty()) return false;

    if (octet.size() > 3) return false;


    if (octet.size() > 1 && octet[0] == '0') return false;

    int value = 0;
    for (size_t i = 0; i < octet.size(); ++i) {
  
        if (octet[i] < '0' || octet[i] > '9') return false;
        
  
        value = value * 10 + (octet[i] - '0');
    }

    if (value < 0 || value > 255) return false;

    return true;
}

bool valid_ip(const std::string& ip)
{
    size_t start_pos = 0;
    int dot_pos = 0;
    int dot_count = 0;

    while (MyLib::find_sign(ip, '.', dot_pos, start_pos)) {
        dot_count++;

        if (dot_count > 3) return false;

        std::string octet = MyLib::sub(ip, start_pos, dot_pos);
        if (!check_octet(octet)) return false;

        start_pos = dot_pos + 1;
    }


    if (dot_count != 3) return false;

    std::string last_octet = MyLib::sub(ip, start_pos, ip.size());
    if (!check_octet(last_octet)) return false;

    return true;
}
