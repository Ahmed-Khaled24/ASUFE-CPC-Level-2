#include<bits/stdc++.h>
using namespace std;
int main() {
	int input; cin >> input;
	int result = 0;

	// The number has to be even
	if (input % 2 == 0) {
		// Divide it and loop until its half because after that the numbers are replicated
		input /= 2;
		for (int i = 2; i < input; i += 2)
			result++;
	}
	cout << result << endl;
}