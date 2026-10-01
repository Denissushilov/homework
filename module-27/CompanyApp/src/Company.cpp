#include "../include/Company.h"
#include <iostream>
#include <cstdlib>

std::string taskToString(TaskType type)
{
    switch(type) {
        case TaskType::A: return "A";
        case TaskType::B: return "B";
        case TaskType::C: return "C";
        default: return "None";
    }
}

// class Employee
Employee::Employee(const std::string& name) 
: name(name) {};

std::string Employee::getName() const
{ return name; }

// class Worker
Worker::Worker(const std::string& name) 
: Employee(name) {}

bool Worker::isBusy() const
{ return busy; }

void Worker::assignTask(TaskType task)
{
    busy = true;
    currentTask = task;
    std::cout << " [Worker] " << getName() << " get task: " 
    << taskToString(task) << "\n";
}

// class Manager
Manager::Manager(const std::string& name, unsigned id)
: Employee(name), managerId(id) {}

Manager::~Manager()
{
    for(auto* worker : team) 
        delete worker;  
}

void Manager::addWarker(Worker* worker)
{
    team.push_back(worker);
}

int Manager::getFreeWorkersCount() const
{
    int freeCount = 0;
    for(const auto* worker : team)
        if(!(worker->isBusy())) freeCount++;
    return freeCount;    
}

void Manager::receiveCommand(int directoryCommand)
{
    std::cout << " [Manager] " << getName() << " (ID: " << managerId
    << ") get command from director: " << directoryCommand << "\n";

    int hash = directoryCommand + managerId;
    std::srand(hash);

    int taskCount = (rand() % team.size()) + 1;
    std::cout << " -> Generated tasks for team: " << taskCount << "\n";

    for(int i = 0; i < taskCount; ++i)
    {
        Worker* freeWorker {nullptr};
        for(auto * worker : team) {
            if(!(worker->isBusy())) {
                freeWorker = worker;
                break;
            }
        }

        if(freeWorker == nullptr) 
            break;

        int taskTypeNum = (rand() % 3) + 1;
        TaskType task = static_cast<TaskType>(taskTypeNum);
        freeWorker->assignTask(task);
    }
}

//class Director
Director::Director(const std::string& name)
: Employee(name) {}

Director::~Director()
{
    for(auto* manager : managers)
        delete manager;
}

void Director::addManager(Manager* manager)
{
    managers.push_back(manager);
}

void Director::giveOrder(int command)
{
    std::cout << "\n[Director] " << getName() << "gived command: " 
    << command << "\n";
    for(auto *manager : managers)
        manager->receiveCommand(command);
}

bool Director::allEmployyeesBusy() const
{
    for(const auto* manager : managers) {
        if(manager->getFreeWorkersCount() > 0) 
            return false;
    }
    return true;
}