#include <iostream>
#include <fstream>
using namespace std;

// Count number of lines in a file
int main(){
  ifstream file("task2.txt", ios::in);

  if (!file) {
    cout << "Error: could not open task2.txt" << endl;
    return 1;
  }

  int lineCount = 0;
  string line;
  while (getline(file, line)) {
    ++lineCount;
  }

  file.close();
  cout << "Number of lines: " << lineCount << endl;
  return 0;
}