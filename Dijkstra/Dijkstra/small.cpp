#include "small.h"

bool ReduceToI(std::string c)
{
	element reduced = Reduce(c);

	if (reduced.value == 'i' && reduced.sign == 1)
	{
		return true;
	}

	return false;
}


bool ReduceToJ(std::string c)
{
	element reduced = Reduce(c);

	if (reduced.value == 'j' && reduced.sign == 1)
	{
		return true;
	}

	return false;
}

bool ReduceToK(std::string c)
{
	element reduced = Reduce(c);

	if (reduced.value == 'k' && reduced.sign == 1)
	{
		return true;
	}

	return false;
}

bool ReduceToMinus1(std::string c)
{
	element reduced = Reduce(c);

	if (reduced.value == '\0' && reduced.sign == -1)
	{
		return true;
	}

	return false;
}

bool SolveSmallProblem(long L, long X, std::string line)
{
	if (L <= 1)
	{
		return false;
	}

	std::string c = "";

	for (long x = 0; x < X; x++)
	{
		c += line;
	}

	if (!ReduceToMinus1(c))
	{
		return false;
	}

	c = "";

	for (long x = 0; x < X; x++)
	{
		c += line;
	}

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
					return true;
				}
			}

		}
	}

	return false;
}