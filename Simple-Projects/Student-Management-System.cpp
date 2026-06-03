#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Student {
public:
    int id;
    string name;
    float marks;

    void input() {
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display() {
        cout << "ID: " << id 
             << ", Name: " << name 
             << ", Marks: " << marks << endl;
    }
};

// Save to file
void saveToFile(const vector<Student>& students) {
    ofstream file("students.txt");
    for (auto s : students) {
        file << s.id << " " << s.name << " " << s.marks << endl;
    }
    file.close();
}

// Load from file
vector<Student> loadFromFile() {
    vector<Student> students;
    ifstream file("students.txt");
    Student s;

    while (file >> s.id >> s.name >> s.marks) {
        students.push_back(s);
    }
    return students;
}

int main() {
    vector<Student> students = loadFromFile();
    int choice;

    do {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by ID\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            Student s;
            s.input();
            students.push_back(s);
            saveToFile(students);
            cout << "Student added!\n";
        }

        else if (choice == 2) {
            for (auto s : students)
                s.display();
        }

        else if (choice == 3) {
            int id;
            cout << "Enter ID to search: ";
            cin >> id;

            bool found = false;
            for (auto s : students) {
                if (s.id == id) {
                    s.display();
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Student not found!\n";
        }

        else if (choice == 4) {
            int id;
            cout << "Enter ID to delete: ";
            cin >> id;

            vector<Student> updated;
            bool deleted = false;

            for (auto s : students) {
                if (s.id != id)
                    updated.push_back(s);
                else
                    deleted = true;
            }

            students = updated;
            saveToFile(students);

            if (deleted) cout << "Student deleted!\n";
            else cout << "Student not found!\n";
        }

    } while (choice != 5);

    cout << "Exiting...\n";
    return 0;
}
