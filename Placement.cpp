#include "Placement.h"

Placement::Placement() {
	sectionNum = 0;
	shelfNum = 0;
	capacityTaken = 0;
	productNum = 0;
}
void Placement::setSectionNum(const size_t newSect) {
	sectionNum = newSect;
}
void Placement::setShelfNum(const size_t newShelf) {
	shelfNum = newShelf;
}
void Placement::setCapacityTaken(const size_t newCapacity) {
	capacityTaken = newCapacity;
}
void Placement::setProductNum(const size_t newProd) {
	productNum = newProd;
}
size_t Placement::getSectionNum() const {
	return sectionNum;
}
size_t Placement::getShelfNum() const {
	return shelfNum;
}
size_t Placement::getCapacityTaken()const {
	return capacityTaken;
}
size_t Placement::getProductNum() const {
	return productNum;
}

bool Placement::operator==(const Placement& other) const {
	return sectionNum == other.sectionNum && shelfNum == other.shelfNum && productNum == other.productNum;
}
bool Placement::operator!=(const Placement& other) const {
	return !(this == &other);
}