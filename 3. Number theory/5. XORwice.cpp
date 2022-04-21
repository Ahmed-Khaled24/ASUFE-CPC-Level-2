#include<bits/stdc++.h>
using namespace std;


int main() {
	int testCases; cin >> testCases;
	while (testCases--) {
		int a, b;
		cin >> a >> b;
		int x = a & b;
		int answer = (a ^ x) + (b ^ x);
		cout << answer << endl;
	}
}