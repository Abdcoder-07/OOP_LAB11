#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;
// Exercise
// Read a file containing 10 numbers
// Display only even numbers
int main(){
  ifstream file("task2.txt", ios::in);

  if (!file) {
    cout << "Error: could not open task2.txt" << endl;
    return 1;
  }

  char ch;
  while (file >> ch) {
    if (isdigit(static_cast<unsigned char>(ch)) && ((ch - '0') % 2 == 0)) {
      cout << ch << endl;
    }
  }

  file.close();
  return 0;
}