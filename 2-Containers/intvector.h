#pragma once

class intVector
{
	int * data;//ptr to dynamically allocated array
	size_t capacity;//total size(or rather, the capacity)
	size_t size;//total number of elements stored
public:
	intVector();
	~intVector();
	int & at(size_t idx);
	int& append(int val);
	int operator[](int idx)const;
	int&operator[](int idx);
private:
	bool grow(size_t minSize);
	int* dataptr() const;
	size_t totalCapacity() const;
	size_t getSize()const;
	bool empty() const;
	int front() const;
	int back() const;

};