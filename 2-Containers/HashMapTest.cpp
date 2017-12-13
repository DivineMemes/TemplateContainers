#include "KeyHash.h"
#include "HashMap.h"
#include "HashNode.h"
#include <cstring>
#include <string>
#include <iostream>

struct MyKeyHash 
{
	unsigned long operator()(const int& k) const
	{
		return k % 10;
	}
};
void main()
{
	HashMap<int, std::string, MyKeyHash> hmap;
	hmap.put(1, "val1");
	hmap.put(2, "val2");
	hmap.put(3, "val3");

	std::string value;
	hmap.get(2, value);
	std::cout << value << std::endl;
	bool res = hmap.get(3, value);
	if (res)
		std::cout << value << std::endl;
	hmap.remove(3);
	res = hmap.get(3, value);
	if (res)
		std::cout << value << std::endl;
}

