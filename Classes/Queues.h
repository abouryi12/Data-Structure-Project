#ifndef QUEUES_H
#define QUEUES_H

#include "Patient.h"
#include <iostream>
using namespace std;

const int SIZE = 20;


struct SPQueue {
    Patient* arr[SIZE];
    int front = -1;
    int rear  = -1;

    bool isEmpty() {
         return front == -1 && rear == -1;
         }
    bool isFull() { 
        return (front==0 && rear==SIZE-1) || (rear+1==front); 
    }

    void EnQueue(Patient* p){
        if(isFull()) {
             cout<<"SP Queue Full\n";
              return; 
            }
        if(isEmpty()){ 
            front=rear=0;
             arr[rear]=p;
              return;
             }
        rear = (rear==SIZE-1)?0:rear+1;
        arr[rear] = p;
    }

    Patient* DeQueue(){
        if(isEmpty()){
            return nullptr;
        }
        Patient* p = arr[front];
        if(front==rear){
            front=rear=-1;
        }
        else front = (front==SIZE-1)?0:front+1;
        return p;
    }

    Patient* peekFront(){ 
        return isEmpty()?nullptr:arr[front];
     }

    bool cancelPatient(int pid){
        if(isEmpty()) return false;
        int i=front;
        while(true){
            if(arr[i]->getPID()==pid){
                while(i!=rear){
                    int next = (i==SIZE-1)?0:i+1;
                    arr[i]=arr[next];
                    i=next;
                }
                if(front==rear){
                    front=rear=-1;
                }
                else if(rear==0){
                    rear=SIZE-1;
                }
                else{
                     rear--;
                }
                return true;
            }
            if(i==rear){
                break;
            }
            i=(i==SIZE-1)?0:i+1;
        }
        return false;
    }

    void displayWithAssigned(){
        if(isEmpty()){ 
            cout<<"Empty\n";
             return; 
            }
        int i=front;
        while(true){
            cout<<arr[i]->getPID();
            if(arr[i]->isAssigned()){
                cout<<"(Assigned)";
            }
            cout<<" ";
            if(i==rear){
                break;
            }
            i=(i==SIZE-1)?0:i+1;
        }
        cout<<endl;
    }
};

struct NPQueue { 
    Patient* arr[SIZE];
    int front=-1, rear=-1;

    bool isEmpty(){ 
        return front==-1 && rear==-1; 
    }
    bool isFull(){ 
        return (front==0 && rear==SIZE-1) || (rear+1==front); 
    }

    void EnQueue(Patient* p){ if(isFull()){
         cout<<"NP Queue Full\n";
          return;
         } 
        if(isEmpty()){ 
            front=rear=0; 
            arr[rear]=p;
             return;
             }
        rear=(rear==SIZE-1)?0:rear+1; 
        arr[rear]=p; 
    }

    Patient* DeQueue(){
         if(isEmpty()){
             return nullptr;
         }
        Patient* p=arr[front];
         if(front==rear){
            front=rear=-1;
         }
        else{
            front=(front==SIZE-1)?0:front+1;
         }
          return p;
         }

    Patient* peekFront(){
         return isEmpty()?nullptr:arr[front];
         }

    bool cancelPatient(int pid){
         if(isEmpty()){
            return false;
         }
        int i=front;
         while(true){ 
            if(arr[i]->getPID()==pid){
                while(i!=rear){
                     int next=(i==SIZE-1)?0:i+1;
                      arr[i]=arr[next];
                       i=next;
                    }
                if(front==rear){
                    front=rear=-1;
                 }
                  else if(rear==0){
                    rear=SIZE-1;
                   }
                    else{ rear--; 
                    return true;
                    }
            } 
            if(i==rear){
                 break;
            }
                  i=(i==SIZE-1)?0:i+1;
        }
         return false;
    }

    void displayWithAssigned(){
        if(isEmpty()){
             cout<<"Empty\n"; 
             return; 
            }
          int i=front;
        while(true){
             cout<<arr[i]->getPID(); 
             if(arr[i]->isAssigned())
             cout<<"(Assigned)"; 
             cout<<" "; 
             if(i==rear) break;
              i=(i==SIZE-1)?0:i+1;
            }
        cout<<endl;
    }
};

struct EPQueue {
    Patient* arr[SIZE];
    int front=-1, rear=-1;

    bool isEmpty(){
         return front==-1 && rear==-1;
         }
   bool isFull(){
    return (front == 0 && rear == SIZE - 1) || (rear + 1 == front);
}

   void EnQueue(Patient* p){
    if (isFull()){
        return;
    }

    if (isEmpty()){
        front = rear = 0;
        arr[rear] = p;
        return;
    }

    int i = rear;
    while (true){
        int next = (i + 1) % SIZE;

        if (arr[i]->getSeverity() >= p->getSeverity()){
            arr[next] = p;
            rear = next;
            break;
        }

        arr[next] = arr[i];

        if (i == front){
            arr[i] = p;
            front = (front - 1 + SIZE) % SIZE;
            break;
        }

        i = (i - 1 + SIZE) % SIZE;
    }
}


    Patient* DeQueue(){ 
        if(isEmpty()){
            return nullptr;
         }
          Patient* p=arr[front]; 

        if(front==rear){
            front=rear=-1;
         }
          else{
             front=(front==SIZE-1)?0:front+1;
           }
            return p; 
        }

    Patient* peekFront(){
         return isEmpty()?nullptr:arr[front]; 
        }

    void displayWithAssigned(){
        if(isEmpty()){
             cout<<"Empty\n"; 
             return; 
            }
        int i=front;
        while(true){
            cout<<arr[i]->getPID()<<"("<<arr[i]->getSeverity()<<")";
            if(arr[i]->isAssigned())
             cout<<"(Assigned)";
            cout<<" ";
            if(i==rear) break;
            i=(i==SIZE-1)?0:i+1;
        }
        cout<<endl;
    }
};

#endif
