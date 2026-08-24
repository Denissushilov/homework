#include "../include/surgery.h"
#include <iostream>
#include <string>

int main() {
    std::string command;
    bool operation_started = false;
    

    Point cut_start;
    Point cut_end;

    std::cout << "=== Surgery Simulator ===\n";
    std::cout << "Available commands: scalpel, hemostat, tweezers, suture\n\n";

    while (true) {
        std::cout << "Enter command: ";
        std::cin >> command;

        if (command == "scalpel") {
            std::cout << "Cut start. ";
            Point start = input_point();
            std::cout << "Cut end. ";
            Point end = input_point();

            scalpel(start, end);

            if (!operation_started) {
                cut_start = start;
                cut_end = end;
                operation_started = true;
                std::cout << "The operation has successfully started!\n";
            }
        } 
        else if (command == "hemostat") {
            if (!operation_started) {
                std::cout << "Error! You must make a cut (scalpel) first.\n";
                continue;
            }
            Point p = input_point();
            hemostat(p);
        } 
        else if (command == "tweezers") {
            if (!operation_started) {
                std::cout << "Error! You must make a cut (scalpel) first.\n";
                continue;
            }
            Point p = input_point();
            tweezers(p);
        } 
        else if (command == "suture") {
            if (!operation_started) {
                std::cout << "Error! The operation has not started yet.\n";
                continue;
            }
            std::cout << "Suture start. ";
            Point start = input_point();
            std::cout << "Suture end. ";
            Point end = input_point();

            suture(start, end);

           
            if (are_points_equal(cut_start, start) && are_points_equal(cut_end, end)) {
                std::cout << "Operation successfully completed! The patient is saved.\n";
                break;
            } else {
                std::cout << "The suture does not match the cut! Continue the operation.\n";
            }
        } 
        else {
            std::cout << "Unknown command. Please try again.\n";
        }
        std::cout << "-------------------------------------\n";
    }

    return 0;
}
