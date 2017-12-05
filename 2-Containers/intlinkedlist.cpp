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

