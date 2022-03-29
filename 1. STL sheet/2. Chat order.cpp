#include<bits/stdc++.h>
using namespace std;
int main() {
	// n is the number of messages
	int n; cin >> n;

	// this deque will be used to store all the names.
	deque<string> names;
		
	// this set will be used to check if the name printed before or for the first time.
	set<string> printer;

	// read the names.
	for (int i = 0; i < n; i++) {
		string name; cin >> name;
		// add to the beginning of the data for easy printing.
		names.push_front(name);
	}

	for (auto name : names) {

		// search in printer set (binary search) if we print this name before.
		auto finder = printer.find(name);

		// if we print it before we pass it and go to the next one.
		if (finder != printer.end())
			continue;

		// if we didn't print it before we print it and add it to the printer set to avoid printing it again.
		cout << name << endl;
		printer.insert(name);

	}
}