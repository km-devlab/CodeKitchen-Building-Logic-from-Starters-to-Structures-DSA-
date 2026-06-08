
#include <iostream>
using namespace std;

int main() {
    string name;
    float mark1, mark2, mark3, average;

    cout << "Enter student name: ";
    cin >> name;

    cout << "Enter marks for 3 subjects: ";
    cin >> mark1 >> mark2 >> mark3;

    average = (mark1 + mark2 + mark3) / 3;

    cout << "\nStudent Name: " << name;
    cout << "\nAverage Marks: " << average;

    if (average >= 90)
        cout << "\nGrade: A";
    else if (average >= 75)
        cout << "\nGrade: B";
    else if (average >= 50)
        cout << "\nGrade: C";
    else
        cout << "\nGrade: Fail";

    return 0;
}
