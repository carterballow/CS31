#include <iostream>
#include <string>
#include <cassert>
#include "PlaneFlight.h"
#include "FrequentFlyerAccount.h"
using namespace std;
int main()
{
// sample test code
PlaneFlight shortleg( "Howard", "LAX", "LAS", 49.00, 285 );
PlaneFlight longleg( "Howard", "LAS", "NYC", 399.00, 2800 );
PlaneFlight sample( "Sample", "Sample", "Sample", 0, 1 );
FrequentFlyerAccount account( "Howard" );
assert( shortleg.getFromCity( ) == "LAX" );
assert( shortleg.getToCity( ) == "LAS" );
assert( shortleg.getName( ) == "Howard" );
assert( std::to_string( shortleg.getCost( ) ) == "49.000000" );
assert( std::to_string( shortleg.getMileage( ) ) == "285.000000" );
// account balance starts at zero...
assert( std::to_string( account.getBalance( ) ) == "0.000000" );
assert( account.getName( ) == "Howard" );
assert( account.canEarnFreeFlight( 3300.00 ) == false );
// flights add to an account balance
assert( account.addFlightToAccount( shortleg ) == true ); // returns true
assert( account.addFlightToAccount( longleg ) == true ); // returns true
assert( account.addFlightToAccount( sample ) == false ); // returns true
assert( std::to_string( account.getBalance( ) ) == "3085.000000" );
// free flights reduce an account balance
if (account.canEarnFreeFlight( 285 ))
{
assert( account.freeFlight( "LAS", "LAX", 285, sample ) == true );
// Howard earned a free flight...
assert( sample.getName( ) == "Howard" );
assert( std::to_string( sample.getCost( ) ) == "0.000000" );
assert( sample.getFromCity( ) == "LAS" );
assert( sample.getToCity( ) == "LAX" );
assert( std::to_string( sample.getMileage( ) ) == "285.000000" );
// account has been reduced for this free flight...
assert( std::to_string( account.getBalance( ) ) == "2800.000000" );
}
else
{
assert( false ); // there are enough miles in the account...
}
// non-matching names are ignored
PlaneFlight muffin( "Muffin", "LAX", "Doggie Heaven", 500, 500 );
assert( account.addFlightToAccount( muffin ) == false );
assert( std::to_string( account.getBalance( ) ) == "2800.000000" );

PlaneFlight validFlight("Alice", "LAX", "SFO", 150.00, 350);
    assert(validFlight.getName() == "Alice");
    assert(validFlight.getFromCity() == "LAX");
    assert(validFlight.getToCity() == "SFO");
    assert(validFlight.getCost() == 150.00);
    assert(validFlight.getMileage() == 350);

    PlaneFlight invalidCostFlight("Bob", "NYC", "MIA", -50.00, 1200);
    assert(invalidCostFlight.getCost() == -1.0);

    PlaneFlight invalidMileageFlight("Charlie", "ORD", "DEN", 200.00, 0);
    PlaneFlight invalidMileageFlight2("David", "ORD", "DEN", 200.00, -10);
    assert(invalidMileageFlight.getMileage() == -1.0);
    assert(invalidMileageFlight2.getMileage() == -1.0);

    PlaneFlight invalidNameFlight("", "DFW", "ATL", 180.00, 800);
    PlaneFlight invalidNameFlight2(" ", "DFW", "ATL", 180.00, 800);
    PlaneFlight invalidNameFlight3("!@#$", "DFW", "ATL", 180.00, 800);
    assert(invalidNameFlight.getName() == "");
    assert(invalidNameFlight2.getName() == "");
    assert(invalidNameFlight3.getName() == "");

    PlaneFlight invalidFromCityFlight("Eve", "", "PHX", 250.00, 600);
    PlaneFlight invalidFromCityFlight2("Eve", " ", "PHX", 250.00, 600);
    PlaneFlight invalidFromCityFlight3("Eve", "!@#$", "PHX", 250.00, 600);
    assert(invalidFromCityFlight.getFromCity() == "");
    assert(invalidFromCityFlight2.getFromCity() == "");
    assert(invalidFromCityFlight3.getFromCity() == "");

    PlaneFlight invalidToCityFlight("Frank", "SEA", "", 300.00, 700);
    PlaneFlight invalidToCityFlight2("Frank", "SEA", " ", 300.00, 700);
    PlaneFlight invalidToCityFlight3("Frank", "SEA", "!@#$", 300.00, 700);
    assert(invalidToCityFlight.getToCity() == "");
    assert(invalidToCityFlight2.getToCity() == "");
    assert(invalidToCityFlight3.getToCity() == "");

    PlaneFlight sameCityFlight("Grace", "HOU", "HOU", 100.00, 100);
    assert(sameCityFlight.getFromCity() == "");
    assert(sameCityFlight.getToCity() == "");

    PlaneFlight floatTest("Henry", "BOS", "IAD", 100.000001, 100);
    assert(floatTest.getCost() == 100.000001);

    // FrequentFlyerAccount Test Cases
    FrequentFlyerAccount account1("Isabella");
    assert(account1.getName() == "Isabella");
    assert(account1.getBalance() == 0.0);

    account1.addFlightToAccount(validFlight);
    assert(account1.getBalance() == 0.0);//because alice doesnt have the same name as isabella

    PlaneFlight secondFlight("Isabella", "MIA", "ATL", 200.00, 500);
    account1.addFlightToAccount(secondFlight);
    assert(account1.getBalance() == 500.0);

    FrequentFlyerAccount account2("Jack");
    account2.addFlightToAccount(validFlight);
    assert(account2.getBalance() == 0.0);

    assert(account1.canEarnFreeFlight(300));
    assert(!account1.canEarnFreeFlight(10000));

    PlaneFlight freeFlightRedeemed("", "", "", 0, 0);
    assert(account1.freeFlight("SFO", "LAX", 350, freeFlightRedeemed));
    assert(account1.getBalance() == 150.0);
    assert(freeFlightRedeemed.getName() == "Isabella");
    assert(freeFlightRedeemed.getFromCity() == "SFO");
    assert(freeFlightRedeemed.getToCity() == "LAX");
    assert(freeFlightRedeemed.getCost() == 0.0);
    assert(freeFlightRedeemed.getMileage() == 350);

    assert(!account1.freeFlight("LAX", "SFO", 10000, freeFlightRedeemed));
    assert(account1.getBalance() == 150.0);

    assert(!account1.freeFlight("LAX", "SFO", 0, freeFlightRedeemed));
    assert(account1.getBalance() == 150.0);

    //edge case float tests
    PlaneFlight floatFlight1("Kelly", "LAX", "LAS", 10.00, 100.123456789);
    FrequentFlyerAccount account3("Kelly");
    account1.addFlightToAccount(floatFlight1);
    account3.addFlightToAccount(floatFlight1);
    assert(account1.getBalance() == 150.0);
    assert(account3.getBalance() == 100.123456789);
    assert(account1.canEarnFreeFlight(100.123456789));
    assert(account1.freeFlight("LAS", "LAX", 100.123456789, floatFlight1));
    assert(floatFlight1.getCost() == 0.0);
    assert(account1.getBalance() == 49.876543211);

    cout << "All tests passed!" << endl;
    return 0;
}
// for compialation on vs code use 
// Remove-Item a.exe -Force -ErrorAction SilentlyContinue; Remove-Item *.o -Force -ErrorAction SilentlyContinue
// g++ main.cpp PlaneFlight.cpp FrequentFlyerAccount.cpp -o project; ./project
// should look like thisAssertion failed: sample.getFromCity( ) == "LAS", file main.cpp, line 34