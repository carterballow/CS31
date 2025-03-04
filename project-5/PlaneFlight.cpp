#include <iostream>
#include <string>
#include "PlaneFlight.h"

PlaneFlight::PlaneFlight(string passengerName, string fromCity, string toCity, double cost, double mileage) {
    // Cost Validation
    if (cost >= 0.0) {
        mCost = cost;
    } else {
        mCost = -1.0; // Indicate invalid cost
    }

    // Mileage Validation
    if (mileage > 0.0) {
        mMileage = mileage;
    } else {
        mMileage = -1.0; // Indicate invalid mileage
    }

    // Name Validation
    if (!passengerName.empty()) {
        mName = passengerName;
    } else {
        mName = ""; // Ignore invalid name by setting to empty string.
    }

    // City Validation
    if (!fromCity.empty() && !toCity.empty() && fromCity != toCity) {
        mFromCity = fromCity;
        mToCity = toCity;
    } else {
        mFromCity = ""; // Ignore invalid fromCity
        mToCity = ""; // Ignore invalid toCity
    }
}

double PlaneFlight::getCost() {
    return mCost;
}

void PlaneFlight::setCost(double setCost) {
    mCost = setCost;
}

double PlaneFlight::getMileage() {
    return mMileage;
}

void PlaneFlight::setMileage(double setMileage) {
    mMileage = setMileage;
}

string PlaneFlight::getName() {
    return mName;
}

void PlaneFlight::setName(string setName) {
    mName = setName;
}

string PlaneFlight::getFromCity() {
    return mFromCity;
}

void PlaneFlight::setFromCity(string setFromCity) {
    mFromCity = setFromCity;
}

string PlaneFlight::getToCity() {
    return mToCity;
}

void PlaneFlight::setToCity(string setToCity) {
    mToCity = setToCity;
}
int PlaneFlight::getIsValid(){
    return mIsValid;
}


