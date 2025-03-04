#include "PlaneFlight.h"
#include "FrequentFlyerAccount.h"
#include <iostream>
#include <string>
using namespace std;

FrequentFlyerAccount::FrequentFlyerAccount(string name) {
    mName = name;
    mBalance = 0;
}

double FrequentFlyerAccount::getBalance() {
    return mBalance;
}

string FrequentFlyerAccount::getName() {
    return mName;
}

bool FrequentFlyerAccount::addFlightToAccount(PlaneFlight flight) {
    mBalance += flight.getMileage();
    return true; // Assuming adding a flight always succeeds
}

bool FrequentFlyerAccount::canEarnFreeFlight(double mileage) {
    return mBalance >= mileage;
}

bool FrequentFlyerAccount::freeFlight(string from, string to, double mileage, PlaneFlight& flight) {
    if (canEarnFreeFlight(mileage)) {
        mBalance -= mileage;
        // Potentially update the flight object with details
        return true;
    } else {
        return false;
    }
}