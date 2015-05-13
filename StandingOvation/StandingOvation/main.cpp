#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int nFriends(int maxS, std::string attendees)
{
	std::cout << maxS << " ";
	int nStanding = 0;
	int nF = 0;
	int nFTotal = 0;

	for (int i = 0; i < maxS+1; i++)
	{
		int Si = (int)attendees[i] - '0';
		std::cout << Si;

		if (nStanding >= i)
		{
			nStanding += Si;
		}
		else
		{
			nF = i - nStanding;
			nStanding += nF + Si;
			nFTotal += nF;
		}
	}

	std::cout << " " << nStanding << " ";
	return nFTotal;
}

int main()
{
	std::string filename = "A-large-practice.in";
	
	std::string outputname = "large-practice-output.txt";

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

		std::stringstream ss(line);
		std::string item;
		std::string first;
		
		std::getline(ss, first, ' ');

		int maxS = std::stoi(first);

		std::getline(ss, item, ' ');

		int nF = nFriends(maxS, item);
		std::cout << nF << std::endl;
		
		nLines++;

		outputFile << "Case #" << nLines << ": " << nF << std::endl;
	}

	inputFile.close();
	outputFile.close();

	return 0;
}