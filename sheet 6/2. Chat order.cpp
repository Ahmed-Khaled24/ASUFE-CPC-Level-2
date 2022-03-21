#include<bits/stdc++.h>
using namespace std;
int main() {
	// n is the number of messages
	int n; cin >> n;
	list<string> names;
	while (n--) {
		string name; cin >> name;
		auto itList = find(names.begin(), names.end(), name);
		if (itList == names.end())
			names.push_front(name);
		else if (itList != names.end()) {
			names.erase(itList);
			names.push_front(name);
		}
	}

	for (auto name : names) cout << name << endl;
}