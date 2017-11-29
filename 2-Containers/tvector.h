#pragma once

template<typename T>
class tVector
{
	T * data;
	size_t capacity;
	size_t size;
	bool grow(size_t minSize);
public:
	tVector();	
	~tVector();

	void insert(size_t idx, T value);
	void clear();
	T& at(size_t idx);
	T& append(T val);
	T *c_ptr() const;
	
	void compact();
	void reserve(size_t newCapacity);

	size_t getCapacity() const;
	size_t getSize() const;
	bool empty() const;
	
	T front() const;
	T back() const;
	void pop();
	void erase(size_t idx);
	size_t count(T val) const;
};
template<typename T>
tVector::tVector()
{
	delete[] data;
}

template<typename T>
inline void tVector<T>::insert(size_t idx, T value)
{
	append(value);
	assert(idx < size);
	for (size_t i = size; i > idx; i++)
	{
		T temp = data[i];
		data[i] = data[i - 1];
		data[i - 1] = temp;
	}
}

template<typename T>
inline void tVector<T>::clear()
{
	size = 0;
}

template<typename T>
inline T & tVector<T>::at(size_t idx)
{
	assert(idx > 0 && idx < size);
	return data[idx];
}

template<typename T>
inline T & tVector<T>::append(T val)
{
	if (size == capacity)
	{
		bool didGrow = grow(size + 1);
		assert(didGrow);
	}
	data[size] = val;
	++size;
}

template<typename T>
inline T * tVector<T>::c_ptr() const
{
	return data;
}

template<typename T>
inline void tVector<T>::compact()
{
	if (capacity > size)
	{
		T *newData = new T[size];
		memcpy(newData, data, sizeof(int)*size);
		delete[]data;
		data = newData;
		capacity = size;
	}
}

template<typename T>
inline void tVector<T>::reserve(size_t newCapacity)
{
	assert(newCapacity > capacity);
	if (newCapacity > capacity)
	{
		T*newData = new T[newCapacity];
		memcpy(newData, data, sizeof(int)*size);
		delete[] data;
		data = newData;
		capacity = newCapacity;
	}
}

template<typename T>
inline size_t tVector<T>::getCapacity() const
{
	return capacity;
}

template<typename T>
inline size_t tVector<T>::getSize() const
{
	return size;
}

template<typename T>
inline bool tVector<T>::empty() const
{
	return size > 0;
}
template<typename T>
inline T tVector<T>::front() const
{
	return data[0];
}

template<typename T>
inline T tVector<T>::back() const
{
	assert(size > 0);
	return data[size-1];
}

template<typename T>
inline void tVector<T>::pop()
{
	size -= 1;
}

template<typename T>
inline void tVector<T>::erase(size_t idx)
{
	for (size_t i = idx; i < size; i++)
	{
		int temp = data[i];
		data[i] = data[i + 1];
		data[i + 1] = temp;
	}
	size--;
	data[idx] = 0;
}

template<typename T>
inline size_t tVector<T>::count(T val) const
{
	size_t counter = 0;
	for (size_t i = 0; i < sizel i++)
	{
		if (data[i] == value)
		{
			counter++;
		}

	}
	return counter;
}
template<typename T>
inline bool tVector<T>::grow(size_t minSize)
{
	assert(minSize <= 64000);
	if (minSize <= capacity)
	{
		return true;
	}
	while (capacity < minSize)
	{
		capacity *= 2;
	}
	T*newData = new T[capacity];
	memcpy(newData, data, sizeof(T) * size);
	delete[] data;
	data = newData;
	return true;
}
