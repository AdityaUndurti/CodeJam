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

int ReduceToI(std::string c)
{	
	std::cout << "i string: " << c << std::endl;

	element reduced = Reduce(c);

	if (reduced.value == 'i')
	{
		return reduced.sign;
	}
	
	return 0;
}


int ReduceToJ(std::string c)
{
	std::cout << "j string: " << c << std::endl;

	element reduced = Reduce(c);
	
	if (reduced.value == 'j')
	{
		return reduced.sign;
	}

	return 0;
}

int ReduceToK(std::string c)
{
	std::cout << "k string: " << c << std::endl;

	element reduced = Reduce(c);

	if (reduced.value == 'k')
	{
		return reduced.sign;
	}

	return 0;
}

bool Solve(std::string c)
{
	for (size_t i = 1; i < c.size() - 2; i++)
	{
		std::string iString = c.substr(0, i);

		int signi = ReduceToI(iString);

		if (signi != 0)
		{
			for (size_t j = i; j < c.size() - 1; j++)
			{
				std::string jString = c.substr(i + 1, j - i - 1);

				int signj = ReduceToJ(jString);

				if (signj != 0)
				{
					for (size_t k = j; k < c.size(); k++)
					{
						std::string kString = c.substr(j + 1, k - j - 1);

						int signk = ReduceToK(kString);

						if (signk != 0)
						{
							std::cout << "Checking for sign..." << std::endl;

							if (signi * signj * signk == 1)
							{								
								return true;
							}
						}

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