#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include "omnio.h"

int main()
{
	std::string filename = "D-small-practice.in";

	std::string outputname = "D-small-practice.txt";

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

		int X = std::stoi(item);

		std::getline(ss, item, ' ');

		int R = std::stoi(item);

		std::getline(ss, item, ' ');

		int C = std::stoi(item);		

		std::cout << "Case #" << iCase + 1 << "; " << X << ", " << R << ", " << C << std::endl;
		outputFile << "Case #" << iCase + 1 << ": ";
		bool sol = Solve(X, R, C);

		if (sol)
		{
			outputFile << "RICHARD" << std::endl;
		}
		else
		{
			outputFile << "GABRIEL" << std::endl;
		}


		iCase++;
	}

	inputFile.close();
	outputFile.close();

}