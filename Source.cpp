#include"Storage.h"
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

int main() {
	Storage test;

	char input[1024];
	bool timeToClose = false;
	char fileName[128];
	 do {
		cin.getline(input, 1024);
		if (strcmp(input, "Print") == 0) {
			test.printStorage();
		}
		else if (strcmp(input, "Add") == 0) {
			test.addProduct();
		}
		else if (strcmp(input, "Remove") == 0) {
			test.removeProduct();
		}
		else if (strcmp(input, "Check") == 0) {
			test.checkStock();
		}
		else if (strcmp(input, "Clean") == 0) {
			test.cleanUp();
		}
		else if (strcmp(input, "PutInFile") == 0) {
			cin.ignore();
			cin.getline(fileName, 128);
			ofstream file(fileName);
			test.putInFile(file);
		}
		else if (strcmp(input, "ReadFromFile") == 0) {
			cin.ignore();
			cin.getline(fileName, 128);
			ifstream file(fileName);
			test.readFromFile(file);
		}
		else if (strcmp(input, "Close") == 0) {
			timeToClose = true;
			break;
		}
		
	 } while (!timeToClose);

}
