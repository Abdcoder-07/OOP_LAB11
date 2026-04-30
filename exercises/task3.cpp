// Store 5 student records in file
#include <iostream>
#include <fstream>
using namespace std;

class Student {
private:
    int id;
    string name;
    float gpa;
public:
    void input() {
        cout << "Enter ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin,name);
        cout << "Enter GPA: ";
        cin >> gpa;
    }
    void display() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "GPA: " << gpa << endl;
    }
    // Function to write object data to file
    void writeToFile() {
        ofstream file("task3.txt", ios::app);
        file << id << " " << name << " " << gpa << endl;
        file.close();
    }
};
int main() {
    Student s;
    s.input();       // Take input
    s.writeToFile(); // Save to file
    cout << "Student record saved!" << endl;
    return 0;
}