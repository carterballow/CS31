// array.cpp : this is project 4 src code.

#include <iostream>
#include <array>//for array
#include <string>//for use of string
#include <cassert>//for assert statements at the end of the code.
#include <cctype> // For isupper()
using namespace std;

int locateMaximum(const string array[], int n);//thse are the function prototypes
int countFloatingPointValues(const string array[], int n);
bool hasNoCapitals(const string array[], int n);
int shiftLeft(string array[], int n, int amount, string placeholder);

int locateMaximum(const string array[], int n) {//this function will return the index of the largest item found in the passed array or -1 if n <=0.
    if (n <= 0) { return -1; }
	else {
		int maxIndex = 0;
		for (int i = 1; i < n; i++) {
			if (array[i] > array[maxIndex]) {
				maxIndex = i;
			}
		}
		return maxIndex;

    }// a,b,c test later (ex test case)
}

int countFloatingPointValues(const string array[], int n) {
    if (n <= 0) {
        return -1; // Return -1 if the array has 0 or fewer elements
    }

    int counter = 0;

    for (int count = 0; count < n; count++) {
        int alreadyHasDecimal = 0;
        bool isValid = true;  // Flag to check if it's a valid floating-point number

        string str = array[count];
        int startIdx = 0;

        // Check for negative sign at the beginning
        if (str[0] == '-') {
            if (str.length() == 1) { // "-" alone is not a valid number
                isValid = false;
            }
            else {
                startIdx = 1; // Start checking from the next character
            }
        }
        // Allow numbers starting with a '.' (like .5)
        if (str[0] == '.') {
            startIdx = 1;  // Start checking from the next character
        }

        // Ensure that the first non-negative character is either a digit or '.'
        if (str[startIdx] == '.' || isdigit(str[startIdx])) {
            // Loop through the remaining characters
            for (int i = startIdx; i < str.length(); i++) {
                if (!isdigit(str[i])) {
                    if (str[i] == '.') {
                        if (alreadyHasDecimal == 1) {  // More than one decimal point
                            isValid = false;
                            break;
                        }
                        alreadyHasDecimal = 1;  // Mark that we've seen a decimal point
                    }
                    else {
                        isValid = false;  // Invalid character found
                        break;
                    }
                }
            }
        }
        else {
            isValid = false; // If the first non-negative character isn't a digit or '.', it's invalid
        }

        // If it's a valid number with at least one decimal point
        if (isValid && alreadyHasDecimal == 1) {
            counter++;
        }
    }

    return counter;
}
// {1.2, 3.4.0.9, 5.9}

     bool hasNoCapitals(const string array[], int n) {
        if (n <= 0) {
            return true; // If there are no elements, return true
        }

        // Iterate through each string in the array
        for (int i = 0; i < n; i++) {
            // Check each character in the current string
            for (char c : array[i]) {
                if (std::isupper(c)) {
                    return false; // If a capital letter is found, return false
                }
            }
        }

        return true; // No capital letters found in any string
     }

int shiftLeft(string array[], int n, int amount, string placeholder){
    if (n <= 0 || amount < 0) {
        return -1; // Return -1 if n <= 0 or amount < 0
    }

    if (amount >= n) {
        for (int i = 0; i < n; i++) {
            array[i] = placeholder; // Fill the entire array with placeholder
        }
        return n; // Return the number of placeholders used
    }

    int count = 0;

    // Shift elements left by 'amount' positions
    for (int i = 0; i < n - amount; i++) {
        array[i] = array[i + amount];
    }

    // Fill the remaining positions with the placeholder
    for (int i = n - amount; i < n; i++) {
        array[i] = placeholder;
        count++; // Count how many times placeholder is used
    }

    return count;
}

int main()//must have main routine for this project
{
    string data2[] = { "a", "b", "c" };
    assert(locateMaximum(data2, 3) == 2); // "c" is the largest

    string data1[] = { "12,", "98.76", "tyroin", "apple", "banana" };
    assert(locateMaximum(data1, 5) == 2); // "tyroin" is lexicographically the largest

    string datanew[] = { "12,", "98.76", "tyroin", "apple", "tyroin" };
    assert(locateMaximum(data1, 5) == 2); // if there are two largest elements, return the first one

    // Test with a single string
    string dataSingle[] = { "a" };
    assert(locateMaximum(dataSingle, 1) == 0); // Only one element, should return index 0

    string dataIdentical[] = { "apple", "apple", "apple" };
    assert(locateMaximum(dataIdentical, 3) == 0); // All identical strings, should return the first index

    // Test countFloatingPointValues
    string data3[] = { "3.14", "hello", "1.0", "foo", "5.67" };
    assert(countFloatingPointValues(data3, 5) == 3); // 3 floating-point numbers: 3.14, 1.0, 5.67

    string dataNegative[] = { "-3.14", "hello", "-1.0", "foo", "5.67" };
    assert(countFloatingPointValues(dataNegative, 5) == 3); // 3 floating-point numbers, including negative numbers

    string data4[] = { "hello", "world", "no numbers" };
    assert(countFloatingPointValues(data4, 3) == 0); // No floating-point values

    string dataInvalid[] = { "12.34abc", "123.45", "12.34," };
    assert(countFloatingPointValues(dataInvalid, 3) == 1); // Only "123.45" is valid

    // Test hasNoCapitals
    string data5[] = { "hello", "world", "no capitals" };
    assert(hasNoCapitals(data5, 3) == true); // All lowercase, should return true

    string data6[] = { "hello", "World", "no capitals" };
    assert(hasNoCapitals(data6, 3) == false); // "World" has a capital letter, should return false

    string dataMixed[] = { "hello", "world", "No Caps" };
    assert(hasNoCapitals(dataMixed, 3) == false); // "No Caps" contains capitals, should return false

    string dataSingleCapital[] = { "a", "B", "c" };
    assert(hasNoCapitals(dataSingleCapital, 3) == false); // "B" is capital, should return false

    string dataUpperCase[] = { "HELLO", "WORLD" };
    assert(hasNoCapitals(dataUpperCase, 2) == false); // All caps, should return false

    // Test shiftLeft
    string data7[] = { "12,", "98.76", "tyrion", "a", "b" };
    assert(shiftLeft(data7, 5, 2, "foo") == 2); // Shift by 2, placeholder "foo" should be used 2 times
    assert(data7[3] == "foo" && data7[4] == "foo"); // Check last two elements

    string data8[] = { "12,", "98.76", "tyrion", "a", "b" };
    assert(shiftLeft(data8, 5, 10, "bar") == 5); // Shift by more than the length, placeholder "bar" should fill all positions
    assert(data8[0] == "bar" && data8[1] == "bar" && data8[2] == "bar" && data8[3] == "bar" && data8[4] == "bar"); // Check all elements

    assert(shiftLeft(data8, 5, -5, "foobar") == -1); // Invalid shift amount

    assert(shiftLeft(data8, 0, 2, "foobar") == -1); // Edge case: empty array

    // Test shifting by 0 (should not change the array)
    string data9[] = { "one", "two", "three" };
    assert(shiftLeft(data9, 3, 0, "foo") == 0); // No shift, no placeholders used
    assert(data9[0] == "one" && data9[1] == "two" && data9[2] == "three"); // Array should remain unchanged

    cout << "All tests passed!" << endl;
}


