// COMSC 210 | Lab 32 | Gillian Rhett
// This program simulates a line of cars lined up to pay their toll at a toll booth. 
// We will start with a certain number of cars in the line, and repeatedly perform these line operations until the line is empty:
//    55% probability that the car at the head of the line pays its toll and leaves the toll booth
//    45% probability that another car joins the line for the toll booth

#include <iostream>
#include <cstdlib>
#include <deque>
#include "Car.h"
using namespace std;

const double P_LEAVE = 55; // either a car leaves or a new car joins
const int INIT_SIZE = 2; // initial size of the deque

int main() {
    // create a deque to store the cars in the toll lane
    deque <Car> toll_lane;
    for(int i = 0; i < INIT_SIZE; ++i) {
        Car new_car;
        toll_lane.push_back(new_car);
    }

    // display the cars in the lane at the beginning of the simulation
    cout << "Initial queue:" << endl;
    for (Car c : toll_lane) {
        cout << "\t";
        c.print();
    }

    // simulate cycles of the toll lane until it is empty
    int count = 1;
    int prob;
    while(!(toll_lane.empty())) {
        cout << "Time: " << count++ << " Operation: ";
        // use a random number to determine whether a car pays and leaves or a new car joins
        prob = rand() % 100 + 1;
        if (prob <= P_LEAVE) { // 1 to 55 --> 55% probability a car leaves
            cout << "Car paid: ";
            toll_lane.front().print();
            toll_lane.pop_front();
        }
        else { // 56 to 100 --> 45% probability that a new car joins
            cout << "Joined lane: ";
            Car c;
            toll_lane.push_back(c);
        }
        // display the current toll lane after the change
        
    }

    return 0;
}