#pragma once

template <typename T>
class Node
{
public:
	Node(T _data);
	~Node();
	Node* Next = nullptr;
	Node* Prev = nullptr;
	T getValue();
	void setValue(T var);
private:
	T data;
};

template<typename T>
inline Node<T>::Node(T _data)
{
	this->data = _data;
}

template<typename T>
inline Node<T>::~Node()
{
	if (this->Next && this->Prev) {
		this->Prev->Next = this->Next;
		this->Next->Prev = this->Prev;
	}
}

template<typename T>
inline T Node<T>::getValue()
{
	return this->data;
}

template<typename T>
inline void Node<T>::setValue(T var)
{
	this->data = var;
}