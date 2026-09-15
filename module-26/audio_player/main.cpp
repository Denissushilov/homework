#include <iostream>
#include <string>
#include "Player.h"
#include "Track.h"

std::tm make_date(int year, int month, int day) {
    std::tm tm = {};
    tm.tm_year = year - 1900; // Года отсчитываются с 1900
    tm.tm_mon = month - 1;    // Месяцы от 0 до 11
    tm.tm_mday = day;
    return tm;
}

int main() {
    Player player;

    player.addTrack(Track("Bohemian Rhapsody", make_date(1975, 10, 31), 355));
    player.addTrack(Track("Stairway to Heaven", make_date(1971, 11, 8), 482));
    player.addTrack(Track("Hotel California", make_date(1976, 12, 8), 390));

    std::cout << "--- Audio Player Simulation Started ---\n";
    std::cout << "Commands: play, pause, next, stop, exit\n\n";

    std::string command;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, command);

        if (command == "exit") {
            std::cout << "Exiting player. Goodbye!\n";
            break;
        } else if (command == "play") {
            player.play();
        } else if (command == "pause") {
            player.pause();
        } else if (command == "next") {
            player.next();
        } else if (command == "stop") {
            player.stop();
        } else {
            std::cout << "Unknown command. Try: play, pause, next, stop, exit\n";
        }
    }

    return 0;
}
