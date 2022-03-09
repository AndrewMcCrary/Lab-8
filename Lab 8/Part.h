#pragma once
#include <string>
#include <ctime>

class Part
{
public:
	Part();
	Part(int SKU, std::string desc, double price, std::string UOM, int QOH = 0, int LT=2500);
	std::string getPartInfo();
	double getPrice();
	int getSKU();
	int getLT();
	bool inStock();
	bool available(int daysFromNow);
	bool operator==(Part temp);
	bool operator<(Part temp);
	bool operator>(Part temp);

private:
	int SKU;
	std::string description;
	double price;
	std::string UOM;
	int quantityOnHand;
	int leadTime;
};

Part::Part()
{
}

inline Part::Part(int SKU, std::string desc, double price, std::string UOM, int QOH=0, int LT=5000)
{
	this->SKU = SKU;
	this->description = desc;
	this->price = price;
	this->UOM = UOM;
	this->quantityOnHand = QOH;
	this->leadTime = LT;
}

inline std::string Part::getPartInfo()
{
	return std::to_string(SKU) + " " + description;
}

inline double Part::getPrice()
{
	return this->price;
}

inline int Part::getSKU()
{
	return this->SKU;
}

inline int Part::getLT()
{
	return this->leadTime;
}

inline bool Part::inStock()
{
	return quantityOnHand > 0;
}

inline bool Part::available(int daysFromNow)
{
	if (quantityOnHand > 0) {
		return true;
	}
	else {
		long int now = static_cast<long int> (time(NULL));
		long int userDesiredDate = (now / 86400) + daysFromNow;
		long int availableDate = (now / 86400) + this->leadTime;
		return userDesiredDate >= availableDate;
	}
}

inline bool Part::operator==(Part temp)
{
	return this->getSKU() == temp.getSKU();
}

inline bool Part::operator>(Part temp)
{
	return this->getSKU() > temp.getSKU();
}

inline bool Part::operator<(Part temp)
{
	return this->getSKU() < temp.getSKU();
}
