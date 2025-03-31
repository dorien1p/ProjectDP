//---------------------------------------------------------------------------
// File name:   class_report.cpp
// Assign ID:   
// Due Date:    3/30/2025
//
// Purpose:     Reads student grade data from a file and prints a formatted 
//              grade report with name, grades, and average.
//
// Author:      Dorien Parris
//---------------------------------------------------------------------------
// run code using ↓
// g++ -o class_report.out class_report.cpp
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

int main()
{
    //----------------------------------------------------------------------
    //  Open the file
    //----------------------------------------------------------------------
    ifstream inputFile("grades.csv");

    // Check if the file opened successfully
    if (!inputFile)
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    //----------------------------------------------------------------------
    //  Print table header
    //----------------------------------------------------------------------
    cout << left << setw(20) << "Name" 
         << setw(8) << "Grade 1" << setw(8) << "Grade 2"
         << setw(8) << "Grade 3" << setw(8) << "Grade 4"
         << setw(8) << "Grade 5" << setw(8) << "Average" << endl;

    //----------------------------------------------------------------------
    //  Read and process file data
    //----------------------------------------------------------------------
    string line, name;
    double grade1, grade2, grade3, grade4, grade5;

    while (getline(inputFile, line))
    {
        stringstream ss(line);
        getline(ss, name, ',');   // Read name
        ss >> grade1; ss.ignore();
        ss >> grade2; ss.ignore();
        ss >> grade3; ss.ignore();
        ss >> grade4; ss.ignore();
        ss >> grade5;

        // Calculate average
        double average = (grade1 + grade2 + grade3 + grade4 + grade5) / 5.0;

        // Print formatted output
        cout << left << setw(20) << name
             << fixed << setprecision(1)
             << setw(8) << grade1 << setw(8) << grade2
             << setw(8) << grade3 << setw(8) << grade4
             << setw(8) << grade5 << setw(8) << average << endl;
    }

    //----------------------------------------------------------------------
    //  Close the file
    //----------------------------------------------------------------------
    inputFile.close();

    return 0;
}