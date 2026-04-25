#include <iostream>
#include <vector>
using namespace std;

// Class Template
template <class T>
class Student {
private:
    T id;
    string name;

public:
    // Constructor
    Student(T i, string n) {
        id = i;
        name = n;
    }

    // Getter for ID
    T getId() {
        return id;
    }

    // Display Method
    void display() {
        cout << "ID: " << id << " | Name: " << name << endl;
    }
};

// Main Program
int main() {
    vector<Student<int>> students;  // vector to store students
    int choice;

    do {
        cout << "\n===== Student Management Menu =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Remove Student by ID\n";
        cout << "4. Search Student by ID\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        int id;
        string name;

        switch (choice) {
        case 1: {
            cout << "Enter ID and Name: ";
            cin >> id >> name;
            students.push_back(Student<int>(id, name));
            cout << "Student added successfully.\n";
            break;
        }

        case 2: {
            if (students.empty()) {
                cout << "No students found.\n";
            } else {
                cout << "\n--- Student List ---\n";
                for (auto &s : students) {
                    s.display();
                }
            }
            break;
        }

        case 3: {
            cout << "Enter ID to remove: ";
            cin >> id;
            bool found = false;

            for (auto it = students.begin(); it != students.end(); ++it) {
                if (it->getId() == id) {
                    students.erase(it);
                    cout << "Student removed successfully.\n";
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Student not found.\n";

            break;
        }

        case 4: {
            cout << "Enter ID to search: ";
            cin >> id;
            bool found = false;

            for (auto &s : students) {
                if (s.getId() == id) {
                    cout << "Student Found:\n";
                    s.display();
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Student not found.\n";

            break;
        }

        case 0:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}