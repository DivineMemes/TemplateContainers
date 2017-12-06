#pragma once
#include "tvector.h"

template <typename T>

class iterator
{
public:
	iterator() = delete;
	iterator(T& container, int initialIndex)
		:owningContainer(container)
		, currentIndex(initialIndex)
	{

	}

	iterator(const iterator<T>&other)
		:owningContainer(other.owningContainer)
		, currentIndex(other.currentIndex)
	{

	}
	iterator<T>& operator=(const iterator<T>& other)
	{
		owningContainer = other.owningContainer;
		currentIndex = other.currentIndex;
	}

	bool operator==(const iterator<T>&other);
	bool operator!=(const iterator<T>&other);

	auto& operator*();
	iterator<T>& operator++();
	iterator<T>& operator++(int previousValue);

private:
	T& owningContainer;
	int			currentIndex;
};

template<typename T>
inline bool iterator<T>::operator==(const iterator<T>& other)
{
	bool isSameContainer = owningContainer == other.owningContainer;
	bool isSameIndex = currentIndex == other.currentIndex;

	return isSameContainer&&isSameContainer;
}

template<typename T>
inline bool iterator<T>::operator!=(const iterator<T>& other)
{
	bool isSameContainer = owningContainer == other.owningContainer;
	bool isSameIndex = currentIndex == other.currentIndex;

	return !isSameContainer||!isSameContainer;
}

template<typename T>
inline auto & iterator<T>::operator*()
{
	return owningContainer->at(currentIndex);
}

template<typename T>
inline iterator<T> & iterator<T>::operator++()
{
	++currentIndex;
	return *this;
}

template<typename T>
inline iterator<T>& iterator<T>::operator++(int previousValue)
{
	iterator<T> tmp(owningContainer, currentIndex);
	operator++();
	return tmp;
}
