#pragma once
#include "tvector.h"
template <typename T>
class Stack
{
private:
	tVector<T> vector;
public:
	//top is size -1

	//empty

	bool empty()
	{
		return vector.empty();
	}

	//size
	T size()
	{
		return vector.size();
	}
	//pop 
	T pop()
	{

	}
	// - return the thing that was popped


	//push
	void push()
	{
		return vector.data[capacity + 1];
	}
	//- add element to the top of the stack
	
	//Top
	T Top()
	{
		return vector.data[size - 1];
	}
	// - access top of the stack
};