#include <iostream>
#include <string>

enum note
{
    DO = 1,  
    RE = 2, 
    MI = 4,  
    FA = 8,  
    SOL = 16,
    LA = 32, 
    SI = 64  
};

int main()
{
    std::string chord_str;
    std::cout << "Enter a chord (digits from 1 to 7, e.g., 1235): ";
    std::cin >> chord_str;

    int notes = 0; 
   
    for (int i = 0; i < chord_str.length(); ++i) {
        char ch = chord_str[i];

        if (ch >= '1' && ch <= '7') {
           
            int note_index = ch - '1'; 
          
            notes |= (1 << note_index);
        }
    }

    std::cout << "Playing: ";

    if (notes & DO)   std::cout << "DO ";
    if (notes & RE)   std::cout << "RE ";
    if (notes & MI)   std::cout << "MI ";
    if (notes & FA)   std::cout << "FA ";
    if (notes & SOL)  std::cout << "SOL ";
    if (notes & LA)   std::cout << "LA ";
    if (notes & SI)   std::cout << "SI ";

    std::cout << std::endl;

    return 0;
}
