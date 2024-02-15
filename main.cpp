// Alonso Nunez
// Project Description:

#include <iostream>
#include <fstream>
#include "student.cpp" // Include the header file for the Student class

int main()
{
  // Create a Student object
  Student student;

  // Open the file for reading
  std::ifstream file("oneStudent.dat");
  if (!file.is_open())
  {
    std::cerr << "Error: Unable to open file." << std::endl;
    return 1;
  }

  // Read data from the file into the Student object
  file >> student;

  // Close the file
  file.close();
  student.ComputeTotal();
  student.ComputeGrade();
  // Output the student information on one row using operator<<
  std::cout << "Student Information (One Row):" << std::endl;
  std::cout << student << std::endl;

  // Display the student information with one attribute per row
  std::cout << "Student Information (One Attribute Per Row):" << std::endl;
  student.DisplayInfo();

  return 0;
}
