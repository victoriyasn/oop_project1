#include"Storage.h"
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

int main() {
	Storage test;
	//test.addProduct();
	//test.addProduct();
	//test.addProduct();
	//test.checkStock();
	//test.cleanUp();
	//test.removeProduct();
	//test.printStorage();
	 
	
	//file testing code - doesnt work 

/*	ofstream out("Test");
	Product input;
	Date testDate(1, 2, 2002);
	Date testDate2(1, 1, 2002);
	input.setProductName("TestName");
	input.setExpireDate(testDate);
	input.setEntryDate(testDate2);
	input.setMadeBy("bhewj");
	input.setQuantity(3);
	Placement testPlace(1, 1, 1);
	input.setPlaceinShop(testPlace);
	input.setComment("fbhweil");

	input.putInFile(out);
	*/

}

//template for the dialog 

/*
char input[1024];
bool timeToClose = false;
 do {
	cin>>input;
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
	else if (strcmp(input, "Close") == 0) {
		timeToClose = true;
		break;
	}
	else cout << "Invalid input!";
 } while (!timeToClose);
*/