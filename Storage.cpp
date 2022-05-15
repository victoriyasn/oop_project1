#include "Storage.h"
#include<iostream>
#include<fstream>
using namespace std;
//defining just example capacities for the storage
#define onShelfCapacity 20
#define shelfCapacity 20
#define sectionCapacity 10



void Storage::resize() {
	capacity *= 2;
	Product* newArr = new Product[capacity];
	for (size_t i = 0; i < size; i++) {
		newArr[i] = storedProducts[i];
	}
	delete[]storedProducts;
	storedProducts = newArr;
}
void Storage::copyFrom(const Storage& other) {
	size = other.size;
	capacity = other.capacity;
	storedProducts = new Product[capacity];
	for (size_t i = 0; i < size; i++) {
		storedProducts[i] = other.storedProducts[i];
	}
}
void Storage::freeMemory() {
	delete[] storedProducts;
	size = 0;
}

Storage::Storage() {
	capacity = 10;
	storedProducts = new Product[capacity];
	size = 0;
	modifSize = 0;
	modifications[0].setProduct("None");
	Date defModifDate;
	defModifDate.setYear(2000);
	defModifDate.setMonth(1);
	defModifDate.setYear(1);
	modifications[0].setModifDate(defModifDate);
	modifications[0].setQuantity(0);
	modifications[0].setInOrOut(1);
}
Storage::Storage(const Storage& other) {
	copyFrom(other);
}
Storage& Storage::operator=(const Storage& other) {
	if (this != &other) {
		freeMemory();
		copyFrom(other);
	}
	return *this;
}
Storage::~Storage() {
	freeMemory();
}


void Storage::putInFile(ofstream& out) {
	out << size << ',';
	for (size_t i = 0; i < size; i++) {
	storedProducts[i].putInFile(out);
	}
}
void Storage::readFromFile(ifstream& in) {
	in >> size;
	in.get();
	capacity = size;
	storedProducts = new Product[capacity];
	for (size_t i = 0; i < size; i++) {
		storedProducts[i].readFromFile(in);
		in.get();
	}
}

//functions for the interface


void Storage::printStorage() {
	cout << endl;
	for (size_t i = 0; i < size; i++) {
		cout << storedProducts[i] << endl;
	}

}
void Storage::addProduct() {
	
	if (size == capacity) resize();
	Product addProduct;

	char* temp = new char[128];
	cout << "Enter product name: " << endl;
	cin.getline(temp, 128) ;
	addProduct.setProductName(temp);
	
	modifications[modifSize].setProduct(temp);

	Date tempDate;
	cout << "Enter expire date: " << endl;
	cin >> tempDate;
	addProduct.setExpireDate(tempDate);

	cout << "Enter entry date: " << endl;
	cin >> tempDate;
	addProduct.setEntryDate(tempDate);
	modifications[modifSize].setModifDate(tempDate);

	cout << "Made by: " << endl;
	cin.ignore();
	cin.getline(temp, 128);
	addProduct.setMadeBy(temp);

	size_t tempQuantity;
	cout << "Enter quantity: " << endl;
	cin >> tempQuantity;
	addProduct.setQuantity(tempQuantity);
	modifications[modifSize].setQuantity(tempQuantity);

	Placement tempPlace;
	cout << "Enter placement:" << endl;
	cin >> tempPlace;
	addProduct.setPlaceinShop(tempPlace);

	cout << "Enter comment: " << endl;
	cin.ignore();
	cin.getline(temp, 128);
	addProduct.setComment(temp);

	modifications[modifSize].setInOrOut(1);

	storedProducts[size] = addProduct;
	modifSize++;
	size++;
	
	delete[]temp;
}
void Storage::removeProduct() {

	char removeProduct[64];
	size_t quantityRemoved = 0;
	bool isEmpty = false;
	size_t index = 0;
	bool remove;
	bool sameProduct = false;
	cout << "Please enter the name of the product you want to remove: " << endl;
	cin.getline(removeProduct, 64);
	cout << "Please enter the quantity you want to remove: " << endl;
	cin >> quantityRemoved;
	size_t indExpDate = 0;
	Date modificationDate;
	cout << "Enter the date of the modification: " << endl;
	cin >> modificationDate;


	for (size_t i = 0; i < size; i++) {
		
		if (storedProducts[i].getProductName() == removeProduct) {
			modifications[modifSize].setProduct(removeProduct);
			modifications[modifSize].setQuantity(quantityRemoved);
			modifications[modifSize].setModifDate(modificationDate);
			modifications[modifSize].setInOrOut(0);
			modifSize++;
			for (size_t j = i + 1; j < size; j++) {
				if (storedProducts[i].getProductName() == storedProducts[j].getProductName()) {
					sameProduct = true;
					if (storedProducts[i].getExpireDate() > storedProducts[j].getExpireDate()) {
						i = j;
						indExpDate = j;
					}
					else indExpDate = i;
				}
			}
			if (sameProduct) {
				storedProducts[indExpDate].setQuantity(storedProducts[i].getQuantity() - quantityRemoved);
				cout <<"Name: "<< storedProducts[indExpDate].getProductName() << endl;
				cout <<"Placement: "<< storedProducts[indExpDate].getPlacement() << endl;
				cout<<"Quantity: "<<storedProducts[indExpDate].getQuantity() << endl;;
			}
			else {
				if (storedProducts[i].getQuantity() >= quantityRemoved) {
					storedProducts[i].setQuantity(storedProducts[i].getQuantity() - quantityRemoved);
					cout << storedProducts[i];
					if (storedProducts[i].getQuantity() == 0) {
						isEmpty = true;
						index = i;
					}
				}
				else {
					cout << "Invalid quantity";
					cout << storedProducts[i];
					cout << "Do you want to remove everything left? 1 for yes, 0 for no";
					cin >> remove;
					if (remove) {
						storedProducts[i].setQuantity(0);
						isEmpty = true;
						index = i;
					}
				}
			}
		} 
	}
	
	
	if (isEmpty) {
		Product* newStore;
		newStore = new Product[capacity];
		size_t get = 0;
		for (size_t i = 0; i < size; i++) {
			if (i != index) {
			
				newStore[get] = storedProducts[i];
				++get;
			}

		}
		cout << get;
		delete[]storedProducts;
		storedProducts = newStore;
		size = get;
	}
	
}
void Storage::checkStock() {
	Date start;
	Date end;
	cout << "Enter start of period: " << endl;
	cin >> start;
	cout << "Enter end of period:" << endl;
	cin >> end;

	for (size_t i = 0; i < modifSize; i++) {
		
		if (modifications[i].getModifDate() >= start && modifications[i].getModifDate() <= end) {
			cout << "Product: " << modifications[i].getProduct() << endl;
			cout << "Modification date: " << modifications[i].getModifDate() << endl;
			cout << "Change: ";
			if (modifications[i].getInOrOut()) cout << "+";
			else cout << "-";
			cout << modifications[i].getQuantity() << endl;
		}
		else continue;
	}
}
void Storage::cleanUp() {
	Date cleanDate;
	Product* newStore;
	newStore = new Product[capacity];

	cout << "Please enter clean up date: " << endl;
	cin >> cleanDate;
	size_t get = 0;
	for (size_t i = 0; i < size; i++) {
		if (storedProducts[i].getExpireDate() > cleanDate) {
			newStore[get] = storedProducts[i];
			++get;
		}
		
	}
	delete[]storedProducts;
	storedProducts = newStore;
	size = get;

	char fileName[23];
	fileName[0] = '\0';
	strcat_s(fileName, strlen("cleanup-") + 1, "cleanup-");

	char chYear[5];
	char chMonth[3];
	char chDay[3];
	chYear[0] = '\0';
	chMonth[0] = '\0';
	chDay[0] = '\0';
	_itoa_s(cleanDate.getYear(), chYear, 10);
	_itoa_s(cleanDate.getMonth(), chMonth, 10);
	_itoa_s(cleanDate.getDay(), chDay, 10);
	strcat_s(fileName, sizeof(fileName), "2002");
	strcat_s(fileName, sizeof(fileName), "-");
	strcat_s(fileName, sizeof(fileName), chMonth);
	strcat_s(fileName, sizeof(fileName), "-");
	strcat_s(fileName, sizeof(fileName), chDay);
	strcat_s(fileName, sizeof(fileName), ".txt");
	
	ofstream file(fileName);
	for (size_t i = 0; i < size; i++) {
		cout << fileName;
		file << storedProducts[i];
	}

	file.close();

}
