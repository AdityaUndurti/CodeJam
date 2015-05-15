#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

struct element
{
	int sign;
	char value;
};


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

bool ReduceToI(std::string c)
{	
	std::cout << "i string: " << c << std::endl;

	element reduced = Reduce(c);

	if (reduced.value == 'i' && reduced.sign == 1)
	{
		return true;
	}
	
	return false;
}


bool ReduceToJ(std::string c)
{
	std::cout << "j string: " << c << std::endl;

	element reduced = Reduce(c);
	
	if (reduced.value == 'j' && reduced.sign == 1)
	{
		return true;
	}

	return false;
}

bool ReduceToK(std::string c)
{
	std::cout << "k string: " << c << std::endl;

	element reduced = Reduce(c);

	if (reduced.value == 'k' && reduced.sign == 1)
	{
		return true;
	}

	return false;
}

bool Solve(std::string c)
{
	for (size_t i = 1; i < c.size() - 2; i++)
	{
		std::string iString = c.substr(0, i);

		if (ReduceToI(iString))
		{
			for (size_t j = i; j < c.size() - 1; j++)
			{
				std::string jString = c.substr(i, j - i);

				if (ReduceToJ(jString))
				{
					std::string kString = c.substr(j, c.size() - j);
					
					if (ReduceToK(kString))
					{
						return true;							
					}					
				}
			}

		}
	}

	return false;
}

int main()
{
	int L = 2;
	int X = 6;
	std::string line = "ji";

	std::string expanded = "";

	for (int x = 0; x < X; x++)
	{
		expanded += line;
	}

	std::cout << expanded << "; " << Solve(expanded) << std::endl;
	return 0;
}