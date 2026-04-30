#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

class Student{
	private:
		int ID;
		string name;
	    double GPA;
	public:
		void input(){
			cout << "Enter a ID:";
			cin >> ID;
			cin.ignore();
			cout << "Enter a Name:";
			getline(cin,name);
			cout << "Enter GPA:";
			cin >> GPA;
		}
		 void WriteToFile(){
			ofstream file("final.txt",ios::app);
			if(!file){
				cout << "Error! File not Opening..."<< endl;
				return;
			}
			file << ID <<"|"<<name << "|" << GPA << endl;
			file.close();
			cout <<  "Record Added Successfully!" << endl;
		}
	static	void viewStudent(){
			ifstream file("final.txt");
			if(!file){
				cout << "Error! File not Opening..."<< endl;
				return;
			}
			string line;
			 cout <<"--------Student Records--------"<< endl;
			 cout << "ID | Name | GPA" << endl;
			while(getline(file,line)){
				cout << line << endl;
			}
			file.close();
		}
	static void Search(){
			ifstream file("final.txt");
			if(!file){
				cout << "Error! File not Opening..."<< endl;
				return;
			}
			string searchName,line;
			cin.ignore();
			cout << "Enter a Name to Search:";
			getline(cin,searchName);
			int found = 0;
			while(getline(file,line)){
				if(line.find(searchName) != string::npos){
					cout << "--------Record Found--------" << endl;
					cout << line << endl;
					found = 1;
				}
			}
			if(!found){
				cout << "Student Record not Found..." << endl;
			}
		 file.close();	
		}
};
void pressEnter(){
	cin.ignore();
	cout << "press enter to continue...";
	cin.ignore(10000,'\n');
	system("cls");
}
int main(){
	Student s;
	int choice;
	cout << "\n-------Student Managment System-------\n" << endl;
	int running= 1;
	while(running){	
	cout << "=======Menu=======" << endl;
	cout << "1.Add Students"<< endl;
	cout << "2.View Students" << endl;
	cout << "3.Search Students" << endl;
	cout << "4.Exit" << endl;
	cout << "Enter a Choice:" ;
	cin >> choice;
	switch(choice){
		case 1:
			
			s.input();
			s.WriteToFile();
			break;
			
	    case 2:
	    	Student::viewStudent();
	    	break;
	    case 3:
	    	Student::Search();
	    	break;
	    case 4:
	    	cout << "Program is terminating..." << endl;
	    	running = 0;
	    	break;
	    default:
	    	cout << "Invalid Choice" << endl;
	    
	    		
	}
	pressEnter();
}
	return 0;
}
