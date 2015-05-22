#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>

#ifndef COMMON

class element
{
public:	
	element()
	{
		value = '\0';
		sign = 1;
	}

	element(char v)
	{
		value = v;
		sign = 1;
	}

	int sign;
	char value;
	bool operator==(element b);
	bool operator==(char b);
	bool operator==(int i);
	bool operator!=(int i);
};

element operator*(element a, element b);


element Multiply(element a, element b);
element Reduce(std::string c);
void Print(element a);

#define COMMON
#endif