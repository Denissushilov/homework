#include "../include/Company.h"
#include <string>
#include <iostream>

int main()
{
    std::cout << "Simulation of an IT company’s operations\n\n";

    int teamsCount, workersPerTeam;
    while(true) {
        std::cout << "Enter count of teams: ";
        std::cin >> teamsCount;
        std::cout << "Enter cout employees in every team: ";
        std::cin >> workersPerTeam;

        if(teamsCount <= 0 || workersPerTeam <= 0) 
            std::cout << "Error: the company’s size must be greater than zero. Try again!\n";
        else 
            break;    
    }

    Director* director = new Director("Elon Musk");
    
    for(int i = 1; i <= teamsCount; ++i) {
        std::string managerName = "Manager_" + std::to_string(i);
        Manager* manager = new Manager(managerName, i);

        for(int j = 1; i <= workersPerTeam; ++i) {
            std::string workerName = "Worker_" + std::to_string(i) + "_" + std::to_string(j);
            Worker* worker = new Worker(workerName);
            manager->addWarker(worker);
        }
        director->addManager(manager);
    }

    std::cout << "The company has been successfully formed.\n";
    std::cout << "Enter whole numbers (the director's instructions) until all workers are occupied.\n";

    while(!(director->allEmployyeesBusy())) {
        int command;
        std::cout << "Enter the director's task identifier: ";
        std::cin >> command;

        director->giveOrder(command);
    }

    std::cout << "\nThe simulation is complete! All employees are busy working." << std::endl;

    delete director;

    return 0;    
}