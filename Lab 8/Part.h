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
	bool available(int month, int day, int year);
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

inline Part::Part(int SKU, std::string desc, double price, std::string UOM, int QOH=0, int LT=2500)
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

inline bool Part::available(int month, int day, int year)
{
	if (quantityOnHand > 0) {
		return true;
	}
	else {
		time_t now = time(0);
		int daysSince = now / 86400;
		//time_t userDate = 
		//int LTseconds = this->leadTime*

		/*int Ds;
		int daysInMonth[12];
		time_t now = time(0);
		tm* ltm = localtime(&now);
		if (ltm->tm_year % 4 == 0) {
			Ds = 365;
			daysInMonth = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		}
		else {
			Ds = 366;
			daysInMonth = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		}
		int userDays = day;
		int currDays = ltm->tm_mday;
		for (int x = 0; x < 12; x++) {
			if (x < month) {
				userDays += daysInMonth[x];
			}
			if (x < 1 + ltm->tm_mon) {
				currDays += daysInMonth[x];
			}
		}
		if (year == 1900 + ltm->tm_year) {
			return userDays > (currDays + this->getLT());
		}
		else {
			
		}*/
		
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
