#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "Car.h"
#include "Queues.h"
#include <vector>
#include <iostream>
using namespace std;

class Hospital {
private:
    int HID;
    vector<Car*> cars;
    SPQueue spQueue;
    NPQueue npQueue;
    EPQueue epQueue;

public:
    Hospital(int hid){
         HID=hid;
         }
    int getHID(){
         return HID; 
        }

    void addCar(Car* car){
         cars.push_back(car); 
        }
    void addPatient(Patient* p, string type){

        if(type=="SP") spQueue.EnQueue(p);

        else if(type=="NP"){

            npQueue.EnQueue(p);
        }

        else if(type=="EP"){

            epQueue.EnQueue(p);
        }
    }

    bool cancelPatientNP(int pid){
        
        return npQueue.cancelPatient(pid); 
    }

    void assignCar(){
        
        while(!epQueue.isEmpty()){

            Patient* p = epQueue.peekFront();
            bool assigned=false;
            for(auto car:cars){
                if(car->getStatus()=="Ready" && car->getType()=="NC"){
                    car->assignCar(p);
                    epQueue.DeQueue();
                    assigned=true; break;
                }
            }
            if(!assigned) break;
        }
        
        while(!spQueue.isEmpty()){

            Patient* p = spQueue.peekFront(); bool assigned=false;
            for(auto car:cars){
                if(car->getStatus()=="Ready" && car->getType()=="SC"){
                    car->assignCar(p); spQueue.DeQueue(); assigned=true; break;
                }
            }
            if(!assigned) break;
        }
        
        while(!npQueue.isEmpty()){
            
            Patient* p = npQueue.peekFront(); bool assigned=false;
            for(auto car:cars){
                if(car->getStatus()=="Ready" && car->getType()=="NC"){
                    car->assignCar(p); npQueue.DeQueue(); assigned=true; break;
                }
            }
            if(!assigned) break;
        }
    }

    void updateCars(){
        for(auto car:cars){
            if(car->getStatus()=="Assigned") car->markLoaded();
            else if(car->getStatus()=="Loaded") car->updateStatus();
        }
    }

    void displayQueues(){
        cout<<"Hospital "<<HID<<":\n";
        cout<<"EP Queue: "; epQueue.displayWithAssigned();
        cout<<"SP Queue: "; spQueue.displayWithAssigned();
        cout<<"NP Queue: "; npQueue.displayWithAssigned();
        cout<<"Cars status:\n";
        for(auto car:cars){
            cout<<car->getCID()<<" ["<<car->getType()<<"] Status: "<<car->getStatus()<<endl;
        }
        cout<<endl;
    }
};

#endif
