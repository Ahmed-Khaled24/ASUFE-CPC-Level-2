#include<bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

ll sumDigits(ll num) {
	vector<int> digits;
	while (num) {
		digits.push_back(num % 10);
		num /= 10;
	}
	return accumulate(digits.begin(), digits.end(), 0);
}

ll GCD(ll a, ll b) {
	ll max = std::max(a, b);
	ll min = std::min(a, b);

	ll r = max % min;
	if (r == 0)
		return min;

	return GCD(min, r);
}

ll GCDsum(ll num) {
	ll digitsSum = sumDigits(num);
	return GCD(num, digitsSum);
}

int main() {
	int testCases; cin >> testCases;
	while (testCases--) {
		ll input; cin >> input;

		while (GCDsum(input) <= 1) 
			input++;

		cout << input << endl;
	}
}