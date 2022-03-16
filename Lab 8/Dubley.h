#pragma once
#include "Part.h"
#include "Node.h"

template <typename T>
class Dubley
{
public:
	Dubley() {};
	Dubley(Node<T>* start);
	~Dubley();
	void AddItem(Node<T>* var);
	Node<T>* GetItem(T var);
	Node<Part>* GetItem(int var);
	bool IsInList(int sku);
	bool IsInList(T var);
	bool IsEmpty();
	int Size();
	Node<T>* SeeNext();
	Node<T>* SeePrev();
	Node<T>* SeeAt(int var);
	void Reset();
	void printList();
private:
	Node<T>* Current = nullptr;
	Node<T>* _head = nullptr;
};

template<typename T>
inline Dubley<T>::Dubley(Node<T>* start)
{
	this->_head = start;
	this->Reset();
}

template<typename T>
inline Dubley<T>::~Dubley()
{
	while (this->_head != nullptr) {
		this->Current = this->_head->Next;
		delete this->_head;
		this->_head = this->Current;
	}
}

template<typename T>
inline void Dubley<T>::AddItem(Node<T>* var)
{
	if (this->IsEmpty()) {
		this->_head = var;
		this->Current = this->_head;
		return;
	}
	else if (this->_head->getValue() > var->getValue()) {
		this->_head->Prev = var;
		var->Next = this->_head;
		this->_head = var;
	}
	else {	
		Node<T>* temp = this->_head;
		Node<T>* addToEnd = this->_head;
		while (temp != nullptr) {
			if (temp->getValue() > var->getValue()) {
				var->Prev = temp->Prev;
				var->Next = temp;
				temp->Prev->Next = var;
				temp->Prev = var;
				return;
			}
			addToEnd = temp;
			temp = temp->Next;
		}
		addToEnd->Next = var;
		var->Prev = addToEnd;
	}
}

template<typename T>
inline Node<T>* Dubley<T>::GetItem(T var)
{
	if (this->IsEmpty()) {
		return nullptr;
	}
	Node<T>* temp = this->_head;
	if (temp->getValue() == var) {
		this->_head = this->_head->Next;
		if (this->_head != nullptr) {
			this->_head->Prev = nullptr;
		}
		return temp;
	}
	while (temp->Next != nullptr) {
		if (temp->getValue() == var) {
			temp->Prev->Next = temp->Next;
			temp->Next->Prev = temp->Prev;
			return temp;
		}
		temp = temp->Next;
	}
	if (temp->getValue() == var) {
		temp->Prev->Next = nullptr;
		return temp;
	}
	return nullptr;
}

inline Node<Part>* Dubley<Part>::GetItem(int SKU)
{
	if (this->IsEmpty()) {
		return nullptr;
	}
	Node<Part>* temp = this->_head;
	if (temp->getValue().getSKU() == SKU) {
		this->_head = this->_head->Next;
		if (this->_head != nullptr) {
			this->_head->Prev = nullptr;
		}
		return temp;
	}
	while (temp->Next != nullptr) {
		if (temp->getValue().getSKU() == SKU) {
			temp->Prev->Next = temp->Next;
			temp->Next->Prev = temp->Prev;
			return temp;
		}
		temp = temp->Next;
	}
	if (temp->getValue().getSKU() == SKU) {
		temp->Prev->Next = nullptr;
		return temp;
	}
	return nullptr;
}

template<typename T>
inline bool Dubley<T>::IsInList(T var)
{
	Node<T>* temp = this->_head;
	while (temp != nullptr) {
		if (temp->data == var)
			return true;
		temp = temp->Next;
	}
	return false;
}

inline bool Dubley<Part>::IsInList(int sku)
{
	Node<Part>* temp = this->_head;
	while (temp != nullptr) {
		if (temp->getValue().getSKU() == sku)
			return true;
		temp = temp->Next;
	}
	return false;
}

template<typename T>
inline bool Dubley<T>::IsEmpty()
{
	return this->_head == nullptr;
}

template<typename T>
inline int Dubley<T>::Size()
{
	Node<T>* temp = this->_head;
	int i = 0;
	while (temp != nullptr) {
		i++;
		temp = temp->Next;
	}
	return i;
}

template<typename T>
inline Node<T>* Dubley<T>::SeeNext()
{
	if (this->IsEmpty()) {
		return nullptr;
	}
	if (this->Current->Next == nullptr) {
		return nullptr;
	}
	this->Current = this->Current->Next;
	return Current;
}

template<typename T>
inline Node<T>* Dubley<T>::SeePrev()
{
	this->Current = this->Current->Prev;
	return this->Current->Prev;
}

template<typename T>
inline Node<T>* Dubley<T>::SeeAt(int var)
{
	if (this->Size() <= var) {
		return nullptr;
	}
	Node<T>* temp = this->_head;
	for (int i = 0; i < var; i++) {
		temp = temp->Next;
	}
	this->Current = temp;
	return temp;
}

template<typename T>
inline void Dubley<T>::Reset()
{
	this->Current = this->_head;
}

inline void Dubley<Part>::printList()
{
	Node<Part>* temp = this->_head;
	if (temp == nullptr) {
		std::cout << "\nList is empty.\n\n";
	}
	else {
		while (temp != nullptr) {
			cout << "\n\nPart Details:\n\n";
			temp->getValue().asciiART();
			temp = temp->Next;
		}
	}
}