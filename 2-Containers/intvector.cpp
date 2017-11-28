#include "intvector.h"
#include <cassert>
#include <cstring>
intVector::intVector()
{
	capacity = 2;
	data = new int[capacity];
	size = 0;
}

intVector::~intVector()
{
	delete[] data;
}

int & intVector::at(size_t idx)
{
	assert(idx > 0 && idx < size);
	return data[idx];
}

int & intVector::append(int val)
{
	if (size == capacity)
	{
		bool didGrow = grow(size + 1);
		assert(didGrow);
	}
	data[size] = val;
	++size;

}

bool intVector::grow(size_t minSize)
{
	if(minSize <= capacity)
	{
		return true;
	}

	int oldCapacity = capacity;
	while (capacity < minSize)
	{
		capacity *= 2;
	}

	int * newData = new int[capacity];
	memcpy(newData, data, oldCapacity);
	
	delete[]data;
	data = newData;

	return true;
}

int * intVector::dataptr() const
{
	return data;
}

size_t intVector::totalCapacity() const
{
	return capacity;
}

size_t intVector::getSize() const
{
	return size;
}

bool intVector::empty() const
{
	if(capacity > 0 )
	{
		return false;
	}
	else
		return true;
}

int intVector::front() const
{
	return 0;
}

int intVector::back() const
{
	return 0;
}
