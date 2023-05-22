#ifndef TASKMANAGER_H
#define TASKMANAGER_H
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <QSharedPointer>
#include <algorithm>
#include <QDebug>

using std::cout;
using std::endl;
using std::vector;
using std::string;

struct Task_t {
    int interval;
    void(*task)(void);
    int exeTime;
};

class Systick {
public:
    static Systick* getInstance(void) {
        static Systick* instance = nullptr;
        if (instance == nullptr) {
            instance = new Systick();
            //auto instance = std::make_shared<Systick>();
        }
        return instance;
    }
    void addTask(string taskName, int interval) {
        auto newTask = std::make_shared<Task_t>();
        newTask->interval = interval;
        //newTask->task = task;
        newTask->exeTime = newTask->interval + this->tickCounter;
        flags.push_back(false);
        tasks.push_back(newTask);

    }
    void systickIsr(void) {
        this->tickCounter++;
        //cout << "Tick : " << this->tickCounter << endl;
        int i = 0;
        for (auto task : tasks) {
            if (task->exeTime == this->tickCounter) {
                //task->task();
                flags[i] = true;
                task->exeTime = task->interval + this->tickCounter;
            }
            ++i;
        }
    }
    void systickHandler(void) {
        static int timer = 0;
        if (++timer > 50000) {
            timer = 0;
            this->systickIsr();
        }
    }
    vector<bool> flags;
private:
    Systick() : tickCounter(0) {}
    int tickCounter;
    vector<std::shared_ptr<Task_t>> tasks;
};

#endif // TASKMANAGER_H
