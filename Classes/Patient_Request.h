#ifndef PATIENT_REQUEST_H
#define PATIENT_REQUEST_H
#include "Event.h"
#include "Hospital.h"
#include "Patient.h"
#include <iostream>
using namespace std;

class PatientRequestEvent: public Event {
private:
    Patient* patient;
    Hospital* hospital;
    string queueType;
public:
    PatientRequestEvent(int t, Patient* p, Hospital* h, string type)
        : Event(t,"PatientRequest"){ patient=p; hospital=h; queueType=type; }

    void execute() override {
        hospital->addPatient(patient, queueType);
        cout<<"Patient "<<patient->getPID()<<" added to hospital "<<hospital->getHID()<<" Queue "<<queueType<<endl;
    }
};
#endif
