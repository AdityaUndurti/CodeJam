#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include "haircut.h"

int main()
{
	std::string filename = "B-small-practice.in";
	std::string outputname = "B-small-practice-output.txt";
	
	std::ifstream inputFile(filename);
	std::ofstream outputFile(outputname);

	std::string line;
	std::string item;

	int nCases = 0;

	if (inputFile.is_open())
	{		
		std::getline(inputFile, line);		
		std::cout << line;
		nCases = std::stoi(line);
		
		std::cout << nCases << std::endl;
		
		int iCase = 0;

		while (iCase < nCases)
		{
			std::getline(inputFile, line);

			std::stringstream ss(line);

			std::getline(ss, item, ' ');
			int B = std::stoi(item);

			std::getline(ss, item, ' ');
			int N = std::stoi(item);

			std::getline(inputFile, line);
			std::stringstream s(line);

			std::vector<int> M;

			for (int b = 0; b < B; b++)
			{
				std::getline(s, item, ' ');
				M.push_back(std::stoi(item));
			}

			std::cout << "Case #" << iCase + 1 << "; " << B << ", " << N << ": ";
			outputFile << "Case #" << iCase + 1 << ": ";
			int sol = Solve(B, N, M);

			std::cout << sol << std::endl;
			outputFile << sol << std::endl;

			iCase++;
		}

		inputFile.close();
		outputFile.close();
	}

	return 0;

}