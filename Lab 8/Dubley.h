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
		return;
	}
	else if (this->_head->getValue() > var->getValue()) {
		this->_head->Prev = var;
		var->Next = this->_head;
		this->_head = var;
	}
	else {	
		Node<T>* temp = this->_head;
		while (temp != nullptr) {
			if (temp->getValue() > var->getValue()) {
				var->Prev = temp->Prev;
				var->Next = temp;
				temp->Prev->Next = var;
				temp->Prev = var;
				return;
			}

			temp = temp->Next;
		}
	}
}

template<typename T>
inline Node<T>* Dubley<T>::GetItem(T var)
{
	Node<T>* temp = this->_head;
	while (temp != nullptr) {
		if (temp->getValue() == var)
			return temp;
		temp = temp->Next;
	}
	return nullptr;
}

inline Node<Part>* Dubley<Part>::GetItem(int SKU)
{
	Node<Part>* temp = this->_head;
	while (temp != nullptr) {
		if (temp->getValue().getSKU() == SKU)
			return temp;
		temp = temp->Next;
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
	if (this->Size() >= var)
		return nullptr;

	Node<T>* temp = _head;
	for (int i = 0; i < var; i++)
		temp = temp->Next;

	return temp;
}

template<typename T>
inline void Dubley<T>::Reset()
{
	this->Current = this->_head;
}
