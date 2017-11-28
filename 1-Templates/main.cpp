#include <iostream>


class Person
{
public:
	std::string name;
	int age;
};

int add(int a, int b)
{
	return a + b;
}

float add(float a, float b)
{
	return a + b;
}

template<typename T>
T sub(T a, T b)
{
	return a - b;
}

template<typename T>
void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<bool exp>
void assert(bool cond)
{
	if (cond == exp)
	{
		return;
	}
	abort();
}

template<typename T>
void print(T a)
{
	std::cout << a << std::endl;

}
template<>
void print(std::string value)
{
	std::cout << value.c_str() << std::endl;
}
template<>
void print(Person value)
{
	print(value.name);
	print(value.age);
}
template<typename T>
T min(T a, T b)
{
	if (a < b)
	{
		return a;
	}
	else
		return b;
}
template<typename T>
T max(T a, T b)
{
	if (a > b)
	{
		return a;
	}
	else
		return b;
}

template<typename T>
T clamp(T val, T min, T max)
{
	if (val > max)
	{
		return max;
	}
	else if (val < min)
	{
		return min;
	}
	else
		return val;
}
int main()
{
	Person me;
	me.name = "Wyatettington";
	me.age = 18;
	
	int v1 = add(5, 2);
	float v2 = add(2.1f, 3.2f);
	int s1 = sub(1, 1);
	float s2 = sub(2.5f, 1.1f);
	int s3 = sub<int>(1, 2.0f);
	
	print<float>(1.7f);
	print<bool>(true);
	print<int>(5);
	

	print(me);
	while (true);
	return 0;
}