#pragma once
#include "Part.h"
#include "Node.h"

template <typename T>
class Dubley
{
public:
	Dubley();
	~Dubley();
	void AddItem(T var);
	Node* GetItem(T var);
	bool IsInList(T var);
	bool IsEmpty();
	int Size();
	Node* SeeNext();
	Node* SeePrev();
	Node* SeeAt(int var);
	void Reset();
private:
	Node* Current
};

template<typename T>
inline Dubley<T>::Dubley()
{
}

template<typename T>
inline Dubley<T>::~Dubley()
{
}

template<typename T>
inline void Dubley<T>::AddItem(T var)
{
}

template<typename T>
inline Node* Dubley<T>::GetItem(T var)
{
	return nullptr;
}

template<typename T>
inline bool Dubley<T>::IsInList(T var)
{
	return false;
}

template<typename T>
inline bool Dubley<T>::IsEmpty()
{
	return false;
}

template<typename T>
inline int Dubley<T>::Size()
{
	return 0;
}

template<typename T>
inline Node* Dubley<T>::SeeNext()
{
	return nullptr;
}

template<typename T>
inline Node* Dubley<T>::SeePrev()
{
	return nullptr;
}

template<typename T>
inline Node* Dubley<T>::SeeAt(int var)
{
	return nullptr;
}

template<typename T>
inline void Dubley<T>::Reset()
{
}
