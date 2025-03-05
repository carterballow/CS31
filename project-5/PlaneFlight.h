#ifndef PLANEFLIGHT_H
#define PLANEFLIGHT_H

#include <string>
using namespace std; // Use the std namespace
class PlaneFlight {
private:
    double mCost;
    string mFromCity;
    string mToCity;
    string mName;
    double mMileage;

public:
    PlaneFlight(string passengerName, string fromCity, string toCity, double cost, double mileage);

    double getCost();
    void setCost(double setCost);

    double getMileage();
    void setMileage(double setMileage);

    string getName();
    void setName(string setName);

    string getFromCity();
    void setFromCity(string setFromCity);

    string getToCity();
    void setToCity(string setToCity);

    bool isValidCity(const std::string& city) const;
    bool isValidName(const std::string& name) const;
};

#endif // PLANEFLIGHT_H