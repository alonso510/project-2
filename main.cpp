// Alonso Nunez
// Project Description:

#include <iostream>
#include <fstream>
#include "student.cpp" // Include the header file for the Student class
#include "roster.cpp"
int main()
{

  Roster test; 
  std::string filename = "grades.dat";
  test.readStudentRecord(filename);
  std::cout << test << std::endl;
  std::string id;
  test.ShowOneStudent(id);

  return 0;
}
