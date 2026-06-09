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
    int dg;
    if(!find_sign(email, '@', dg) || dg >= 65 || !dg)
        return false;
    //поделить substr(email, dg); и далее проверять обе части по отдельности так так валидации для них различаюся    
    return true;
}

bool find_sign(const std::string str, const char ch, int& pos)
{
    int counter{0};
    for(char wr_ch : str) {
        counter++;
        if(wr_ch == ch) {
            pos = counter;
            return true;
        }
        
    }
   
    
    return false;
}