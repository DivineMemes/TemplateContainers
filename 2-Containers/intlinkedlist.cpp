#include "intlinkedlist.h"
#include <cassert>
intLinkedList::intLinkedList()
	:head(nullptr)
{

}

intLinkedList::~intLinkedList()
{
	intLinkedListNode* iter = head;
	while (iter != nullptr)
	{
		intLinkedListNode* next = iter->next;
		delete[] iter;
		iter = next;
	}

}

void intLinkedList::append(int value)
{
	intLinkedListNode* newNode = new intLinkedListNode;
	newNode->value = value;
	newNode->next = nullptr;
	newNode->prev = nullptr;
	if (head == nullptr)
	{
		head = newNode;
	}
	else
	{
		intLinkedListNode* iter = head;
		while (iter->next != nullptr)
		{
			iter = iter->next;
		}
		iter->next = newNode;
	}
}

int intLinkedList::at(int index)
{
	intLinkedListNode* iter = head;
	int iterationCount = 0;
	while (iterationCount != index && iter != nullptr)
	{
		iterationCount++;
		iter = iter->next;

	}
	assert(iter != nullptr);
	return iter->value;
}

size_t intLinkedList::size() const
{
	intLinkedListNode* iter = head;
	int iterationCount = 0;
	while (iter != nullptr)
	{
		iterationCount++;
		iter = iter->next;
	}
	assert(iter != nullptr);
	return iterationCount;
}

bool intLinkedList::empty() const
{
	intLinkedListNode* iter = head;
	if (iter = nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int intLinkedList::front() const
{
	assert(!empty());
	return head->value;

}

int intLinkedList::back() const
{
	assert(!empty());
	intLinkedListNode* iter = head;
	while (iter->next != nullptr)
	{
		iter = iter->next;

	}
	return iter->value;
}

void intLinkedList::clear()
{
	intLinkedListNode* iter = head;
	while (iter->next != nullptr)
	{
		intLinkedListNode* next = iter->next;
		delete[] iter;
		iter = next;
	}
	head = nullptr;
}

void intLinkedList::erase(size_t idx)
{
	assert(idx < size());
	intLinkedListNode*iter = head;
	intLinkedListNode*prev = head;
	int counter = 0;

	while (iter->next != nullptr&& counter != idx)
	{
	
		iter = iter->next;
		counter++;
	}
	iter->prev->next = iter->next;
	if (idx == 0)
	{
		head = iter->next;
	}
	delete iter;
}

int intLinkedList::Count(int value)
{
	intLinkedListNode*iter = head;
	int counter = 0;
	while (iter->next != nullptr)
	{
		if (iter->value == value)
		{
			counter++;
		}
		iter = iter->next;
	}
	return 0;
}

void intLinkedList::insert(size_t idx, int value)
{
	intLinkedListNode*newNode = new intLinkedListNode;
	newNode->value = value;
	intLinkedListNode*iter = head;
	
	int counter = 0;
	while (iter->next != nullptr && counter != idx)
	{
		
		iter = iter->next;
		counter++;
	}
	iter->prev->next = newNode;
	newNode->next = iter;
	newNode->prev = iter->prev;
}


int intLinkedList::operator[](int idx) const
{
	intLinkedListNode* iter = head;
	
	for(int i = 0; i < idx; ++i)
	{
		
		iter = iter->next;

	}
	assert(iter != nullptr);
	return iter->value;
}

int & intLinkedList::operator[](int idx)
{

	intLinkedListNode* iter = head;
	
	for(int i = 0; i < idx; ++i)
	{
		iter = iter->next;
	}
	assert(iter != nullptr);
	return iter->value;
}

