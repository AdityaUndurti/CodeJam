#include "large.h"

bool SolveLargeProblem(long long L, long long X, std::string line)
{
	std::vector <element> input;
	
	element t;	

	long minX = (long)std::min(X, (long long)4);

	for (long l = 0; l < L; l++)
	{
		element in(line[l]);			
		input.push_back(in);
	}
	

	int modX = X % 4;	
	element all;
	
	for (long x = 0; x < modX; x++)
	{
		for (long l = 0; l < L; l++)
		{
			all = all*input[l];			
		}
	}
	
	if (all != -1)
	{		
		return false;
	}

	element cumulative;
		
	for (size_t x = 0; x < minX*L; x++)
	{
		int i = x % L;
		cumulative = cumulative*input[i];		
		
		if (cumulative == 'i')
		{			
			int maxIndex = (int)std::min((long)x + minX*L, L*X);			

			element j_accumulator;
			
			for (int y = x + 1; y < maxIndex; y++)
			{
				int j = y % L;
				j_accumulator = j_accumulator*input[j];

				if (j_accumulator == 'j')
				{		
					return true;
				}

			}
		}
	}

	return false;

}
