#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
// max = min.q + r
// q = floor(max / min)
// r = max % min

int GCD(int _1, int _2) {
	int max = std::max(_1, _2);
	int min = std::min(_1, _2);
	int r = max % min;
	
	if (r == 0)
		return min;

	return GCD(min, r);
}

int main() {
	int testCases; 
	cin >> testCases;
	cin.ignore();
	while (testCases--) {

		// This set store all the gsd of all pairs
		set<int> GCDs;

		// Input section
		vector<int> inputNumbers;
		int number;
		string input;
		getline(cin, input);
		stringstream ss(input);
		while (ss >> number) {
			inputNumbers.push_back(number);
		}
		//----------------------------------------------------------
					
		// Loop to get all possible pairs and get thier gcd then store all gcds
		for (int i = 0; i < inputNumbers.size(); i++) {
			for (int j = i+1 ; j < inputNumbers.size(); j++) {
				GCDs.insert(GCD(inputNumbers[i], inputNumbers[j]));
			}
		}

		// Print the last element in the set (the biggest)
		cout << *GCDs.rbegin() << endl;
	}
}