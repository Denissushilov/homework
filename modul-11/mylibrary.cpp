#include "mylibrary.hpp"


namespace MyLib
{

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
    
}