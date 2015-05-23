#include "omnio.h"

bool Solve(int X, int R, int C)
{
	if (X == 1)
	{
		return false;
	}
	else if (X == 2)
	{
		if (R*C % 2 != 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (X == 3)
	{
		if (R*C % 3 != 0)
		{
			return true;
		}
		else if (R < 2 || C < 2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (X >= 7)
	{
		return true;
	}
	else
	{
		if (X >= R*C)
		{
			return true;
		}	
		
		if (R*C % X != 0)
		{
			return true;
		}

		if (R <= 2 || C <= 2)
		{
			return true;
		}

		return false;
	}

}