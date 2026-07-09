#include <iostream>
#include <string>
#include <map>

bool isAnagram(const std::string& str1, const std::string& str2)
{
    if(str1.length() != str2.length()) 
        return false;

    std::map<char, int> count1, count2;
        
    for(char ch : str1) {
        count1[ch]++;
    }

    for(char ch : str2) {
        count2[ch]++;
    }

    return count1 == count2;
    
}

int main()
{
    std::string word1, word2;
    std::cout << "Enter two words to check for anagram:\n";
    
    if (std::cin >> word1 >> word2) {
        if (isAnagram(word1, word2)) {
            std::cout << "true (They are anagrams)\n";
        } else {
            std::cout << "false (They are not anagrams)\n";
        }
    }

    return 0;
}