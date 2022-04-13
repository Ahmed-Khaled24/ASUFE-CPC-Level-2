#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int solve(int a , int b, int n){
	// Base case
	if (n == 0)
		return a;
	else if (n == 1)
		return b;

	return solve(a, b, n - 1) ^ solve(a, b, n - 2);
}

int main() {
	int testCases; cin >> testCases;
	while (testCases--) {

		int a, b, n;
		cin >> a >> b >> n;
		
		// the only usage of the function to get fib(2)
		int fib2 = solve(a, b, 2);
		int remainder = n % 3;

		if (remainder == 0)
			cout << a << endl;
		else if (remainder == 1)
			cout << b << endl;
		else if (remainder == 2)
			cout << fib2 << endl;
	}
}

/*
	In this problem I found a pattern which is every i+3 the solution is repeated so 
	I followed the patteren using the concept of BASMAGATION.
*/