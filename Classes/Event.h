#ifndef EVENT_H
#define EVENT_H
#include <iostream>
using namespace std;

class Event {
public:
    int timestamp;
    string eventType;

    Event(int t, string type){ 
        timestamp=t; eventType=type;
     }
    virtual void execute()=0;
};

#endif
