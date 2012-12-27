#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;

vector<string> paths;
vector<int> weights;
vector<int> lengths;
vector<string> cycles;
vector<int> cycleLengths;

int min_length;
int min_index;

void generateWeights()
{
	paths.push_back("12");
	weights.push_back(4);
	paths.push_back("13");
	weights.push_back(6);
	paths.push_back("15");
	weights.push_back(7);
	paths.push_back("16");
	weights.push_back(6);
	paths.push_back("17");
	weights.push_back(15);
	
	paths.push_back("24");
	weights.push_back(10);

	paths.push_back("35");
	weights.push_back(10);
	paths.push_back("36");
	weights.push_back(5);
	paths.push_back("37");
	weights.push_back(5);

	paths.push_back("45");
	weights.push_back(15);
	paths.push_back("47");
	weights.push_back(3);

	paths.push_back("56");
	weights.push_back(5);

	for(int i = 0; i < 12; i++)
	{
		string str = paths[i];
		string str1 = str.substr(0,1);
		string str2 = str.substr(1,1);
		paths.push_back(str2 + str1);
		weights.push_back(weights[i]);
	}
}

void getCycles()
{
	ifstream file("goodPermutations.dat");
	string str;
	for(int i = 0; i < 42; i++)
	{
		getline(file, str);
		cycles.push_back(str);
	}
	file.close();
}

int getLengthOfPath(string str)
{
	for(unsigned int i = 0; i < paths.size(); i++)
	{
		if(str.compare(paths[i]) == 0)
		{
			return weights[i];
		}
	}

	return 10000;
}

void calculateLengths()
{
	for(unsigned int i = 0; i < cycles.size(); i++)
	{
		int length = 0;
		for(unsigned int j = 0; j < cycles[i].length() - 1; j++)
		{
			length += getLengthOfPath(cycles[i].substr(j,2));
		}
		
		if(length < min_length)
		{
			min_length = length;
			min_index = i;
		}
	}
}

int main()
{
	min_length = 1000000;

	generateWeights();

	getCycles();

	calculateLengths();

	cout << "Min length: " << min_length << endl;

	cout << "Cycle: " << cycles[min_index] << endl;

	return 0;
}
