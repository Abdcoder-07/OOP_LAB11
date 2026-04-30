#include <iostream>
#include <fstream>
#include <cstring>
// Read and display all objects
using namespace std;

class Student {
public:
    int id;
    char name[20];

    Student() {
        id = 0;
        name[0] = '\0';
    }

    Student(int i, const char* n) {
        id = i;
        strcpy(name, n);
    }
};

int main() {
    Student s[] = {
        Student(34, "Anas"),
        Student(46, "Ali"),
        Student(67, "Abdullah")
    };

    int n = sizeof(s) / sizeof(s[0]);

    ofstream file("student.dat", ios::binary);

    if (!file) {
        cout << "File error!" << endl;
        return 1;
    }

    for (int i = 0; i < n; i++) {
        file.write((char*)&s[i], sizeof(s[i]));
    }

    file.close();

    ifstream inFile("student.dat", ios::binary);
    if (!inFile) {
        cout << "File error while reading!" << endl;
        return 1;
    }

    cout << "Students read from file:" << endl;
    Student temp;
    while (inFile.read((char*)&temp, sizeof(temp))) {
        cout << "ID: " << temp.id << " | Name: " << temp.name << endl;
    }

    inFile.close();

    cout << "Binary data written and read successfully." << endl;
    return 0;
}