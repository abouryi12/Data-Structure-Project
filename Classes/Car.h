#ifndef CAR_H
#define CAR_H
#include "Patient.h"
#include <iostream>
using namespace std;

class Car {
private:
    string CID;
    double speed;
    int location;
    Patient* assignedPatient = nullptr;

    enum CarType { NC, SC };
    enum CarStatus { Ready, Assigned, Loaded };

    CarStatus status = Ready;
    CarType type = NC;

    int loadedTime = 0;          
    int travelDuration = 1;      

public:
    Car(string cid, int spd, int loc){
        CID = cid;
        speed = spd;
        location = loc;
    }

    void assignCar(Patient* p){
        if(status != Ready){
            cout << "Car is not ready for assignment." << endl;
            return;
        }
        assignedPatient = p;
        status = Assigned;
        if(assignedPatient) assignedPatient->markAssigned();
    }

    void markLoaded(){
        if(status == Assigned){
            status = Loaded;
            loadedTime = 0;
            
        }
    }

    void updateStatus(){
        if(status == Loaded){
            loadedTime++;
            if(loadedTime >= travelDuration){
                unloadPatient();
            }
        }
    }

    void unloadPatient(){
        if(status != Loaded){
            cout << "No patient to unload." << endl;
            return;
        }
        assignedPatient = nullptr;
        status = Ready;
        loadedTime = 0;
    }

    int getAssignedPatientID(){
         return assignedPatient ? assignedPatient->getPID() : -1; 
        }

    void setType(string t){
         type = (t=="NC") ? NC : SC;
         }
    string getType(){
         return (type==NC) ? "NC" : "SC";
         }

    string getStatus(){
        if(status == Ready){
            return "Ready";
        }
        else if(status == Assigned){

            return "Assigned";
        }
        else{
            
            return "Loaded";
        }
    }

    string getCID(){
         return CID;
         }
};

#endif
