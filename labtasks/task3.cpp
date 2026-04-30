#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Student {
    private:
        int id;
        string name;
        float gpa;
    public:
        void input () {
            cout << "Enter ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter GPA: ";
            cin >> gpa;
        }

        void writeToFile() {
            ofstream file("task3.txt", ios::app);
            if (!file) {
                cout << "Could not open file for writing." << endl;
                return;
            }
            file << "ID: " << id << " | Name: " << name << " | GPA: " << gpa << endl;
            file.close();
        }

        void displayFromProgramMemory() {
            cout << "ID: " << id << endl;
            cout << "Name: " << name << endl;
            cout << "GPA: " << gpa << endl;
        }

        void displayFromFile() {
            fstream file;
            file.open("task3.txt", ios::in);
            if (!file) {
                cout << "Could not open file for reading." << endl;
                return;
            }
            cout << "Reading from file: " << endl;
            string line;
            while(getline(file, line)) {
                cout << line << endl;
            }
            file.close();
        }

};
int main () {
    ofstream clearFile("task3.txt", ios::trunc);
    if (!clearFile) {
        cout << "Could not initialize task3.txt." << endl;
        return 1;
    }
    clearFile.close();

    Student s[5];
    for (int i=0; i<5; i++) {
        cout << "Adding records for student " << i+1 << endl;
        s[i].input();
        s[i].writeToFile();
    }
    cout << "Student record saved!" << endl;

    s[0].displayFromFile();
    return 0;
}