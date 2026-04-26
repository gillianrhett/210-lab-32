// COMSC 210 | Lab 33 | Gillian Rhett
// This program simulates multiple toll lanes of cars lined up to pay their toll at a toll booth. 
// for each lane:
//    46% probability that the car at the head of the queue pays its toll and leaves the queue
//    39% probability that another car joins the queue
//    15% probability that the rear car will shift lanes

#include <iostream>
#include <cstdlib>
#include <array>
#include <deque>
#include "Car.h"
using namespace std;

const int P_LEAVE = 55; // either a car leaves or a new car joins
const int INIT_SIZE = 2; // initial size of the deque
const int NUM_LANES = 4; // number of toll lanes to store in the array
const int SIM_CYCLES = 20; // number of times to run the simulation

int main() {
    // create an array to store four lanes
    array <deque <Car>, NUM_LANES> lanes;

    // create 4 deques to store the cars in the toll lanes
    for (int i = 0; i < NUM_LANES; ++i) {
        deque <Car> temp_lane;
        for(int j = 0; j < INIT_SIZE; ++j) {
            Car new_car; // create a new car with random info
            temp_lane.push_back(new_car); // add the new car to the back of the line
        }
        lanes.at(i) = temp_lane;
    }

    // display the cars in the lane at the beginning of the simulation
    cout << "Initial queue:" << endl;
    int n = 1;
    for (deque toll_lane : lanes) {
        cout << "Lane " << n++ << endl;
        for (Car c : toll_lane) {
            cout << "\t";
            c.print();
        }
    }
/* // commenting out the rest so I can test the first part
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
*/
    return 0;
}