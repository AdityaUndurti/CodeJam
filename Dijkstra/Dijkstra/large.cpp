#include "large.h"

bool IsI(element a)
{
	return (a.sign == 1) && (a.value == 'i');
}

bool IsJ(element a)
{
	return (a.sign == 1) && (a.value == 'j');
}

bool IsK(element a)
{
	return (a.sign == 1) && (a.value == 'k');
}

bool IsNegative1(element a)
{
	return (a.sign == -1) && (a.value == '\0');
}

bool SolveLargeProblem(long L, long X, std::string line)
{
	std::vector <element> input;
	
	element t;
	t.sign = 1;
	t.value = '\0';

	long minX = std::min(X, (long)4);

	for (long x = 0; x < minX; x++)
	{
		for (long l = 0; l < L; l++)
		{
			element in;
			in.value = line[l];
			in.sign = 1;
			input.push_back(in);
		}
	}

	int modX = X % 4;	
	element all;
	all.sign = 1;
	all.value = '\0';

	for (long x = 0; x < modX; x++)
	{
		for (long l = 0; l < L; l++)
		{
			all = Multiply(all, input[l]);			
		}
	}
	
	if (!IsNegative1(all))
	{
		std::cout << "False" << std::endl;
		return false;
	}

	element cumulative;
	cumulative.sign = 1;
	cumulative.value = '\0';

	for (size_t i = 0; i < input.size(); i++)
	{		
		cumulative = Multiply(cumulative, input[i]);
		std::cout << std::endl << "Checking for i: ";
		Print(cumulative);

		if (IsI(cumulative))
		{
			std::cout << std::endl << "Checking for j: ";
			element check;
			check.sign = 1;
			check.value = '\0';

			for (size_t j = i + 1; j < input.size(); j++)
			{
				check = Multiply(check, input[j]);				
				Print(check);

				if (IsJ(check))
				{
					std::cout << "Found j" << std::endl;
					return true;
				}
			}
		}
	}

	return false;

}
