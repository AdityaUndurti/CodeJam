#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include "large.h"
#include "small.h"

int main()
{
	std::string filename = "C-test.in";

	std::string outputname = "C-large-practice-output.txt";

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
		
		long L = std::stol(item);
		std::getline(ss, item, ' ');
		
		long X = std::stol(item);
		
		std::getline(inputFile, line);
		
		std::cout << "Case #" << iCase + 1 << std::endl;
		outputFile << "Case #" << iCase + 1 << ": ";
		bool sol = SolveLargeProblem(L, X, line);

		if (sol)
		{
			outputFile << "YES" << std::endl;
		}
		else
		{
			outputFile << "NO" << std::endl;
		}
		

		iCase++;
	}

	inputFile.close();
	outputFile.close();

	return 0;
}