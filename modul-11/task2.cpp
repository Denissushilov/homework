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
bool find_sign(const std::string& str, const char ch, int& pos, size_t start=0);

int main()
{
    std::string email;

    cout << "Input your email address: ";
    cin >> email;
 
    int r;

    cout << find_sign(email, '@', r) << " " << r;
    //cout << (valid_email(email) ? "Yes" : "No");
  

    return 0;
}

bool valid_email(const std::string email)
{
    int dg;
    if(!find_sign(email, '@', dg))
        return false;
    //поделить substr(email, dg); и далее проверять обе части по отдельности так так валидации для них различаюся    
    return true;
}

bool find_sign(const std::string& str, const char ch, int& pos, size_t start)
{
    size_t len = str.size();
    if(start >= len) {
        pos = -1;
        return false;
    }
    
    for(size_t i = start; i < len; ++i) {
       
        if(str[i] == ch) {
            pos = static_cast<int>(i);
            return true;
        }
        
    }
   
    pos = -1;
    return false;
}