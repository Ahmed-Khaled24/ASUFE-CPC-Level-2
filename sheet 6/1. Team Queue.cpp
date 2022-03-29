#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;


// o(n)
void fillTheMap(unordered_map<int, int> &theMap, int numberOfTeams) {
	// this will be used to identify each team members in the map
	int teamIdentifier = 1;

	// fill the map with teams members
	for (int i = 0; i < numberOfTeams; i++) {
		// size of the team
		int size; cin >> size;
		// insert all team members
		for (int j = 0; j < size; j++) {
			int member; cin >> member;
			theMap.insert({member, teamIdentifier});
		}
		// to indentify the next team
		teamIdentifier++;
	}
}


// o(1) because the unordered map is a hash table
int getTheTeam(unordered_map<int, int>& theMap, int theElement) {
	auto it = theMap.begin();
	it = theMap.find(theElement);
	return it->second;
}


// o(1)
void DEQUEUE(list<int>& theQueue, unordered_map<int, int>& theMap, vector<int>& counter, vector<list<int>::iterator>& positions) {
	int topElement = theQueue.back();
	int topElementTeam = getTheTeam(theMap, topElement);
	cout << topElement << endl;
	theQueue.pop_back();

	// handle the positions arrya and counter array
	counter[topElementTeam]--;
	if (counter[topElementTeam] == 0)
		positions[topElementTeam] = theQueue.end();
}


int main() {
	int scenarioCounter = 1;

	while (true) {

		// t is the number of teams
		int t; cin >> t;
		if (t == 0) break;

		// this map holds every member as a value and its team as a key
		unordered_map<int, int> allMembers;
		fillTheMap(allMembers, t);

		//------------------------------------------------------------------------------

		// handle the queries on the queue
		list<int> queue;
		string command = "";
		cout << "Scenario #" << scenarioCounter << endl;

		// array to keep track of the positoin of each team
		vector<list<int>::iterator> positions(t + 1);
		for (int i = 0; i < t + 1; i++) positions[i] = queue.end();


		// array to keep track of each number of elements of the same team exist in the queue
		vector<int> counter(t + 1, 0);


		while (true) {

			cin >> command;

			// when we see stop command then this test finishes
			if (command == "STOP") break;

			// when we see dequeue command we print the first inserted element and remove it from the queue
			else if (command == "DEQUEUE")
				DEQUEUE(queue, allMembers, counter, positions);
			
			// when we see enqueue command we add the following element wrt the given instructions
			else if (command == "ENQUEUE") {
				int theElement; cin >> theElement;
				int theElementTeam = getTheTeam(allMembers, theElement);

				// insert the element at the position of the last one of its team 
				auto insertPosition = positions[theElementTeam];
				if (insertPosition == queue.end())  
					positions[theElementTeam] = queue.insert(queue.begin(), theElement);
				else 
					positions[theElementTeam] = queue.insert(insertPosition, theElement);

				counter[theElementTeam]++;
				
			}				
		}
		scenarioCounter++;
		cout << endl;
	}
}