// Write a program to:

// Take user name and age
// Store it in a file
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    string name;
    cout << "Enter a Name: ";
    getline(cin, name);

    int age;
    cout << "Enter an Age: ";
    cin >> age;

    ofstream file("task1.txt");
    if (!file) {
        cout << "Error: could not open file for writing." << endl;
        return 1;
    }

    file << "Name: " << name << '\n';
    file << "Age: " << age << '\n';
    file.close();

    cout << "Data stored in task1.txt" << endl;
    return 0;
}