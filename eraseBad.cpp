#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

vector<string> permutations;
vector<string> paths;
vector<string> goodPermutations;

void generatePaths()
{
	paths.push_back("12");
	paths.push_back("13");
	paths.push_back("15");
	paths.push_back("16");
	paths.push_back("17");
	
	paths.push_back("24");

	paths.push_back("35");
	paths.push_back("36");
	paths.push_back("37");

	paths.push_back("45");
	paths.push_back("47");

	paths.push_back("56");

	for(int i = 0; i < 12; i++)
	{
		string str = paths[i];
		string str1 = str.substr(0,1);
		string str2 = str.substr(1,1);
		paths.push_back(str2 + str1);
	}
}

void getPermutations()
{
	ifstream file("permutations.dat");
	string str;
	for(int i = 0; i < 5040; i++)
	{
		getline(file, str);
		permutations.push_back(str);
	}
	file.close();
}

bool match(string str)
{
	bool tf = false;

	for(unsigned int i = 0; i < paths.size(); i++)
	{
		if(str.compare(paths[i]) == 0)
		{
			tf = true;
		}
	}

	return tf;
}

void goodPermutation()
{
	for(unsigned int i = 0; i < permutations.size(); i++)
	{
		bool good = true;
	        for(unsigned int j = 0; j < permutations[i].length() - 1; j++)
		{
			if(!match(permutations[i].substr(j,2)))
			{
				good = false;
				j = 7;
			}
		}
		if(good)
		{
			goodPermutations.push_back(permutations[i]);
		}
	}
}

void outGood()
{
	ofstream file("goodPermutations.dat");
	
	for(unsigned int i = 0; i < goodPermutations.size(); i++)
	{
		file << goodPermutations[i].c_str() << endl;
	}

	file.close();
}

int main()
{
	generatePaths();

	getPermutations();

	goodPermutation();

	cout << "Good permutations: " << goodPermutations.size() << endl;

	outGood();

	return 0;
}
