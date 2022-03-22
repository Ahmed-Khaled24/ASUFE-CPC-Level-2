#include<bits/stdc++.h>
using namespace std;
int main() {
	// use this string to store the whole input
	string inputString; cin >> inputString;
	// use this stack to process the result
	stack<char> wire;

	for (auto c : inputString) {
		// at the first loop stack is empty (has no top) so we add the first input to the stack and continue.
		if (wire.empty()) {
			wire.push(c);
			continue;
		}

		// get the top of the stack 
		char top = wire.top();
		// if the top = the current char that will be inserted so we can untangle this piece of wire.
		if (c == top)
			// we remove the top of the stack and discard the current char c.
			wire.pop();
			// if the top != the current char that will be inserted we push the current char to the stack.
		else wire.push(c);
	}

	// check if the size of the stack after processign is 0 so it is completely untangled.
	if (wire.size() == 0)
		cout << "Yes";
	else cout << "No";
}