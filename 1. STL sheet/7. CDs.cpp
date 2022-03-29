#include<bits/stdc++.h>
using namespace std; 
int main() {
	int jack, jill; cin >> jack >> jill;
	while (jack != 0 || jill != 0) {
		set<int> cds;
		int canSell = 0;
		for (int i = 0; i < jack + jill; i++) {
			int cd; cin >> cd;
			auto status = cds.insert(cd);
			if (!status.second) canSell++;
		}
		cout << canSell << endl;
		cin >> jack >> jill;
	}
}