#pragma once

template <typename T>
class Node
{
public:
	Node(Node* _next = nullptr, Node* _prev = nullptr);
	~Node();
	Node* Next = nullptr;
	Node* Prev = nullptr;
	T getValue();
	void setValue(T var);
private:
	T data;
};

template<typename T>
inline Node<T>::Node(Node* _next, Node* _prev)
{
	this->Next = _next;
	this->Prev = _prev;
}

template<typename T>
inline Node<T>::~Node()
{
	if (this->Prev != nullptr)
		this->Prev->Next = this->Next;
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