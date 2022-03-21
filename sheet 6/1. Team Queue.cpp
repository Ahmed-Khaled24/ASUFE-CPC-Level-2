#include<bits/stdc++.h>
using namespace std;

void fillTheMap(map<int, int> &theMap, int numberOfTeams) {
	// this will be used to identify each team members in the map
	static int teamIdentifier = 1;

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

void DEQUEUE(list<int> &theQueue) {
	int topElement = *theQueue.rbegin();
	cout << topElement << endl;
	theQueue.pop_back();
}

int getTheTeam(map<int, int>& theMap, int theElement) {
	auto it = theMap.begin();
	it = theMap.find(theElement);
	return it->second;
}

int main() {
	int scenarioCounter = 1;

	while (true) {

		// t is the number of teams
		int t; cin >> t;
		if (t == 0) break;

		// this map holds every member as a value and its team as a key
		map<int, int> allMembers;
		fillTheMap(allMembers, t);

		// handle the queries on the queue
		list<int> queue;
		string command = "";
		cout << "Scenario #" << scenarioCounter << endl;

		while (true) {

			cin >> command;

			// when we see stop command then this test finishes
			if (command == "STOP") break;

			// when we see dequeue command we print the first inserted element and remove it from the queue
			else if (command == "DEQUEUE")
				DEQUEUE(queue);
			
			// when we see enqueue command we add the following element wrt the given instructions
			else if (command == "ENQUEUE") {
				int theElement; cin >> theElement;
				int theElementTeam = -1;

				// if we insert the first element to the queue
				if (queue.empty()) {
					queue.push_front(theElement);
					continue;
				}

				// check the element team
				theElementTeam = getTheTeam(allMembers, theElement);
				
				// find the team for each member in the queue and compare with theElementTeam
				bool foundTheTeam = false;
				auto itList = queue.begin();
				while(itList != queue.end()) {
					int currentElement = *itList;
					auto itMap = allMembers.find(currentElement);
					int currentElementTeam = itMap->second;

					if (theElementTeam == currentElementTeam) {
						queue.insert(itList, theElement);
						foundTheTeam = true;
						break;
					}

					itList++;
				}
				// if there is no elements in the queue from the same team
				if (!foundTheTeam)
					queue.push_front(theElement);
			}				
		}
		scenarioCounter++;
	}
}