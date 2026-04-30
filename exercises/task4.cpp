#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Student {
public:
    int id;
    char name[20];

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

    cout << "Binary data written successfully." << endl;
    return 0;
}