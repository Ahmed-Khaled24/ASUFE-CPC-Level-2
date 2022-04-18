#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
void print(int numenator, int denominator) {
	string denom = to_string(denominator);
	if (denom.size() == 4)
		denom = "0" + denom;

	cout << numenator << " / " << denom << " = " << numenator / denominator << endl; 
}

bool distnctNumber(string number) {
	set<char> digits;
	int num_of_digits = number.size();

	// If the number is four-digit number we have to check for the zero
	if (num_of_digits == 4) {
		for (auto d : number) {
			if (d == '0')
				return false;
			else
				digits.insert(d);
		}
	}
	// If it is five-digit number 
	else if(num_of_digits == 5) {
		for (auto d : number)
			digits.insert(d);
	}
	// If it is nine-digit number
	else if (num_of_digits == 9) {
		// This check is for numenator and denominator after filling the set
		for (auto d : number) 
			if (d == '0')
				return false;
			else 
				digits.insert(d);		
	}
	// If it is ten-digit number
	else if (num_of_digits == 10) {
		// This check is for numenator and denominator after filling the set
		for (auto d : number)
			digits.insert(d);
	}

	// Check if the number of digits equals the set size "has distinct digits"
	if (num_of_digits == digits.size())
		return true;
	else 
		return false;
}

void fill_the_set(unordered_set<int>& theSet) {
	for (int number = 1234; number <= 98765; number++) 
		if (distnctNumber(to_string(number)))
			theSet.insert(number);
}

bool solve(int result, unordered_set<int> &numbers) {
	int answerCounter = 0;
	auto denominator = numbers.begin();
	while (denominator != numbers.end()) {
		int numenator = result * (*denominator);
		if (numenator <= 98765) {
			string both = to_string(numenator) + to_string(*denominator);
			if (distnctNumber(both)) {
				print(numenator, *denominator);
				answerCounter++;
			}
		}
		denominator++;
	}

	if (answerCounter == 0)
		return false;
	else return true;
}

int main() {
	unordered_set<int> distinct_five_digits_numbers;
	fill_the_set(distinct_five_digits_numbers);

	int division_result;
	while (cin >> division_result) {
		if (division_result == 0)
			break;

		bool  hasSolutions = solve(division_result, distinct_five_digits_numbers);
		if (!hasSolutions) {
			cout << "There are no solutions for " << division_result << "." << endl;
		}
		cout << endl;
	}
}