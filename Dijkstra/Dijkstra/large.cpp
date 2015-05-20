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

bool SolveLargeProblem(long long L, long long X, std::string line)
{
	std::vector <element> input;
	
	element t;
	t.sign = 1;
	t.value = '\0';

	long minX = std::min(X, (long long)4);

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
		return false;
	}

	element cumulative;
	cumulative.sign = 1;
	cumulative.value = '\0';
	
	for (size_t x = 0; x < minX*L; x++)
	{
		int i = x % L;
		cumulative = Multiply(cumulative, input[i]);		
		
		if (IsI(cumulative))
		{
			//std::cout << "Found i at " << x << std::endl;
			int maxIndex = std::min((long)x + minX*L, L*X);			

			element j_accumulator;
			j_accumulator.sign = 1;
			j_accumulator.value = '\0';
			for (size_t y = x + 1; y < maxIndex; y++)
			{
				int j = y % L;
				j_accumulator = Multiply(j_accumulator, input[j]);

				if (IsJ(j_accumulator))
				{
					//std::cout << "Found j at " << j << std::endl;
					return true;
				}

			}
		}
	}

	std::cout << std::endl;
	return false;

}
