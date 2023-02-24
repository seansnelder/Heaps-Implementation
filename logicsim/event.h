#ifndef EVENT_H
#define EVENT_H
#include "wire.h"

struct Event
{
    uint64_t time;
    Wire* wire;
    char state;
};

// struct RandObjGen {
//     int operator() { return rand(); }
//   };
  

typedef struct EventLess {
        //write the operator() required to make this a functor that compares Events by time
        bool operator()(Event* a, Event* b){
            
        return a->time < b->time; //we want first argument's time to be less than, 
        // because it is a min heap
        }

        } EventLess;
	
#endif
