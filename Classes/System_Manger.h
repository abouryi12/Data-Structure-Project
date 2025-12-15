#ifndef SYSTEM_MANAGER_H
#define SYSTEM_MANAGER_H

#include "Hospital.h"
#include "Event.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class SystemManager {
private:
    int CurrentTime = 0;
    vector<Hospital*> hospitals;
    vector<Event*> EventQueue;

public:
    ~SystemManager() {
        for (auto* e : EventQueue)
            delete e;
    }

    void addHospital(Hospital* h) {
        hospitals.push_back(h);
    }

    void addEvent(Event* e) {
        EventQueue.push_back(e);
        sort(EventQueue.begin(), EventQueue.end(),
             [](Event* a, Event* b) {
                 return a->timestamp < b->timestamp;
             });
    }

   
    void startTimeStep() {
        CurrentTime++;
        processEvents();
    }

    void finishTimeStep() {
        for (auto& h : hospitals) {
            h->updateCars();
            h->assignCar();
        }
    }

private:
    void processEvents() {
        vector<Event*> remaining;

        for (auto* e : EventQueue) {
            if (e->timestamp == CurrentTime) {
                e->execute();
                delete e;
            } else if (e->timestamp > CurrentTime) {
                remaining.push_back(e);
            } else {
                
                delete e;
            }
        }

        EventQueue = remaining;
    }
    
};

#endif
