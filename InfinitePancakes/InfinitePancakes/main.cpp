#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

void print(std::vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << ' ';
	}
}

int ShallowestPath(int D, std::vector<int> Pi)
{
	return 0;
}

int main()
{
	std::string filename = "B-small-practice.in";

	std::string outputname = "B-small-practice-output.txt";

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
		std::cout << "; " << ShallowestPath(D, Pi) << std::endl;
	}

	inputFile.close();
	outputFile.close();
}