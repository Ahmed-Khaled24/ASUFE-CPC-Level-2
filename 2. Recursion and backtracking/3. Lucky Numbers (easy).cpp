#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const ll upperBound = 1e10;

bool is_super_lucky(ll number) {
	int fours = 0, sevens = 0;
	while (number) {
		long digit = number % 10;
		digit == 4 ? fours++ : sevens++;
		number /= 10;
	}

	if (fours == sevens)
		return true;
	else 
		return false;
}

void fill_with_lucky_numbers(ll current_number, set<ll> &luckyNumbers) {
	
	// Base case
	if (current_number > upperBound)
		return;

	// Fill with only super lucky numbers
	if(is_super_lucky(current_number))
		luckyNumbers.insert(current_number);

	// Recurse
	fill_with_lucky_numbers(current_number * 10 + 4, luckyNumbers);
	fill_with_lucky_numbers(current_number * 10 + 7, luckyNumbers);
}

int main() {
	set<ll> luckyNumbers;
	fill_with_lucky_numbers(0, luckyNumbers);
	ll input; cin >> input;
	cout << *luckyNumbers.lower_bound(input) << endl;
}