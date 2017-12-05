#pragma once

class intLinkedList
{

public:

	struct intLinkedListNode
	{
		int value;
		intLinkedListNode* next;
	};

	intLinkedList();
	~intLinkedList();
	
	void append(int value);
	int at(int index);
	
	size_t size() const;
	bool empty() const;
	int front()const;
	int back()const;

	int operator[](int idx)const;
	int&operator[](int idx);

private:
	
	intLinkedListNode* head;

};