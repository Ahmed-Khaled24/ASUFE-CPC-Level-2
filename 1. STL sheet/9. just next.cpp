#include<bits/stdc++.h>
using namespace std;


bool compareNumbers(vector<int>& inputNumber, vector<int>& justNext) {
	for (int i = 0; i < inputNumber.size(); i++) {
		if (justNext.at(i) > inputNumber.at(i))
			return true;
	}
	return false;
}


void printNumber(vector<int>& V) {
	for (auto n : V) cout << n;
	cout << endl;
}


int main() {
	int n; cin >> n;
	while (n--) {
		int size; cin >> size;
		vector<int> inputNumber(size);
		for (int i = 0; i < size; i++) cin >> inputNumber.at(i);



			// if the input is only one number
		if (size == 1) {
			cout << -1 << endl;
			continue;
		}


		int prev = inputNumber.at(size - 1);
		int firstDecreasing = -1, justGreater = -1;
		for (int i = size - 2; i >= 0; i--) {
			if (inputNumber.at(i) >= prev) {
				prev = inputNumber.at(i);
			}
			else {
				firstDecreasing = i;
				break;
			}
		}

			// there is no such a decreasing number
		if (firstDecreasing == -1) {
			cout << -1 << endl;
			continue;
		}

			// sort and get the just greater number than the first decreasing one
		sort(inputNumber.begin() + firstDecreasing + 1, inputNumber.end());
		auto greater = upper_bound(inputNumber.begin() + firstDecreasing, inputNumber.end(), inputNumber.at(firstDecreasing));


			// first decreasing is the largest number of the number 
		if (greater == inputNumber.end()) {
			cout << -1 << endl;
			continue;
		}


		justGreater = greater - inputNumber.begin();
		swap(inputNumber.at(firstDecreasing), inputNumber.at(justGreater));
		sort(inputNumber.begin() + firstDecreasing + 1, inputNumber.end());
		printNumber(inputNumber);
	}
}