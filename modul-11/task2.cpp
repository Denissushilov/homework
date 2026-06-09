/*
    Задание 2: Программа проверки корректности email-адреса
    Программа, ...
    Имя файла: task2.cpp
*/
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

bool valid_email(const std::string email);
bool find_sign(const std::string str, const char ch, int& pos);

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
    return true;
}

bool find_sign(const std::string str, const char ch, int& pos)
{
    int counter{0};
    for(char wr_ch : str) {
        if(wr_ch == ch) {
            pos = counter;
            return true;
        }
        counter++;
    }
   
    pos = -1;
    return false;
}