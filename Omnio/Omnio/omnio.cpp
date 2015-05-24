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
	else if (X == 4)
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
	else if (X == 5)
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

		if (R == 3 && C == 5 || C == 3 && R == 5)
		{
			return true;
		}

		return false;
	}
	else if (X == 6)
	{
		if (X >= R*C)
		{
			return true;
		}

		if (R*C % X != 0)
		{
			return true;
		}

		if (R <= 3 || C <= 3)
		{
			return true;
		}

		return false;
	}
	else
	{
		return true;
	}

}