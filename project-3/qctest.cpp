// qctest.cpp
// Project 3
// leave comments carter!!!

#include <iostream>
#include <string>
#include <cassert> //for testing
using namespace std;

bool isValidQC(string results) {

    // Index initiation
    size_t i = 0;//int basically
    size_t length = results.length();

    // Returns false if is empty
    if (results.empty()) {
        return false;
    }

    // Q must be the first letter for each grouping
    while (i < length) {
        if (results[i] != 'Q') {
            return false;
        }
        i++;

        // after 'Q' the first digit cant be '0'
        if (i >= length || isdigit(results[i]) == false || results[i] == '0') {
            return false;
        }

        // Leading 0
        if (results[i] == '0' && (i + 1 < length && isdigit(results[i + 1]))) {
            return false; // Invalidates numbers with leading zeros
        }
        int totalTests = 0;
        while (i < length && isdigit(results[i])) {
            totalTests = totalTests * 10 + (results[i] - '0'); // Converts to int
            i++;
        }

        int passes = -1, defects = -1; // Reset for each batch

       
        for (int j = 0; j < 2; j++) { // checks twice
            if (i >= length || (results[i] != 'p' && results[i] != 'd')) {
                return false;
            }
            char c = results[i]; // Store p or d
            i++;

          
            if (i >= length || isdigit(results[i]) == false) {
                return false;
            }
            if (results[i] == '0' && (i + 1 < length && isdigit(results[i + 1]))) {
                return false; // Invalidates leading zeros
            }

            int count = 0; // Counts passes and defects
            while (i < length && isdigit(results[i])) {
                count = count * 10 + (results[i] - '0');
                i++;
            }

            if (c == 'p') {
                passes = count;
            }
            if (c == 'd') {
                defects = count;
            }
        }

        // if passes or defects equal -1, false
        if (passes == -1 || defects == -1 || passes + defects != totalTests) {
            return false;
        }
    }
    return true;
}

// Returns the total number of passed tests across all batches, or -1 if invalid
int passQC(string results) {

    if (isValidQC(results) == false) {
        return -1;
    }

    // Indexing
    size_t i = 0;
    size_t length = results.length();
    int totalPasses = 0;

    while (i < length) {
        i++; // Skip 'Q'
        while (i < length && isdigit(results[i])) i++; // Skip batch count

        int p = 0, d = 0;
        for (int j = 0; j < 2; j++) {
            char c = results[i];
            i++;
            int count = 0;
            while (i < length && isdigit(results[i])) {
                count = count * 10 + (results[i] - '0'); // Go one-by-one through digits
                i++;
            }
            if (c == 'p') {
                p = count;
            }
            if (c == 'd') { // Necessary to ensure that the batch formatting is correct
                d = count;
            }
        }
        totalPasses = totalPasses + p; // Add total passes
    }
    return totalPasses;
}

// Returns -1 if not valid
int defectQC(string results) {

    if (isValidQC(results) == false) {
        return -1;
    }

    // Index intitialization
    size_t i = 0;// size var type(int) is helpful for this 
    size_t length = results.length();
    int totalDefects = 0;

    while (i < length) {
        i++; // for Q
        while (i < length && isdigit(results[i])) i++; // Skip count

        int p = 0, d = 0;
        for (int j = 0; j < 2; j++) {
            char c = results[i];
            i++;
            int count = 0;
            while (i < length && isdigit(results[i])) {
                count = count * 10 + (results[i] - '0');
                i++;
            }
            if (c == 'p') { // Necessary to ensure that the batch formatting is correct
                p = count;
            }
            if (c == 'd') {
                d = count;
            }
        }
        totalDefects = totalDefects + d; // Add total defects to the previous amount in the case of multiple strings.
    }
    return totalDefects;
}

int totalQC(string results) {  // -1 if invalid, else the total using the other functions

    if (isValidQC(results) == false) {
        return -1;
    }
    return passQC(results) + defectQC(results);
}

// Returns the total number of batches in the string, or -1 if invalid
int batches(string results) {

    if (isValidQC(results) == false) {
        return -1;
    }

    // Indexing
    size_t i = 0, len = results.length();
    int batchCount = 0;

    while (i < len) {//i is less than length during the traversal of the string
        batchCount++;
        i++; // for Q
        while (i < len && isdigit(results[i])) {
            i++; // Skip count...
        }
        for (int j = 0; j < 2; j++) {
            i++; 
            while (i < len && isdigit(results[i])) {
                i++;
            }
        }
    }
    return batchCount;
}

int main() {

    string s;
    cout.setf(ios::boolalpha); // make them true or false

    for (;;) {
        cout << "Pass test result(s) returns ";
        getline(cin, s);
        if (s == "quit") break;//this is here in the case that the user needs to quit as a second chance

        cout << "isValidQC returns " << isValidQC(s) << endl;
        cout << "passQC returns " << passQC(s) << endl;
        cout << "defectQC returns " << defectQC(s) << endl;
        cout << "totalQC returns " << totalQC(s) << endl;
        cout << "batches returns " << batches(s) << endl;
    }
    return 0;
}
