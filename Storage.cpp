#include "Storage.h"
#include<iostream>
#include<fstream>
using namespace std;
//defining just example capacities for the storage
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


void Storage::putInFile(const char* fileName) {
	ofstream file(fileName);
	for (size_t i = 0; i < size; i++) {
		storedProducts[i].putInFile(fileName);
	}
	file.close();
}
void Storage::readFromFile(const char* fileName) {
	ifstream file(fileName);
	for (size_t i = 0; i < size; i++) {
		storedProducts[i].readFromFile(fileName);
	}
	file.close();
}

//functions for the interface

void Storage::printStorage() {
	for (size_t i = 0; i < size; i++) {
		cout << storedProducts[i];
	}
}
void Storage::addProduct() {
	if (size == capacity) resize();
	storedProducts[size];

	size++;
}
void Storage::removeProduct() {

}
void Storage::checkStock() {

}
void Storage::cleanUp() {

}
