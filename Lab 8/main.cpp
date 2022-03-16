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
			" [5] Size\n [6] SeeNext\n [7] SeePrev\n [8] SeeAt\n [9] Reset\n[10] Destructor\n[11] ASCII Art\n\n";
		int choice = 0;
		std::cin >> choice;
		bool correct = true;
		switch (choice) {
		case 1:
			while (correct) {
				int sku, quantity, leadTime;
				double price;
				std::string description, units;

				std::cout << "\nYou selected [1] AddItem. The following data will need to be provided:\n" <<
					"Stock Keeping Number | Description\n" <<
					"               Price | Unit of Measure\n" <<
					"    Quantity on Hand | Lead Time (hours)\n\n";
				std::cout << "Please provide the following data in order (one entry, no commas): SKU, Price, Quantity, Lead Time\n";
				std::cin >> sku >> price >> quantity >> leadTime;
				std::cout << "\n     SKU: " << sku << "\n   Price: " << price << "\nQuantity: " << quantity;

				std::cout << "\nPlease provide the following data in order (separate entries): Description, Units, Lead Time\n";
				cin.ignore();
				std::getline(std::cin, description);
				std::getline(std::cin, units);
				std::cout << "\nDescription: " << description << "\n      Units: " << units << "\n  Lead Time: " << leadTime;

				std::cout << "\nIs your item correct? [0]: yes / [1]: no | ";
				std::cin >> correct;

				if (!correct) { inventory.AddItem(new Node<Part>(Part(sku, description, price, units, quantity, leadTime))); }
			}
			break;
		case 2:
			while (correct) {
				int sku;
				std::cout << "\nYou selected [2] GetItem. Please provide a Stock Keeping Number (SKU): ";
				std::cin >> sku;
			
				std::cout << "\nYou entered: " << sku << ". Is this correct? [0]: yes / [1]: no | ";
				std::cin >> correct;
				if (!correct) { 
					if (inventory.IsInList(sku) == 0) {
						cout << "\nItem may not be in list, also check if list is empty.\n";
					}
					else {
						inventory.GetItem(sku)->getValue().asciiART();
					}
				}
			}
			break;
		case 3:
			int sku;
			std::cout << "\nYou selected [3] IsInList. Please provide a Stock Keeping Number (SKU): ";
			std::cin >> sku;
			if (inventory.IsInList(sku) == 0) {
				std::cout << sku << " is NOT in list." << endl;
			}
			else {
				std::cout << sku << " is in list." << endl;
			}
			break;
		case 4:
			std::cout << "\nYou selected [4] IsEmpty." << endl;
			if (inventory.IsEmpty() == 0) {
				std::cout << "List is NOT empty." << endl;
			}
			else {
				std::cout << "List is empty." << endl;
			}
			break;
		case 5:
			std::cout << "\nYou selected [5] Size. | Size is: " << inventory.Size() << endl;
			break;
		case 6:
			std::cout << "\nYou selected [6] SeeNext. | \n";
			
			inventory.SeeNext()->getValue().asciiART();
			break;
		case 7:
			std::cout << "\nYou selected [7] SeePrev. | " << inventory.SeePrev();
		case 8:
			int viewIndex;
			std::cout << "\nYou selected [8] SeeAt. Please provide an index to view: ";
			std::cin >> viewIndex;
			inventory.SeeAt(viewIndex)->getValue().asciiART();
			break;
		case 9:
			while (correct) {
				std::cout << "\nYou selected [9] Reset. Are you sure? [0]: yes / [1]: no";
				std::cin >> correct;
				if (!correct) { inventory.Reset(); }
			}
			break;
		case 10:
			// Must add Destructor option implementation
			break;
		case 11:
			std::cout << "\nYou selected [11] ASCII Art.\n\n";
			inventory.printList();
		default:
			continue;
		};
	
		std::cout << "\nContinue? [0 = yes/1 = no]: ";
		std::cin >> connectionTerminated;
	
	}	
}