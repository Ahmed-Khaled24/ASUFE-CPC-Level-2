#include<bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
void fillLucky( ll curLucky, ll upperBound, vector<ll> &luckyNubmers) {
	if (curLucky > upperBound)
		return;
	else
		luckyNubmers.push_back(curLucky);

	fillLucky(curLucky * 10 + 4, upperBound, luckyNubmers);
	fillLucky(curLucky * 10 + 7, upperBound, luckyNubmers);
}


int main() {
	vector<ll> luckyNumbers;
	fillLucky(0, 1e10, luckyNumbers);
	sort(luckyNumbers.begin(), luckyNumbers.end());

	ll left, right;
	cin >> left >> right;
	ll sum = 0;

	ll upper_bound_of_right_index = lower_bound(luckyNumbers.begin(), luckyNumbers.end(), right) - luckyNumbers.begin();
	ll upper_bound_of_left_index = lower_bound(luckyNumbers.begin(), luckyNumbers.end(), left) - luckyNumbers.begin();
	ll upper_bound_of_left = luckyNumbers.at(upper_bound_of_left_index);
	ll upper_bound_of_right = luckyNumbers.at(upper_bound_of_right_index);


	if (right == left) {
		sum = upper_bound_of_left;
	}
	else {
		for (int i = upper_bound_of_right_index; i > upper_bound_of_left_index; i--) {
			ll big = luckyNumbers.at(i),
				small = luckyNumbers.at(i - 1);
			sum += (big - small) * big;
		}

		// add left part 
		ll left_part = (upper_bound_of_left - left + 1) * upper_bound_of_left;
		sum += left_part;

		// sub right part
		ll right_part = (upper_bound_of_right - right) * upper_bound_of_right;
		sum -= right_part;
	}
		cout << sum;
	
}