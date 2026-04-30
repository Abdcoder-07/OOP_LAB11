// Task
// Combine file handling + exception handling
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
using namespace std;

int main() {
    try {
        string message;
        cout << "Enter a message to store in file: ";
        getline(cin, message);

        ofstream outFile("task5.txt");
        if (!outFile) {
            throw runtime_error("Error: Unable to create task5.txt");
        }
        outFile << message << endl;
        outFile.close();

        ifstream inFile("task5.txt");
        if (!inFile) {
            throw runtime_error("Error: Unable to open task5.txt for reading");
        }

        string line;
        cout << "Data read from file:" << endl;
        while (getline(inFile, line)) {
            cout << line << endl;
        }

        inFile.close();
    }
    catch (const exception& error) {
        cout << error.what() << endl;
    }

    return 0;
}
