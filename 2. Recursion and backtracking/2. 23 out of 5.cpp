#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int> &numbers, int level, int result) {
	// Base case
	// Make sure that all the numbers are used to return true
	if (result == 23 && level == 5)
		return true;
	else if (result != 23 && level == 5)
		return false;

	// Increase the level to use the next number in the vector.
	// Check all the possibilities if any is true the function returns true.
	bool ans1 = solve(numbers, level+1, result + numbers.at(level));
	bool ans2 = solve(numbers, level+1, result - numbers.at(level));
	bool ans3 = solve(numbers, level+1, result * numbers.at(level));

	return ans1 || ans2 || ans3;
}


int main() {
	while (true) {
		vector<int> Numbers(5);
		for (int i = 0; i < 5; i++) cin >> Numbers.at(i);
		sort(Numbers.begin(), Numbers.end());
		if (Numbers.at(0) == 0) break;

		int Level = 1;
		bool answer = false;

		do {
			answer = solve(Numbers, Level, Numbers.at(Level - 1));
			if (answer == true) break;
		} 
		while (next_permutation(Numbers.begin(), Numbers.end()));
		// next_permutation functions is to get the next permutation of the container 
		// I use it here to get all possibilities of arranging the vector but to work 
		// properly I had to use sort at first "line 26" to start from the smallest permutation

		if (answer)
			 cout << "Possible" << endl;
		else cout << "Impossible" << endl;
	}
}