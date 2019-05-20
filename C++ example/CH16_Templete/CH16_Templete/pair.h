#pragma once
#include <iostream>
using namespace std;

template<class T>
class Pair
{
public:
	Pair();
	Pair(T firstVal, T secondVal);
	~Pair();
	void setFirst(T newVal);
	void setSecond(T newVal);
	T getFirst() const;
	T getSecond() const;
private:
	T first;
	T second;
};

template<class T>
Pair<T>::Pair()
{
}

template<class T>
Pair<T>::Pair(T firstVal, T secondVal)
{
	first = firstVal;
	second = secondVal;
}
template<class T>
void Pair<T>::setFirst(T newVal)
{
	first = newVal;
}
template<class T>
void Pair<T>::setSecond(T newVal)
{
	second = newVal;
}

template<class T>
T Pair<T>::getFirst() const
{
	return first;
}
template<class T>
T Pair<T>::getSecond() const
{
	return second;
}
template<class T>
Pair<T>::~Pair()
{
}