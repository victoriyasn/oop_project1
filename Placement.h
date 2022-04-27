#ifndef __PLACEMENT_H
#define __PLACEMENT_H

class Placement {
private :
	size_t sectionNum;
	size_t shelfNum;
	size_t capacityTaken;
	size_t productNum;
public :
	Placement();
	void setSectionNum(const size_t);
	void setShelfNum(const size_t);
	void setCapacityTaken(const size_t);
	void setProductNum(const size_t);
	size_t getSectionNum() const;
	size_t getShelfNum() const;
	size_t getCapacityTaken()const;
	size_t getProductNum() const;
	bool operator==(const Placement&)const;
	bool operator!=(const Placement&)const;
};
#endif