#include<iostream> 
using namespace::std; //so I dont have to use it for input, output, or strings
int main() //main program
{
	string name; //for the customers name
	int cups = 0;
	string cupsout; //for the output of cups element
	char coffee;
	string coffeeout;
	char extra;
	string extraout;
	string weekday;
	string weekdayout;
	double total = 0.0; // tally the price

	cout.setf(ios::fixed); //magic formula
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout << "First name: ";
	cin >> name;
	if (name.length() > 0 && name[0] >= 'A' && name[0] <= 'Z')
		name = name;
	else
		name = "The first name must start with an uppercase letter.";
	cin.ignore(10000, '\n');
	cout << '\n';
	cout << "Number of cups: ";
	cin >> cups;
	if (cups > 0) {
		cups = cups;
	}
	else { // the else logic will prove vital in the end if conditions arent met for the input
		cupsout = "The number of cups must be positive.";
	}
	cin.clear();
	cin.ignore(10000, '\n');//used this so the program would continue running coorectly without '\n' interference
	cout << '\n';
	cout << "Type of coffee(r = regular, d = decaf): ";
	cin >> coffee;
	if (coffee == 'd') {
		total = total + 4.50;
		total = cups * total;
	}
	else if (coffee == 'r') {
		total = total + 4.00;
		total = cups * total;
	}
	else
	{
		coffeeout = "You must enter r or d.";
	}
	cin.ignore(10000, '\n');
	cout << '\n'; // this is used to move down the input for the next component
	cout << "Any extra items ? (y / n): ";
	cin >> extra;
	if (extra == 'y')
		total = total + 1.95;
	else if (extra == 'n') {
		total = total;
	}
	else {
		extraout = "You must enter y or n.";
	}
	cin.ignore(10000, '\n');
	cout << '\n';
	cout << "Day of the week: "; //prompting for the day of the week to apply discount
	cin >> weekday; //storing the day of the week in the variable weekday
	if (weekday == "Wednesday") {
		total = total * 0.85;
	}
	else if (weekday == "Monday" || weekday == "Tuesday" || weekday == "Thursday" || weekday == "Friday" || weekday == "Saturday" || weekday == "Sunday") {
		total = total;
	}
	else { //these else statements work sequentially to identify the first problem and output it to the user
		weekdayout = "You must enter a valid day of the week.";
	}
	cout << "---" << endl;
	if (name == "The first name must start with an uppercase letter.") {
		cout << name;
	}
	else if (cupsout == "The number of cups must be positive.") {
		cout << cupsout;
	}
	else if (coffeeout == "You must enter r or d.") {
		cout << coffeeout;
	}
	else if (extraout == "You must enter y or n.") {
		cout << extraout;
	}
	else if (weekdayout == "You must enter a valid day of the week.") {
		cout << weekdayout;
	}
	else { //if all things go right
		cout << "The total charge for " << name << " is $" << total;
	}

}
