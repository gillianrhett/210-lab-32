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

const int P_LEAVE = 46; // if the random num is 1 to 46, the front car pays and leaves
const int P_JOIN = P_LEAVE + 39; // if the random num is 47 to 85, a new car joins
// if the random num is 86 to 100, the rear car shifts lanes
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

    // simulate cycles of the toll lane until it is empty
    int prob, rand_lane; // for storing random numbers
    srand(time(0));
    for (int t = 1; t <= SIM_CYCLES; ++t) {
        cout << "Time " << t << ":" << endl;
        for (int lane = 0; lane < NUM_LANES; ++lane) {
            cout << "Lane: " << lane + 1 << " "; // the lane number to display is one greater than its index
            // use a random number to determine whether a car pays and leaves or a new car joins or a car switches lanes
            // based on the sample output, only one of the two operations can happen in each cycle
            prob = rand() % 100 + 1; // random number 1 to 100 for probability                
            if (prob <= P_LEAVE && !lanes.at(lane).empty()) { // 1 to 46 --> 46% probability a car leaves
                cout << " Paid: ";
                lanes.at(lane).front().print(); // peek at the front car to display its info
                lanes.at(lane).pop_front(); // remove the front car
            }
            else if (P_LEAVE < prob && prob <= P_JOIN) { // 47 to 85 --> 39% probability that a new car joins
                cout << "Joined lane: ";
                Car c; // create a new car with random info
                 lanes.at(lane).push_back(c); // the new car joins
                 lanes.at(lane).back().print(); // peek at the rear car that just joined and display its info
            }
            else if (prob > P_JOIN && !lanes.at(lane).empty()) { // 86 to 100 --> 15% probability that the rear car switches to another lane
                // randomly pick a different lane
                rand_lane = lane;
                while(rand_lane == lane)
                    rand_lane = rand() % NUM_LANES; // pick a random lane that isn't the current lane
                // add the car to the new lane
                lanes.at(rand_lane).push_back(lanes.at(lane).back());
                cout << "Switched: ";
                lanes.at(lane).back().print();
                // remove the car from its old lane
                lanes.at(lane).pop_back();
            }
            else { // else the lane was empty and a new car didn't join
                cout << "Lane is still empty." << endl;
            }
            // display the current toll lane after the operation
            cout << "Queue:" << endl;
            for (Car c : lanes.at(lane)) {
                cout << "\t";
                c.print();
            }
            if(lanes.at(lane).empty())
                cout << "\tEmpty"<< endl;
            cout << endl;
        }
    }

    return 0;
}