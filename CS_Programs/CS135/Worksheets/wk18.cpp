/*
 * Alec Him
 * CS 135 - Worksheet 18
 * Description: Simple program that demonstrates using structs
 * Input: String, Integer, Double
 * Output: Struct data
 */
#include <iostream>

struct studentType
{
    std::string firstName = "", lastName = "";
    int courseGrade = 0, courseSection = 0;
    double gpa = 0.0;
};

int main()
{
    // Variables 
    const int NUM_STUDENTS = 3;
    studentType students[NUM_STUDENTS];
    for(int i = 0; i < NUM_STUDENTS; i++)
    {
        std::cout << "Enter first, last, grade, section, GPA: ";
        std::cin >> students[i].firstName >> students[i].lastName >> students[i].courseGrade >> students[i].courseSection >> students[i].gpa; 
    }
    for(int i = 0; i < NUM_STUDENTS; i++)
        std::cout << "Student " << i << " " << students[i].firstName << " " << students[i].lastName << " " << students[i].courseGrade << " " << students[i].courseSection << " " << students[i].gpa << std::endl;

    return 0;
}