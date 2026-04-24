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

const int P_LEAVE = 55; // either a car leaves or a new car joins
const int INIT_SIZE = 2; // initial size of the deque

int main() {
    // create a deque to store the cars in the toll lane
    deque <Car> toll_lane;
    for(int i = 0; i < INIT_SIZE; ++i) {
        Car new_car; // create a new car with random info
        toll_lane.push_back(new_car); // add the new car to the back of the line
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
    srand(time(0));
    while(!(toll_lane.empty())) {
        cout << "Time: " << count++ << " Operation: ";
        // use a random number to determine whether a car pays and leaves or a new car joins
        // based on the sample output, only one of the two operations can happen in each cycle
        prob = rand() % 100 + 1; // random number 1 to 100 for probability
        if (prob <= P_LEAVE) { // 1 to 55 --> 55% probability a car leaves
            cout << "Car paid: ";
            toll_lane.front().print(); // peek at the front car to display its info
            toll_lane.pop_front(); // remove the front car
        }
        else { // 56 to 100 --> 45% probability that a new car joins
            cout << "Joined lane: ";
            Car c; // create a new car with random info
            toll_lane.push_back(c); // the new car joins
            toll_lane.back().print(); // peek at the rear car that just joined and display its info
        }
        // display the current toll lane after the operation
        cout << "Queue:" << endl;
        for (Car c : toll_lane) {
            cout << "\t";
            c.print();
        }
        if(toll_lane.empty())
            cout << "\tEmpty"<< endl;
        cout << endl;
    }
    return 0;
}