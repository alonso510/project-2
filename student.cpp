#include "student.h"
#include <iostream>
#include <cassert>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>

// Default constructor definition
Student::Student() : id(""), name(""), total(0), letterGrade(' ')
{
    // Initialize all scores to zero
    for (int i = 0; i < CATEGORY_NUM; ++i)
    {
        score[i] = 0;
    }
}

// Copy constructor definition
Student::Student(const Student &s) : id(s.id), name(s.name), total(s.total), letterGrade(s.letterGrade)
{
    // Copy all scores
    for (int i = 0; i < CATEGORY_NUM; ++i)
    { // loop through ENUM
        score[i] = s.score[i];
    }
}

// Assignment operator definition
Student &Student::operator=(const Student &s)
{
    if (this != &s)
    {              // Check for self-assignment
        id = s.id; // set
        name = s.name;
        total = s.total;
        letterGrade = s.letterGrade;
        // Copy all scores
        for (int i = 0; i < CATEGORY_NUM; ++i)
        {
            score[i] = s.score[i];
        }
    }
    return *this;
}
 //getters and setters
string Student::getID() const
{
    return id;
}

void Student::setID(string newID)
{
    id = newID;
}
// Accessor & mutator of total (score)
void Student::ComputeTotal()
{
    for (int i = 0; i < CATEGORY_NUM; ++i)
    {                             // loop through ENUM
        total = total + score[i]; // add to total;
    }
}

int Student::GetTotal() const
{
    return total;
}
// Function to compute letter grade
void Student::ComputeGrade()
{
    if (total >= 90)
    {
        letterGrade = 'A';
    }
    else if (total >= 80)
    {
        letterGrade = 'B';
    }
    else if (total >= 70)
    {
        letterGrade = 'C';
    }
    else if (total >= 60)
    {
        letterGrade = 'D';
    }
    else
    {
        letterGrade = 'F';
    }
}
char Student::GetGrade() const
{
    return letterGrade;
}
void Student::changeScore(ScoreType scoreName, int scoreValue)
{
    score[static_cast<int>(scoreName)] = scoreValue;
}

// Accessor function to get the score for a specific ScoreType
int Student::getScore(ScoreType scoreName) const
{
    return score[static_cast<int>(scoreName)];
}


// Function to display information of one student
void Student::DisplayInfo() const
{
    // Print student ID and name
    std::cout << "----------------------" << std::endl;
    std::cout << "ID: " << id << std::endl;
    std::cout << "Name: " << name << std::endl;

    // Print scores for each ScoreType

    std::cout << "CLA: " << score[CLA] << std::endl;
    std::cout << "OLA: " << score[OLA] << std::endl;
    std::cout << "QUIZ: " << score[QUIZ] << std::endl;
    std::cout << "HOMEWORK: " << score[HOMEWORK] << std::endl;
    std::cout << "EXAM: " << score[EXAM] << std::endl;
    std::cout << "BONUS: " << score[BONUS] << std::endl;

    // Print total score and letter grade
    std::cout << "----------------------" << std::endl;
    std::cout << "Total Score: " << total << std::endl;
    std::cout << "Letter Grade: " << letterGrade << std::endl;
}
std::ostream &operator<<(std::ostream &myout, const Student &s)
{
    // Output specific information of the student on one row
    myout << std::setw(5) << s.id << std::setw(15) << s.name;
    for (int i = 0; i < Student::CATEGORY_NUM; ++i)
    {
        myout << std::setw(5) << s.score[i];
    }

    myout << std::endl;

    return myout;
} 
//  insertion operator overload
std::istream &operator>>(std::istream &myin, Student &s)
{
    // Input student information
    myin >> s.id >> s.name;
    for (int i = 0; i < Student::CATEGORY_NUM; ++i)
    {

        myin >> s.score[i];
    }
    return myin;
}
void Student::setTotal(int n)
{
    total = n;
}