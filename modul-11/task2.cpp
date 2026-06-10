/*
    Задание 2: Программа проверки корректности email-адреса
    Программа, ...
    Имя файла: task2.cpp
*/
#include <iostream>
#include <string>

#include "mylibrary.hpp"

using std::cout;
using std::cin;
using std::endl;

bool valid_email(const std::string email);


int main()
{
    std::string email;

    cout << "Input your email address: ";
    cin >> email;
 
  
    
    //cout << (valid_email(email) ? "Yes" : "No");
  

    return 0;
}

bool valid_email(const std::string email)
{
    int dg;
    if(!MyLib::find_sign(email, '@', dg))
        return false;
       
    return true;
}

