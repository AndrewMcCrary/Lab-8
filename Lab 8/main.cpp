#include <iostream>
#include "Dubley.h"

int main(void) {
	Dubley<int> d = Dubley<int>();

	Node<int>* n = new Node<int>(5);

	d.AddItem(n);



	return 0;
}