#include <iostream>
#include <string>
#include <vector>
#include <ctime>

struct Task {
    std::string name;
    std::time_t startTime = 0;
    std::time_t endTime = 0;
    bool isFinished = false;
};


double secondsToHours(std::time_t seconds) {
    return static_cast<double>(seconds) / 3600.0;
}

int main() {
    std::vector<Task> taskHistory;
    Task currentTask;
    bool hasActiveTask = false;

    while (true) {
        std::cout << "\nEnter command (begin, end, status, exit): ";
        std::string command;
        std::cin >> command;

        if (command == "begin") {
            if (hasActiveTask) {
                currentTask.endTime = std::time(nullptr);
                currentTask.isFinished = true;
                taskHistory.push_back(currentTask);
                std::cout << "Auto-finished previous task: " << currentTask.name << "\n";
            }

            std::cout << "Enter task name: ";
            std::cin.ignore();
            std::getline(std::cin, currentTask.name);
            
            currentTask.startTime = std::time(nullptr);
            currentTask.isFinished = false;
            hasActiveTask = true;
            
            std::cout << "Started task: " << currentTask.name << "\n";

        } else if (command == "end") {
            if (hasActiveTask) {
                currentTask.endTime = std::time(nullptr);
                currentTask.isFinished = true;
                taskHistory.push_back(currentTask);
                hasActiveTask = false;
                std::cout << "Finished task: " << currentTask.name << "\n";
            } else {
                std::cout << "No active task running.\n";
            }

        } else if (command == "status") {
            std::cout << "\n--- FINISHED TASKS ---\n";
            if (taskHistory.empty()) {
                std::cout << "No finished tasks yet.\n";
            } else {
                for (const auto& task : taskHistory) {
                    std::time_t duration = task.endTime - task.startTime;
                    std::cout << "- " << task.name << ": " 
                              << secondsToHours(duration) << " hours "
                              << "(" << duration << " seconds)\n";
                }
            }

            std::cout << "\n--- CURRENT TASK ---\n";
            if (hasActiveTask) {
                std::time_t currentDuration = std::time(nullptr) - currentTask.startTime;
                std::cout << "Active: " << currentTask.name << "\n"
                          << "Time elapsed: " << secondsToHours(currentDuration) << " hours "
                          << "(" << currentDuration << " seconds)\n";
            } else {
                std::cout << "No active task.\n";
            }

        } else if (command == "exit") {
            std::cout << "Exiting program. Goodbye!\n";
            break;
            
        } else {
            std::cout << "Unknown command! Try again.\n";
        }
    }

    return 0;
}
