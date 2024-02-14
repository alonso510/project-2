#include "student.h"

// Default constructor definition
Student::Student() : id(""), name(""), total(0), letterGrade(' ') {
    // Initialize all scores to zero
    for (int i = 0; i < CATEGORY_NUM; ++i) {
        score[i] = 0;
    }
}

// Copy constructor definition
Student::Student(const Student& s) : id(s.id), name(s.name), total(s.total), letterGrade(s.letterGrade) {
    // Copy all scores
    for (int i = 0; i < CATEGORY_NUM; ++i) { // loop through ENUM 
        score[i] = s.score[i];
    }
}

// Assignment operator definition
Student& Student::operator=(const Student& s) {
    if (this != &s) { // Check for self-assignment
        id = s.id; // set 
        name = s.name;
        total = s.total;
        letterGrade = s.letterGrade;
        // Copy all scores
        for (int i = 0; i < CATEGORY_NUM; ++i) {
            score[i] = s.score[i];
        }
    }
    return *this;
}
string Student::getID() const {
    return id;
}

void Student::setID(string newID) {
    id = newID;
}
  // Accessor & mutator of total (score)
    void  Student::ComputeTotal(){
         for (int i = 0; i < CATEGORY_NUM; ++i) { // loop through ENUM 
        total = total + score[i];
    }
    }

    int Student::GetTotal() const {
        return total;
    }