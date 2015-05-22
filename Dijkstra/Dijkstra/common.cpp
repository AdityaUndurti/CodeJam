#include "common.h"

element operator*(element a, element b)
{
	return Multiply(a, b);
}

bool element::operator==(element b)
{
	return (sign == b.sign) && (value == b.value);
}

bool element::operator==(char b)
{
	return (sign == 1) && (value == b);
}

bool element::operator==(int i)
{
	return (sign == i) && (value == '\0');
}

bool element::operator!=(int i)
{
	return (sign != i) || (value != '\0');
}

element Multiply(element a, element b)
{
	element c;

	if (a.value == '\0')
	{		
		c.value = b.value;
		c.sign = a.sign*b.sign;		
		return c;
	}

	if (b.value == '\0')
	{
		c.value = a.value;
		c.sign = a.sign*b.sign;
		return c;
	}

	// cases where a == b (i,j,k)
	if (a.value == b.value)
	{
		c.value = '\0';
		c.sign = -1 * a.sign * b.sign;
		return c;
	}

	if (a.value == 'i' && b.value == 'j')
	{
		c.value = 'k';
		c.sign = a.sign * b.sign;
		return c;
	}

	if (a.value == 'i' && b.value == 'k')
	{
		c.value = 'j';
		c.sign = -1 * a.sign * b.sign;
		return c;
	}

	if (a.value == 'j' && b.value == 'k')
	{
		c.value = 'i';
		c.sign = a.sign * b.sign;
		return c;
	}

	if (a.value == 'j' && b.value == 'i')
	{
		c.value = 'k';
		c.sign = -1 * a.sign * b.sign;
		return c;
	}

	if (a.value == 'k' && b.value == 'i')
	{
		c.value = 'j';
		c.sign = a.sign * b.sign;
		return c;
	}

	if (a.value == 'k' && b.value == 'j')
	{
		c.value = 'i';
		c.sign = -1 * a.sign * b.sign;
		return c;
	}
}

element Reduce(std::string c)
{
	element reduced;
	reduced.sign = 1;
	reduced.value = '\0';

	for (size_t i = 0; i < c.size(); i++)
	{
		element current;
		current.sign = 1;
		current.value = c[i];

		reduced = Multiply(reduced, current);
	}

	return reduced;
}

void Print(element a)
{
	std::cout << "{";
	if (a.sign < 0)
	{
		std::cout << "-";
	}

	std::cout << a.value << "}";
	return;
}