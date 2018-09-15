// ---------------------------------------------------------
// cyclic.cpp
// Jeremy Campbell
// The 6th project in Applied Algoritms; 
// Determines if a number is cyclic or not, meaning that a 
// number with n digits can be multiplied by 1 through n 
// and contain all the same numbers
// ---------------------------------------------------------
#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;

void reverse(string &s)
{
	string r(s.size(), ' ');
	for (int i = 0; i < s.size(); i++)
	{
		r[i] = s[s.size() - i- 1];
	}
	s = r;
}

void multiply(int multiplier, int j, int multiplicand, string &ans)
{
	// Subtracting and adding by '0' to convert between a char and int
	int temp = (ans[j] - '0') + (multiplier * multiplicand);
	ans[j] = (temp % 10) + '0';
	
	// Add the carry to the next slot in the answer
	// If at the end of the string, add another slot to 
	// keep from an invalid subscript
	if ((j + 1) > ans.size())
	{
		ans.push_back('0');
	}
	ans[j + 1] =  ((ans[j + 1] - '0') + temp / 10) + '0';
}

bool isCyclic(string cycNum)
{
	bool result = true;
	// doubleCyc stores the number twice back to back
	string doubleCyc = cycNum;
	doubleCyc.append(cycNum);

	// Reverse the string to make the math easier
	reverse(cycNum);
	
	// The number is always guarenteed to have at least 2 digits, 
	// and no more than 60 digits
	for (int i = 1; i <= cycNum.size() && result; i++)
	{
		string ans(cycNum.size(), '0');
		for (int j = 0; j < cycNum.size(); j++)
		{
			if (i < 10)
			{
				multiply(i, j, cycNum[j] - '0', ans);
			}
			else
			{
				// By the ones place first, then by the tens place
				multiply(i % 10, j, cycNum[j] - '0', ans);
				multiply(i / 10, j, cycNum[j] - '0', ans);
			}
		}
		reverse(ans);
		if (doubleCyc.find(ans) == string::npos)
			result = false;
	}
	return result;
}

int main()
{
	ifstream fin("cyclic.in");

	if (!fin)
	{
		cerr << "Failed to open file." << endl;
		return -1;
	}

	ofstream fout("cyclic.out");
	string cycNum;
	fin >> cycNum;

	// "00" signals end of file 
	while (cycNum != "00")
	{
		fout << cycNum << " is" << (isCyclic(cycNum) ? " " : " not ") << "cyclic";
		fin >> cycNum;
		if (cycNum != "00")
			fout << endl;
	}
}