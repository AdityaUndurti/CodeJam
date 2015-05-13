#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>

class Node
{
	int depth;
	std::vector<int> pi;

public:
	Node(int d = 0, std::vector<int> v = {})
	{
		depth = d;
		pi = v;
	}

	int Depth()
	{
		return depth;
	}
	
	std::vector<int> ReduceByOne()
	{
		std::vector<int> p2(pi);

		for (int i = 0; i < p2.size(); i++)
		{
			if (p2[i] > 0)
			{
				p2[i] = p2[i] - 1;
			}
		}

		return p2;
	}

	std::vector<int> CutMaxInHalf()
	{
		std::vector<int> c(pi);

		int maxLocation;
		maxLocation = std::distance(pi.begin(), std::max_element(pi.begin(), pi.end()));		
		c[maxLocation] = pi[maxLocation] / 2;
		c.push_back(pi[maxLocation] - c[maxLocation]);

		return c;
	}

	void print()
	{
		for (int i = 0; i < pi.size(); i++)
		{
			std::cout << pi[i] << ' ';
		}
	}
};

void print(std::vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << ' ';
	}
}

Node DoNothing(Node parent)
{	
	Node c(parent.Depth() + 1, parent.ReduceByOne());
	return c;
}

Node BinarySplit(Node parent)
{
	Node c(parent.Depth() + 1, parent.CutMaxInHalf());
	return c;
}

int ShallowestPath(int D, std::vector<int> Pi)
{
	Node parent(D, Pi);
	Node firstChild = DoNothing(parent);
	Node secondChild = BinarySplit(parent); 
	std::cout << "Children: ";
	firstChild.print();
	std::cout << "; ";
	secondChild.print();
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
		ShallowestPath(D, Pi);
		std::cout << std::endl;
	}

	inputFile.close();
	outputFile.close();
}