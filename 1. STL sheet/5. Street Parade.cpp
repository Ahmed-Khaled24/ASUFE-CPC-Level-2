#include<bits/stdc++.h>
using namespace std;
int main() {
		// number of cars
	int n; cin >> n;
	while (n != 0) {
		stack<int> sideStreet;
		vector<int> trucks(n), result;
		for (int i = 0; i < n; i++) cin >> trucks[i];
		//==================================================
		int current = 1;
		for (int i = 0; i < n; i++) {
			if (trucks[i] == current) {
				result.push_back(current++);

				while (!sideStreet.empty() && sideStreet.top() == current) {
					result.push_back(sideStreet.top());
					sideStreet.pop();
					current++;
				}

			}
			else 
				sideStreet.push(trucks[i]);	
		}

		if (result.size() == n)
			cout << "yes" << endl;
		else 
			cout << "no" << endl;

		cin >> n;
	}
}