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

const double P_LEAVE = 0.55, P_JOIN = 0.45;
const int INIT_SIZE = 2;

int main() {
    deque <Car> toll_line;
    for(int i = 0; i < INIT_SIZE; ++i) {
        Car new_car;
        toll_line.push_back(new_car);
    }

    for (Car c : toll_line) // TESTING
        c.print();

    return 0;
}