// Modify the program to:

// Append data instead of overwriting
// Use ios::app
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

    fstream file("task1.txt",ios::app);
    if (!file) {
        cout << "Error: could not open file for writing." << endl;
        return 1;
    }

    file << "Name: " << name << '\n';
    file << "Age: " << age << '\n';
    file.close();

    cout << "Data stored in task1.txt by appending" << endl;
    return 0;
}