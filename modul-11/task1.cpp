/*
    Задание 1: Шифр Цезаря
    Программа, введёную ширует строку
    Имя файла: task1.cpp
*/
#include <iostream>
#include <string>
#include <cctype>

void encrypt_caesar(std::string& str, int shift);

using std::cout;
using std::cin;
using std::endl;

int main()
{

    std::string str;
    int shift;
    cout << "Enter text: ";
    getline(cin, str);

    cout << "Enter shift: ";
    cin >> shift;

    encrypt_caesar(str, shift);

    cout << "Your cipher: " << str;
   

    return 0;
}

void encrypt_caesar(std::string& str, int shift)
{
    shift = (shift% 26 + 26) % 26;

    for(char& ch: str) {
        if(isalpha(ch)) {
            char base = (isupper(ch) ? 'A' : 'a');

            ch = base + (ch - base + shift) % 26;
        }
    }
}

