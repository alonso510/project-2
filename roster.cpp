#include "roster.h"
#include <iostream>
#include <cassert>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>

// Constructor definition
Roster::Roster(string courseName) : courseName(courseName), studentNum(0)
{
    // Initialize the roster with no students
}
Roster::Roster() : courseName(""), studentNum(0)
{
    // Initialize the roster with no students
}
void Roster::readStudentRecord(string filename)
{
    std::ifstream file(filename); // declare file pass in filename
    file.open(filename);          // open file
    file >> courseName;
    std::string header;
    std::getline(file, header);
    while (file)
    {                                 // iterate through file
        file >> students[studentNum]; // store className
        studentNum++;
    }
    file.close(); // close file
}
int Roster::GetStudentCount() const
{
    return studentNum;
}
bool Roster::isValid(string id) const
{
    for (int i = 0; i <= studentNum; i++)
    {
        if (students[i].getID() == id)
        {
            return true;
        }
    
    }
return false; 
}
void Roster::ShowOneStudent(string id) const  {
    while (!isValid(id)) {
        std::cout << "Enter a valid class ID: ";
        std::cin >> id;
        std::cout << endl;
    }

    for (int i = 0; i < studentNum; i++) {
        if (students[i].getID() == id) {
            students[i].DisplayInfo();
            return; // Exit the function after displaying information for the matching student
        }
    }

    // If the loop completes without finding a matching student
    std::cout << "Student with ID " << id << " not found." << std::endl;
}
ostream & operator<< (ostream & os, const Roster & oneClass) {
    ifstream inputFile("grades.dat");
    if (!inputFile) {
        cerr << "File could not be opened." << endl;
        return os;
    } //test to open file

    // Count the number of students in the file
    int numStudents = 0;
    string line;
    while (getline(inputFile, line)) {
        ++numStudents;
    }
    inputFile.clear(); 
    inputFile.seekg(0); 

    // Output header with the total number of students
    os << "Here is the information for " << numStudents-2 << " students:" << endl;

    // Output individual student information
    while (getline(inputFile, line)) {
        os << line << endl; 
    }

    inputFile.close();
    return os;
}