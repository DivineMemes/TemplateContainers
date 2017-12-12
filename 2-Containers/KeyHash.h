#pragma once
template<typname K>
struct KeyHash
{
	unsigned long operator()(const K& key) const
	{
		return reinterpret_cast<unsigned long>(key) % TABLE_SIZE;
	}
};