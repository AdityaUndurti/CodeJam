#include "common.h"

element Multiply(element a, element b)
{
	element c;

	if (a.value == '\0')
	{
		c.value = b.value;
		c.sign = a.sign*b.sign;
	}

	if (b.value == '\0')
	{
		c.value = a.value;
		c.sign = a.sign*b.sign;
	}

	// cases where a == b (i,j,k)
	if (a.value == b.value)
	{
		c.value = '\0';
		c.sign = -1 * a.sign * b.sign;
	}

	if (a.value == 'i' && b.value == 'j')
	{
		c.value = 'k';
		c.sign = a.sign * b.sign;
	}

	if (a.value == 'i' && b.value == 'k')
	{
		c.value = 'j';
		c.sign = -1 * a.sign * b.sign;
	}

	if (a.value == 'j' && b.value == 'k')
	{
		c.value = 'i';
		c.sign = a.sign * b.sign;
	}

	if (a.value == 'j' && b.value == 'i')
	{
		c.value = 'k';
		c.sign = -1 * a.sign * b.sign;
	}

	if (a.value == 'k' && b.value == 'i')
	{
		c.value = 'j';
		c.sign = a.sign * b.sign;
	}

	if (a.value == 'k' && b.value == 'j')
	{
		c.value = 'i';
		c.sign = -1 * a.sign * b.sign;
	}

	return c;
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