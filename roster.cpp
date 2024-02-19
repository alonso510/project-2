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
   
    std::ifstream file; // declare file pass in filename
    file.open(filename);          // open file

    std::string line;
      for(int i = 0; i < 2; ++i){ // for loop to skip first two lines 
        std::getline(file, line);
      }
  
    while (file)
    {                                 // iterate through file
        file >> students[studentNum]; // store className
        students[studentNum].ComputeTotal();
        students[studentNum].ComputeGrade();
     
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
    std:: cout << "Enter a valid class ID: ";
    std::cin >> id;
    std::cout << std::endl;
    while(isValid(id) == false){
        std:: cout << "Enter a valid class ID: ";
        std::cin >> id;
        std::cout << std::endl;
    }
    
    for (int i = 0; i < studentNum; i++) {
        if (students[i].getID() == id) {
            students[i].DisplayInfo();
            break;// Exit the function after displaying information for the matching student
        }
    }

  

    // If the loop completes without finding a matching student
   
}
    string Roster::getclassName() const {
    return courseName;
}
ostream & operator<< (ostream & os, const Roster & oneClass) {
    ifstream inputFile("grades.dat");
    if (!inputFile) {
        cerr << "File could not be opened." << endl;
        return os;
    } 

    
    int numStudents = 0;
    string line;
    while (getline(inputFile, line)) {
        ++numStudents;
    }
    inputFile.clear(); 
    inputFile.seekg(0); 

    
    os << "Here is the information for " << numStudents-2 << " students in class " << oneClass.getclassName() << endl;

    // Output individual student information
    while (getline(inputFile, line)) {
        os << line << endl; 
    }

    inputFile.close();
    return os;
}