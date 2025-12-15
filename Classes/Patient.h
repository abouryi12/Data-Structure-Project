#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
using namespace std;

class Patient {
private:
    int PID;           // patient id
    enum patientStatus { EP, SP, NP };
    int QT;            // request time
    int PT;            // pickup time
    int HID;           // hospital id
    int distance;
    int severity;      // use only with EP
    bool assigned = false;  

public:
    Patient(int pid, int qt, int hid, int dist, int sev) {
        PID = pid;
        QT = qt;
        HID = hid;
        distance = dist;
        severity = sev;
        PT = 0;         // pickup time
    }

    void updateStatus(int pt) {
        this->PT = pt;
    }

    int calculateWT() {
        return PT - QT;
    }

    int getPID(){
         return PID;
         }
    int getHID() {
         return HID;
         }
    int getDistance() {
         return distance; 
        }
    int getSeverity() {
         return severity;
         }

    
    void markAssigned() { 
        assigned = true; 
    }
    bool isAssigned() {
         return assigned; 
        }
};

#endif
