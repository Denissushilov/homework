#include "Track.h"
#include <iostream>
#include <iomanip>

Track::Track(std::string t_title, std::tm t_date, int t_duration)
: title(t_title), creationData(t_date), durationSeconds(t_duration) {}

std::string Track::getTitle() const { return title; }

void Track::displayInfo() const
{
    std::cout << "Track: \\" << title  << "\\\n";
    std::cout << "Created: " << std::put_time(&creationData, "%Y/%m/%d") << "\n";
    std::cout << "Duration: " << durationSeconds / 60 << " m " << durationSeconds % 60 << " s\n";
}