/*
    Задание 2: Программа проверки корректности email-адреса
    Имя файла: task2.cpp
*/
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

bool find_sign(const std::string& str, const char ch, int& pos, size_t start=0);
std::string sub(const std::string& str, unsigned start, unsigned end);
bool valid_email(const std::string& email);
bool check_part(std::string& part, bool is_local);

int main()
{
    std::string email;

    cout << "Input your email address: ";
    cin >> email;
 
  
    
    cout << (valid_email(email) ? "Yes" : "No");
  

    return 0;
}

bool check_part(std::string& part, bool is_local)
{
    size_t len = part.size();
    size_t normal_len = (is_local ? 64 : 63);

    if(len < 1 || len > normal_len) return false;

    if (part.front() == '.' || part.back() == '.') return false;

    std::string specs_syms = "!#$%&'*+-/=?^_`{|}~";

    for(size_t i = 0; i < len; ++i) {
        char ch = part[i];

        if (ch == '.' && i + 1 < len && part[i + 1] == '.')  return false;

        bool is_alnum = (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
        bool is_base_spec = (ch == '-') || (ch == '.');

        if(is_alnum || is_base_spec) continue;

        if(is_local) {
            int dum_pos;

            if(find_sign(specs_syms, ch, dum_pos)) continue;
        }

        return false;
    }

    return true;
    
}

bool valid_email(const std::string& email)
{
    int at_pos;
    if(find_sign(email, '@', at_pos) || !at_pos) return false;
    int second_pos;

    if(find_sign(email, '@', second_pos, at_pos+1)) return false;

    std::string local = sub(email, 0, at_pos);
    std::string domen = sub(email, at_pos+1, email.size());

    
    if(!check_part(local, true) || !check_part(domen, false)) return false;
   
       
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

std::string sub(const std::string& str, unsigned start, unsigned end)
{
    size_t len = str.size();
    
    if(start >= end)
        return "";

    
    end = (end > len ? len : end); 
    
    std::string result(end - start, ' ');
    for(size_t i = 0; start < end; ++start, ++i)
        result[i] = str[start];
    
    return result;    
}
