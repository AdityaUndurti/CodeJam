#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>


int Solve(int D, std::vector<int> pi)
{
	int min = 1001;

	for (int maxStack = 1; maxStack < 1001; maxStack++)
	{
		int nMoves = 0;

		for (int i = 0; i < (int)pi.size(); i++)
		{
			int nPlatesToMove = pi[i] - maxStack;

			if (nPlatesToMove > 0)
			{
				// Divide and then round up
				nMoves += nPlatesToMove / maxStack + (nPlatesToMove % maxStack != 0);
			}
		}

		nMoves = nMoves + maxStack;

		if (nMoves < min)
		{
			min = nMoves;
		}
	}

	return min;
}

void print(std::vector<int> v)
{
	for (int i = 0; i < (int)v.size(); i++)
	{
		std::cout << v[i] << ' ';
	}
}

int main()
{
	std::string filename = "B-large-practice.in";

	std::string outputname = "B-large-practice-output.txt";

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

	int nLines = 0;
	while (nLines < nCases)
	{		
		std::getline(inputFile, line);
		
		int D = std::stoi(line);
		std::string item;		
		std::vector<int> Pi;

		std::getline(inputFile, line);
		std::stringstream ss(line);
		while (std::getline(ss, item, ' '))
		{			
			Pi.push_back(stoi(item));
		}
		nLines++;

		std::cout << "Case #" << nLines << ": " << D << ", ";
		print(Pi);
		
		int s = Solve(D, Pi);

		std::cout << "; Solution: " << s << std::endl;

		outputFile << "Case #" << nLines << ": " << s << std::endl;
	}

	inputFile.close();
	outputFile.close();
}