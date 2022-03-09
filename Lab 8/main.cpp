#include <string>
#include <iostream>
#include "Dubley.h"

#include "Dubley.h"

int main(void) {
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
				int sku, price, quantity;
				std::string description, units, leadTime;

				std::cout << "\nYou selected [1] AddItem. The following data will need to be provided:\n" <<
					"Stock Keeping Number | Description\n" <<
					"               Price | Unit of Measure\n" <<
					"    Quantity on Hand | Lead Time\n\n";
				std::cout << "Please provide the following data in order (one entry, no commas): SKU, Price, Quantity\n";
				std::cin >> sku, price, quantity;
				std::cout << "\n     SKU: " << sku << "\n   Price: " << price << "\nQuantity: " << quantity;

				std::cout << "\nPlease provide the following data in order (separate entries): Description, Units, Lead Time\n";
				std::getline(std::cin, description);
				std::getline(std::cin, units);
				std::getline(std::cin, leadTime);
				std::cout << "\nDescription: " << description << "\n      Units: " << units << "\n  Lead Time: " << leadTime;

				std::cout << "\nIs your item correct? [1]: yes / [0]: no | ";
				std::cin >> correct;

				//if (correct) { AddItem(Part(sku, description, price, units, quantity, leadTime)); }
			}
			break;
		case 2:
			while (correct) {
				int sku;
				std::cout << "\nYou selected [2] GetItem. Please provide a Stock Keeping Number (SKU): ";
				std::cin >> sku;
			
				std::cout << "\nYou entered: " << sku << ". Is this correct? [1]: yes / [2]: no | ";
				//if (correct) { GetItem(sku); }
			}
			break;
		case 3:
			std::cout << "\nYou selected [3] IsInList. ";



		case 4:
			std::cout << "\nYou selected [4] IsEmpty. ";
			//std::cout << IsEmpty();

		case 5:

		case 6:

		case 7:

		case 8:

		case 9:

		case 10:

		default:
			break;
		};
	
		std::cout << "\nContinue? [y/n]: ";
		std::cin >> connectionTerminated;
	
	}	
}