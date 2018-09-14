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

bool isCyclic(string cycNum)
{
	// doubleCyc stores the number twice back to back
	string doubleCyc = cycNum;
	doubleCyc.append(cycNum);
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

	cin >> cycNum;

	// "00" signals end of file 
	while (cycNum != "00")
	{
		
		cout << cycNum << " is" << (isCyclic(cycNum) ? " " : " not ") << "cyclic.";

		cin >> cycNum;
		if (cycNum != "00")
			cout << endl;
	}
}