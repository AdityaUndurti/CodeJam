#include "omnio.h"

bool Solve(int X, int R, int C)
{
	if (X == 1)
	{
		return false;
	}

	if (X >= 7)
	{
		return true;
	}

	if (R*C % X != 0)
	{
		return true;
	}

	if (X >= 3 && (R <= 2 || C <= 2))
	{
		return true;
	}

	return false;
}