#pragma once

template<typename T>
class tVector
{
	T * data;
	size_t capacity;
	size_t size;

public:
	tVector();	
	~tVector();

	T& at(size_t idx);
	T& append(T val);
	T *c_ptr() const;
	size_t getCapacity() const;
	size_t getSize() const;
	bool empty() const;
	T front() const;
	T back() const;
	void pop(T idx);
};
template<typename T>
tVector::tVector()
{
	delete[] data;
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
	if (capacity > 0)
	{
		return false;
	}
	else
		return true;
}

template<typename T>
inline T tVector<T>::front() const
{
	return data[0];
}

template<typename T>
inline T tVector<T>::back() const
{
	return data[size-1];
}

template<typename T>
inline void tVector<T>::pop(T idx)
{
	
}
