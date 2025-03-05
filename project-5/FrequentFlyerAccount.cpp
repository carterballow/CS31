#include "PlaneFlight.h"
#include "FrequentFlyerAccount.h"
#include <iostream>
#include <string>
using namespace std;

FrequentFlyerAccount::FrequentFlyerAccount(string name) {//set up account
    mName = name;
    mBalance = 0;
}

double FrequentFlyerAccount::getBalance() {//get the balance
    return mBalance;
}

string FrequentFlyerAccount::getName() {//get the name of the account not the flight important
    return mName;
}

bool FrequentFlyerAccount::addFlightToAccount(PlaneFlight flight) {
    if(flight.getName() == mName){
    mBalance += flight.getMileage();
    return true; // Assuming adding a flight always succeeds
    }
    return false;
}

bool FrequentFlyerAccount::canEarnFreeFlight(double mileage) {
    if((mBalance >= mileage) && (mileage > 0)){
    return true;
    }
    else 
    return false;
}
bool FrequentFlyerAccount::freeFlight(string from, string to, double mileage, PlaneFlight& flight) {

    if (canEarnFreeFlight(mileage)) {
        mBalance -= mileage;

        // Set the flight details for the free flight
        flight.setName(mName);  // Assign the account holder's name to the flight
        flight.setFromCity(from);    // Set the departure location
        flight.setToCity(to); // Set the destination location
        flight.setCost(0.0);     // Free flight, so cost is zero
        flight.setMileage(mileage); // Assign the mileage for tracking

        return true;
    }
    return false; // Not enough mileage for a free flight
}
