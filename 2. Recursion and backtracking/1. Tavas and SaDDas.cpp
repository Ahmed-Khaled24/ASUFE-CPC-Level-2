#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
using ll = long long;
void solve(int upperBound, ll curLucky, vector<int> &LuckyNumbers) {
	if (curLucky > upperBound)
		return;
	LuckyNumbers.push_back(curLucky);
	solve(upperBound, curLucky * 10 + 4, LuckyNumbers);
	solve(upperBound, curLucky * 10 + 7, LuckyNumbers);
}

int main() {
	vector<int> luckyNumbers;
	solve(1e9, 0, luckyNumbers);
	sort(luckyNumbers.begin(), luckyNumbers.end());
	int input; cin >> input;
	int index = find(luckyNumbers.begin(), luckyNumbers.end(), input) - luckyNumbers.begin();
	cout << index;
}