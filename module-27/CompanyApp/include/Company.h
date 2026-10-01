#pragma once
#include <string>
#include <vector>

enum class TaskType {None, A, B, C};

std::string taskToString(TaskType);

class Employee {
protected:
    std::string name;
public:
    Employee(const std::string&);
    virtual ~Employee() = default;
    std::string getName() const;        
};

class Worker : public Employee {
private:
    bool busy {false};
    TaskType currentTask {TaskType::None};
public:
    Worker(const std::string&);
    bool isBusy() const;
    void assignTask(TaskType);    
};

class Manager : public Employee {
private:
    unsigned managerId;
    std::vector<Worker*> team;
public:
    Manager(const std::string&, unsigned);   
    ~Manager();
    void addWarker(Worker*);
    void receiveCommand(int);
    int getFreeWorkersCount() const;    
};

class Director : public Employee {
private:
    std::vector<Manager*> managers;
public:
    Director(const std::string&);
    ~Director();
    void addManager(Manager*);
    void giveOrder(int);
    bool allEmployyeesBusy() const;        
};