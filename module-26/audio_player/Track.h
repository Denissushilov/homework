#pragma once
#include <string>
#include <ctime>

class Track {
private:
    std::string title;
    std::tm creationData;
    int durationSeconds;
public:
    Track(std::string t_title, std::tm t_date, int t_duration);

    std::string getTitle() const;
    void displayInfo() const;
};