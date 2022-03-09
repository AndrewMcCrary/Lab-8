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
	Node<T>* temp = this->_head;
	while (temp != nullptr) {
		if (temp->getValue() > var->getValue()) {
			// Stick in middle or first
			if (temp->Prev != nullptr)
				temp->Prev->Next = var;
			else
				this->_head = var;

			temp->Prev = var;
		}
		else if (temp->Next == nullptr) {
			// Stick on end
			temp->Next = var;
		}

		temp = temp->Next;
	}

	// Temp should be shifted behind the new node

}

template<typename T>
inline Node<T>* Dubley<T>::GetItem(T var)
{
	if (this->IsEmpty())
		return nullptr;

	Node<T>* temp = this->_head;
	if (temp->data == var)
		return temp;
	do
	{
		temp = temp->Next;
		if (temp->data == var)
			return temp;
	} while (temp->Next);
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
		temp = temp->Next
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
	return this->Current->Prev;
}

template<typename T>
inline Node<T>* Dubley<T>::SeeAt(int var)
{
	if (this->Size() >= var)
		return nullptr;

	Node<T>* temp = Current;
	while (temp != nullptr)
		temp = temp->Prev;

	for (int i = 0; i < var; i++)
		temp = temp->Next;

	return temp;
}

template<typename T>
inline void Dubley<T>::Reset()
{
	this->Current = this->_head;
}
