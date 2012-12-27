#include <iostream>
#include <sstream>
#include <cstdlib>
#include <fstream>
using namespace std;

unsigned int N = 7;
unsigned int count = 0;

void display(unsigned int *a)
{
	stringstream ss;
	
	for(unsigned int i = 0; i < N; i++)
	{
		ss << a[i];
	}
	string str = ss.str();
	str = str + str[0];
	ofstream file;
	file.open("permutations.dat", ios::app);
	file << str << endl;
	file.close();
	count++;
}

int main()
{
	remove("permutations.dat");
	unsigned int a[N], p[N];

	for(unsigned int i = 0; i < N; i++)
	{
		a[i] = i + 1;
		p[i] = 0;
	}

	unsigned int i = 1;
	display(a);
	while(i < N)
	{
		if(p[i] < i)
		{
			unsigned int j = i % 2 * p[i];
			unsigned int tmp = a[j];
			a[j] = a[i];
			a[i] = tmp;
			p[i]++;
			i = 1;
			display(a);
		}
		else
		{
			p[i] = 0;
			i++;
		}
	}
	
	cout << "Count: " << count << endl;

	return 0;
}
