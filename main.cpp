// Alonso Nunez
// Project Description: Search and Display Students 

#include <iostream>
#include <fstream>
#include "student.cpp" // Include the header file for the Student class
#include "roster.cpp"
int main()
{

  Roster test; // create the roster object
  std::string filename = "grades.dat"; // create the filename
  test.readStudentRecord(filename); // read the roster
  std::cout << test << std::endl; // Print the roster
  std::string id;
  test.ShowOneStudent(id); // show one student

  return 0;
}
