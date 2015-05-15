#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

bool ReduceToI(std::string c)
{
	// sort, so it's always in the form of iiijjjkk, i.e. with all the is in the beginning, js in the middle and ks at the end
	std::sort(c.begin(), c.end());
	std::cout << "i string: " << c << std::endl;
	return false;
}

bool ReduceToJ(std::string c)
{
	std::sort(c.begin(), c.end());
	std::cout << "j string: " << c << std::endl;
	return true;
}

bool ReduceToK(std::string c)
{
	std::sort(c.begin(), c.end());
	std::cout << "k string: " << c << std::endl;
	return true;
}

bool Solve(std::string c)
{
	for (size_t i = 0; i < c.size() - 2; i++)
	{
		std::string iString = c.substr(0, i);
		if (ReduceToI(iString))
		{
			for (size_t j = i + 1; j < c.size() - 1; j++)
			{
				std::string jString = c.substr(i + 1, j);

				if (ReduceToJ(jString))
				{
					for (size_t k = j + 1; k < c.size(); k++)
					{
						std::string kString = c.substr(i + 1, j);

						if (ReduceToK(kString))
						{
							return true;
						}

					}
				}
			}

		}
	}

	return false;
}


char Multiply(char a, char b)
{	
	

	return '\0';
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