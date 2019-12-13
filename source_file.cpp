#include <iostream>
#include <bitset>
#include<algorithm> 
#include<vector>
using namespace std;

class Problem
{
public:
	
	static vector<int> flipShift(int a, int b)
	{
		//Nearest power of A
		vector<int>v;
		int A_dash=nearest_power(a);
		v.push_back(A_dash);

		//nearest power of B
		int B_dash= nearest_power(b);
		
		//Maximum value of Adash and Bdash for finding the umber of bits needed to be shift
		v.push_back(A_dash);
		string s1 = std::bitset<8>(max(A_dash, B_dash)).to_string();
		string s2 = std::bitset<8>(min(A_dash, B_dash)).to_string();

		string A_binary = std::bitset<8>(A_dash).to_string(); //to binary
		string B_binary = std::bitset<8>(B_dash).to_string(); //to binary

		
		int n = A_binary.length();
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			s1.insert(s1.begin(), s1[n - 1]);
			s1.erase(s1.end() - 1);
			count++;
			if (s1.compare(s2) == 0)
			{
				
				v.push_back(count);
				break;
			}
			
		}
		return v;
	}
	static int nearest_power(int a);

};

int Problem::nearest_power(int a)
{
	int A_dash;
	if (abs(a - pow(2, ceil(log(a) / log(2)))) < abs(a - pow(2, floor(log(a) / log(2)))))
	{
		A_dash = static_cast<int>(pow(2, ceil(log(a) / log(2))));
	}
	else
	{
		A_dash = static_cast<int>(pow(2, floor(log(a) / log(2))));
	}
	return A_dash;
}
#ifndef RunTests
int main()
{
	// test your code if you wish
	int num1, num2;
	cout << "Number 1: " << endl;
	cin >> num1;
	cout << "Number 2: " << endl;
	cin >> num2;
	vector<int> v = Problem::flipShift(num1, num2);
	for (auto i : v)
	{
		cout << i<<endl;
	}
	cout << "*******Finally the end of the problem ***** :)" << endl;
	//unsigned long decimal = std::bitset<8>(binary).to_ulong();
	//std::cout << decimal << "\n";
	return 0;
}
#endif
