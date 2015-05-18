#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>

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
	//std::cout << "i string: " << c << std::endl;

	element reduced = Reduce(c);

	if (reduced.value == 'i' && reduced.sign == 1)
	{
		return true;
	}
	
	return false;
}


bool ReduceToJ(std::string c)
{
	//std::cout << "j string: " << c << std::endl;

	element reduced = Reduce(c);
	
	if (reduced.value == 'j' && reduced.sign == 1)
	{
		return true;
	}

	return false;
}

bool ReduceToK(std::string c)
{
	//std::cout << "k string: " << c << std::endl;

	element reduced = Reduce(c);

	if (reduced.value == 'k' && reduced.sign == 1)
	{
		return true;
	}

	return false;
}

bool Solve(std::string c)
{
	for (size_t i = 1; i < c.size() - 1; i++)
	{
		std::string iString = c.substr(0, i);

		if (ReduceToI(iString))
		{
			for (size_t j = i; j < c.size(); j++)
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
	std::string filename = "C-small-practice.in";

	std::string outputname = "C-small-practice-output.txt";

	std::ifstream inputFile(filename);
	std::ofstream outputFile(outputname);

	std::string line;

	int nCases = 0;

	if (inputFile.is_open())
	{
		std::getline(inputFile, line);
		nCases = std::stoi(line);
		std::cout << nCases << std::endl;
	}

	int iCase = 0;
	std::string item;

	while (iCase < nCases)
	{
		std::getline(inputFile, line);
		std::stringstream ss(line);
		std::getline(ss, item, ' ');
		int L = std::stoi(item);
		std::getline(ss, item, ' ');
		int X = std::stoi(item);

		std::getline(inputFile, line);

		std::string expanded = "";

		for (int x = 0; x < X; x++)
		{
			expanded += line;
		}

		std::cout << expanded << "; " << Solve(expanded) << std::endl;

		iCase++;
	}

	inputFile.close();
	outputFile.close();

	return 0;
}