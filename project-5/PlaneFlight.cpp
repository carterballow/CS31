#include <iostream>
#include <string>
#include "PlaneFlight.h"
using namespace std;
PlaneFlight::PlaneFlight(string passengerName, string fromCity, string toCity, double cost, double mileage) {
    // Use setters to validate and set values
    setName(passengerName);
    setFromCity(fromCity);
    setToCity(toCity);
    setCost(cost);
    setMileage(mileage);
    if (mFromCity == mToCity) {
        mFromCity = "";
        mToCity = "";
    }
}

// Getters and Setters with Validation Logic

double PlaneFlight::getCost() {
    return mCost;
}

void PlaneFlight::setCost(double setCost) {
    if (setCost >= 0.0) {
        mCost = setCost;
    } else {
        mCost = -1.0; // Indicate invalid cost
    }
}

double PlaneFlight::getMileage() {
    return mMileage;
}

void PlaneFlight::setMileage(double setMileage) {
    if (setMileage > 0.0) {
        mMileage = setMileage;
    } else {
        mMileage = -1.0; // Indicate invalid mileage
    }
}

string PlaneFlight::getName() {
    return mName;
}

void PlaneFlight::setName(string setName) {
    if (!setName.empty() && isValidName(setName)) {
        mName = setName;
    } else {
        mName = ""; // Ignore invalid name by setting it to an empty string
    }
}

string PlaneFlight::getFromCity() {
    return mFromCity;
}

void PlaneFlight::setFromCity(string setFromCity) {
    if (isValidCity(setFromCity)) { // Added check here
        mFromCity = setFromCity;
    } else {
        mFromCity = ""; // Ignore invalid fromCity
    }
}
string PlaneFlight::getToCity() {
    return mToCity;
}

void PlaneFlight::setToCity(string setToCity) {
    if (isValidCity(setToCity)) { // Added check here
        mToCity = setToCity;
    } else {
        mToCity = ""; // Ignore invalid toCity
    }
}

// Helper Validation Methods

bool PlaneFlight::isValidName(const string& name) const {
    if (name.empty()) {
        return false;
    }
    bool hasAlpha = false;
    for (char c : name) {
        if (!isalpha(c) && !isspace(c)) {
            return false;
        }
        if (isalpha(c)) {
            hasAlpha = true;
        }
    }
    return hasAlpha;
}

bool PlaneFlight::isValidCity(const string& city) const {
    if (city.empty()) {
        return false;
    }
    bool hasAlpha = false;
    for (char c : city) {
        if (!isalpha(c) && !isspace(c)) {
            return false;
        }
        if (isalpha(c)) {
            hasAlpha = true;
        }
    }
    return hasAlpha;
}