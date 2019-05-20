#pragma once
#include <iostream>
#include "pair.h"
using namespace std;

template<class T>
class PairChild : public Pair<T>
{
public:
	PairChild();
	PairChild(T f, T s, double correlation);
	~PairChild();
	void setFirst(T f);
	void setSecond(T s);
	void setThird(double correlation);
	T getFirst() const;
	T getSecond() const;
	double getThird() const;
private:
	T m; T u;
	double m_correlation;
};

template<class T>
PairChild<T>::PairChild()
{
}

template<class T>
PairChild<T>::PairChild(T f, T s, double correlation)
{
	m = f;
	u = s;
	m_correlation = correlation;
}

template<class T>
void PairChild<T>::setFirst(T f)
{
	m = f;
}

template<class T>
void PairChild<T>::setSecond(T s)
{
	u = s;
}

template<class T>
void PairChild<T>::setThird(double correlation)
{
	m_correlation = correlation;
}

template<class T>
T PairChild<T>::getFirst() const
{
	return m;
}

template<class T>
T PairChild<T>::getSecond() const
{
	return u;
}

template<class T>
double PairChild<T>::getThird() const
{
	return m_correlation;
}

template<class T>
PairChild<T>::~PairChild()
{

}