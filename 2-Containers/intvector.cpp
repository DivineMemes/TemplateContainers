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
	return val;
}

int intVector::operator[](int idx) const
{
	assert(idx > size);
	return data[idx];
}

int & intVector::operator[](int idx)
{
	assert(idx > size);
	return data[idx];
}

void intVector::Clear(size_t size)
{
	size = 0;
}

void intVector::Erase(int idx)
{
	for (int i = idx; i < size; i++)
	{
		int temp = data[i];
		data[i] = data[i + 1];
		data[i + 1] = temp;
	}
	size--;
	data[idx] = 0;

}

int intVector::Count(int value)
{
	int counter = 0;
	for (int i = 0; i < size; ++i)
	{
		if (data[i] == value)
		{
			counter++;
		}
	}
	return counter;

}

void intVector::Insert(size_t idx, int value)
{
	append(value);
	assert(idx < size);
	for (int i = size; i > idx; i++)
	{
		int temp = data[i];
		data[i] = data[i - 1];
		data[i - 1] = temp;
	}
}

void intVector::Reserve(size_t newCapacity)
{
	if (newCapacity > capacity)
	{
		int*newData = new int[newCapacity];
		memcpy(newData, data, sizeof(int)*size);
		delete[] data;
		data = newData;
		capacity = newCapacity;
	}
}

void intVector::Compact()
{
	if (capacity > size)
	{
		int *newData = new int[size];
		memcpy(newData, data, sizeof(int)*size);
		delete[]data;
		data = newData;
		capacity = size;
	}
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
	return data[0];
}

int intVector::back() const
{
	return data[size - 1];
}
