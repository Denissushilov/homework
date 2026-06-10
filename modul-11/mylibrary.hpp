#ifndef MYLIBRARY_HPP
#define MYLIBRARY_HPP

#include <string>

namespace MyLib
{

bool find_sign(const std::string& str, const char ch, int& pos, size_t start=0);
std::string sub(const std::string& str, unsigned start, unsigned end);
    
}


#endif

