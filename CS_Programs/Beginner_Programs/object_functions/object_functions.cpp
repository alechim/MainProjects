#include <iostream>

using namespace std;

class Student {
    public:
        string name;
        string major;
        double gpa;
        Student(string studentName, string studentMajor, double studentGpa){
            name = studentName;
            major = studentMajor;
            gpa = studentGpa;
        }

        bool hasHonors(){
            // only have to change 3.5 if bar is changed to 2.0
            if(gpa >= 3.5){
                return true;
            }
            return false;
        }
};

int main(){

    Student student1("Jim", "Business", 2.4);
    Student student2("Pam", "Art", 3.6);

    cout << student1.hasHonors() << endl;

    cout << student2.hasHonors() << endl;

    return 0;
}