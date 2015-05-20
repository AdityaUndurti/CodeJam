#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>

#ifndef COMMON

struct element
{
	int sign;
	char value;
};

element Multiply(element a, element b);
element Reduce(std::string c);
void Print(element a);

#define COMMON
#endif