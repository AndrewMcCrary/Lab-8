#pragma once
#include "Part.h"

template <typename T>
class Dubley
{
public:
	Dubley();
	~Dubley();
	void AddItem(T var);
	T* GetItem(T var);
	bool IsInList(T var);
	bool IsEmpty();
	int Size();
	T* SeeNext();
	T* SeePrev();
	T* SeeAt();
	void Reset();
private:

};

template<typename T>
inline Dubley<T>::Dubley()
{
}
