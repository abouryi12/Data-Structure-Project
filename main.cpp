#include <iostream>
#include "classes/System_Manger.h"
#include "classes/Patient_Request.h"
#include "classes/Patient_Cancellation.h"


using namespace std;

int main() {


    Hospital* h1 = new Hospital(1);
    Hospital* h2 = new Hospital(2);

   
    Car* c1 = new Car("C1", 60, 0);
    Car* c2 = new Car("C2", 50, 0);
    Car* c3 = new Car("C3", 70, 0);

    c1->setType("NC");
    c2->setType("SC");
    c3->setType("NC");

    h1->addCar(c1);
    h1->addCar(c2);
    h2->addCar(c3);

    Patient* p1  = new Patient(101, 1, 1, 5, 10);   // EP
    Patient* p2  = new Patient(102, 2, 1, 3, 0);    // SP
    Patient* p3  = new Patient(103, 3, 1, 4, 0);    // NP
    Patient* p4  = new Patient(104, 4, 1, 2, 8);    // EP
    Patient* p5  = new Patient(105, 5, 1, 6, 0);    // SP
    Patient* p6  = new Patient(106, 6, 2, 7, 0);    // NP
    Patient* p7  = new Patient(107, 7, 1, 1, 9);    // EP
    Patient* p8  = new Patient(108, 8, 2, 8, 0);    // SP
    Patient* p9  = new Patient(109, 9, 1, 9, 0);    // NP
    Patient* p10 = new Patient(110,10, 2,10,12);    // EP

    
    SystemManager manager;
    manager.addHospital(h1);
    manager.addHospital(h2);

   
    manager.addEvent(new PatientRequestEvent(1,  p1,  h1, "EP"));
    manager.addEvent(new PatientRequestEvent(2,  p2,  h1, "SP"));
    manager.addEvent(new PatientRequestEvent(3,  p3,  h1, "NP"));
    manager.addEvent(new PatientRequestEvent(4,  p4,  h1, "EP"));
    manager.addEvent(new PatientRequestEvent(5,  p5,  h1, "SP"));
    

   
    int maxTime = 5;

    for (int time = 1; time <= maxTime; time++) {

        cout << "========= Time Step " << time << " =========\n";

        
        manager.startTimeStep();

        
        h1->displayQueues();
        h2->displayQueues();

        manager.finishTimeStep();
        

        cout << endl;
    }

    
    delete p1; 
    delete p2;
    delete p3; 
    delete p4;
    delete p5;
    delete c1;
    delete c2;
    delete c3;
    delete h1;
    delete h2;

    return 0;
}
