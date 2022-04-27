#include "Storage.h"


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

