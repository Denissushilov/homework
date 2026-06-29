#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

const int NUM_DENOMINATIONS{6};
const int NOMINALS[NUM_DENOMINATIONS] = {5000, 2000, 1000, 500, 200, 100};
const int MAX_TOTAL_BANKNOTES = 1000;
const char *FILE_NAME = "atm_state.bin";

int countTotalBanknotes(const int countArray[])
{
    int total{0};

    for(int i = 0; i < NUM_DENOMINATIONS; ++i) {
        total += countArray[i];
    }
    return total;
}

void printATMState(const int countArray[])
{
    unsigned long long totalAmount{0};
    std::cout << "\nCURRENT ATM STATE" << std::endl;

    for(int i = 0; i < NUM_DENOMINATIONS; ++i) {
        std::cout << NOMINALS[i] << " RUB: " << countArray[i] << " banknotes" << std::endl;
        totalAmount += static_cast<unsigned long long>(countArray[i]) * NOMINALS[i];
    }
    std::cout << "Total amount in ATM: " << totalAmount << " RUB" << std::endl;
    std::cout << "Total banknotes: " << countTotalBanknotes(countArray) << " / " << MAX_TOTAL_BANKNOTES << std::endl;
    std::cout << "-------------------------" << std::endl;
}

int main()
{
    using std::ios;
    std::srand(std::time(nullptr));

    int banknotesCount[NUM_DENOMINATIONS] {0};

    std::ifstream inFile(FILE_NAME, ios::binary);

    if(inFile.is_open()) {
        inFile.read(reinterpret_cast<char*>(banknotesCount), sizeof(banknotesCount));
        inFile.close();
        std::cout << "ATM state loaded successfully." << std::endl;
        printATMState(banknotesCount);
    } else {
        std::cout << "ATM file not found. ATM is currently EMPTY." << std::endl;
    }

    std::string command;

    while(true) {
        std::cout << "\nEnter command ('+' to fill, '-' to withdraw, 'exit' to quit): ";
        std::cin >> command;

        if(command == "exit") break;

        if(command == "+") {
            int currentTotal = countTotalBanknotes(banknotesCount);
            if(currentTotal >= MAX_TOTAL_BANKNOTES) {
                std::cout << "ATM is already full!" << std::endl;
                continue;
            }

            int banknotesNeeded = MAX_TOTAL_BANKNOTES - currentTotal;
            std::cout << "Filling ATM with " << banknotesNeeded << " random banknotes..." << std::endl;

            for(int i = 0; i < banknotesNeeded; ++i) {
                int randomIndex = std::rand() % NUM_DENOMINATIONS;
                ++banknotesCount[randomIndex];
            }
            printATMState(banknotesCount);
        } else if(command == "-") {
            int amount{0};
            std::cout << "Enter the amount to withdraw (multiple of 100): ";
            std::cin >> amount;

            if(amount <= 0 || amount % 100 != 0) {
                std::cout << "Error! the amount must be a positive multiple of 100." << std::endl;
                continue;
            }

            int tempCount[NUM_DENOMINATIONS];
            for(int i = 0; i < NUM_DENOMINATIONS; ++i)
                tempCount[i] = banknotesCount[i];

            int remainingAmount = amount;
            
            for(int i = 0; i < NUM_DENOMINATIONS; ++i) {
                if(remainingAmount >= NOMINALS[i]) {
                    int needed = remainingAmount / NOMINALS[i];
                    int actualToGive = (needed < tempCount[i] ? needed : tempCount[i]);

                    remainingAmount -= actualToGive * NOMINALS[i];
                    tempCount[i] -= actualToGive;
                }
            }

            if(remainingAmount == 0) {
                for(int i = 0; i < NUM_DENOMINATIONS; ++i) {
                    banknotesCount[i] = tempCount[i];
                }
                std::cout << "Success! Please take your money." << std::endl;
                printATMState(banknotesCount);
            } else {
                std::cout << "Error! Cannot withdraw this amount. Not enough suitable banknotes in ATM." << std::endl;
            }
        } else {
             std::cout << "Unknown command! Use '+', '-' or 'exit'." << std::endl;
        }
    }

    std::ofstream outFile(FILE_NAME, ios::binary);
    if (outFile.is_open()) {
        outFile.write(reinterpret_cast<const char*>(banknotesCount), sizeof(banknotesCount));
        outFile.close();
        std::cout << "ATM state saved successfully. Goodbye!" << std::endl;
    } else {
        std::cout << "Error saving ATM state to file!" << std::endl;
    }



    return 0;
}