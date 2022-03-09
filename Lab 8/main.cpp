#pragma once
#include <string>
#include <iostream>
#include "Dubley.h"
#include "Part.h"

int main(void) {

	Dubley<Part> inventory = Dubley<Part>();

	bool connectionTerminated = false;
	while (!connectionTerminated) {
		std::cout << "Function Testing Menu\n\n [1] AddItem\n [2] GetItem (removes from list)\n [3] IsInList\n [4] IsEmpty\n" <<
			" [5] Size\n [6] SeeNext\n [7] SeePrev\n [8] SeeAt\n [9] Reset\n[10] Destructor\n\n";
		int choice = 0;
		std::cin >> choice;
		bool correct = true;
		switch (choice) {
		case 1:
			while (correct) {
				int sku, quantity;
				double price;
				std::string description, units, leadTime;

				std::cout << "\nYou selected [1] AddItem. The following data will need to be provided:\n" <<
					"Stock Keeping Number | Description\n" <<
					"               Price | Unit of Measure\n" <<
					"    Quantity on Hand | Lead Time\n\n";
				std::cout << "Please provide the following data in order (one entry, no commas): SKU, Price, Quantity\n";
				std::cin >> sku >> price >> quantity;
				std::cout << "\n     SKU: " << sku << "\n   Price: " << price << "\nQuantity: " << quantity;

				std::cout << "\nPlease provide the following data in order (separate entries): Description, Units, Lead Time\n";
				std::getline(std::cin, description);
				std::getline(std::cin, units);
				std::getline(std::cin, leadTime);
				std::cout << "\nDescription: " << description << "\n      Units: " << units << "\n  Lead Time: " << leadTime;

				std::cout << "\nIs your item correct? [0]: yes / [1]: no | ";
				std::cin >> correct;

				if (!correct) { inventory.AddItem(Part(sku, description, price, units, quantity, leadTime)); }
			}
			break;
		case 2:
			while (correct) {
				int sku;
				std::cout << "\nYou selected [2] GetItem. Please provide a Stock Keeping Number (SKU): ";
				std::cin >> sku;
			
				std::cout << "\nYou entered: " << sku << ". Is this correct? [0]: yes / [1]: no | ";
				std::cin >> correct;
				if (!correct) { inventory.GetItem(sku); }
			}
			break;
		case 3:
			int sku;
			std::cout << "\nYou selected [3] IsInList. Please provide a Stock Keeping Number (SKU): ";
			std::cin >> sku;
			std::cout << inventory.IsInList(sku);
			break;
		case 4:
			std::cout << "\nYou selected [4] IsEmpty. | " << inventory.IsEmpty();
			break;
		case 5:
			std::cout << "\nYou selected [5] Size. | " << inventory.Size();
			break;
		case 6:
			std::cout << "\nYou selected [6] SeeNext. | " << inventory.SeeNext();
			break;
		case 7:
			std::cout << "\nYou selected [7] SeePrev. | " << inventory.SeePrev();
		case 8:
			std::cout << "\nYou selected [8] SeeAt. | " << inventory.SeeAt();
		case 9:
			while (correct) {
				std::cout << "\nYou selected [9] Reset. Are you sure? [0]: yes / [1]: no";
				std::cin >> correct;
				if (!correct) { inventory.Reset(); }
			}
			break;
		default:
			continue;
		};
	
		std::cout << "\nContinue? [y/n]: ";
		std::cin >> connectionTerminated;
	
	}	
}