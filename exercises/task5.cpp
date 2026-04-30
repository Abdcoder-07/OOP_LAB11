#include <iostream>
#include <fstream>
using namespace std;

int main() {
    try {
        ifstream file("task5.txt");

        if (!file) {
            throw "Error: Unable to open file!";
        }

        cout << "File opened successfully." << endl;

        file.close();
    }
    catch (const char* error) {
        cout << error << endl;
    }

    return 0;
}