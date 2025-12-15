#ifndef PATIENT_CANCELLATION_H
#define PATIENT_CANCELLATION_H
#include "Event.h"
#include "Hospital.h"
#include <iostream>
using namespace std;

class PatientCancellationEvent: public Event {
private:
    int patientID;
    Hospital* hospital;
public:
    PatientCancellationEvent(int t,int pid,Hospital* h)
        : Event(t,"Cancellation"){
             patientID=pid; hospital=h;
             }

    void execute() override{
        bool success=hospital->cancelPatientNP(patientID);
        if(success){
            cout<<"Patient "<<patientID<<" canceled successfully\n";
        }
        else{
             cout<<"Patient "<<patientID<<" not found for cancellation\n";
        }
    }
};

#endif
