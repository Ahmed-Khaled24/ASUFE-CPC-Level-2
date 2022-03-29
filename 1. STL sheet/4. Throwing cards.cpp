#include<bits/stdc++.h>
using namespace std;
int main() {
	int n; cin >> n;
	while (n != 0) {
		list<int> deck;
		list<int> discarded;
		// fill the deck with ordered cards.
		for (int i = 0; i < n; i++) deck.push_back(i + 1);
		while (deck.size() >= 2) {
			// discard the first element.
			int discard = deck.front();
			discarded.push_back(discard);
			deck.pop_front();
			// move the first element to the end.
			int switched = deck.front();
			deck.pop_front();
			deck.push_back(switched);
		}

		// print the discarded cards. 
		cout << "Discarded cards:";
		for (auto card : discarded) {
			cout << " " << card;
			if (card != discarded.back())
				cout << ",";
		} cout << endl;

		// pring the remaining card.
		cout << "Remaining card:" << " " << deck.front() << endl;

		cin >> n;
		
	}
	
	
}