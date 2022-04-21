#include<bits/stdc++.h>
using namespace std;
int GCD(int a, int b) {
	int max = std::max(a, b);
	int min = std::min(a, b);
	int r = max % min;
	if (r == 0)
		return min;
	else
		return GCD(min, r);
}

int main() {
	
	int input; cin >> input;
	while (input) {
		unsigned long long G = 0;
		for (int i = 1; i < input; i++) {
			for (int j = i + 1; j <= input; j++) {
				G += GCD(i, j);
			}
		}

		cout << G << endl;
		cin >> input;
	}
}