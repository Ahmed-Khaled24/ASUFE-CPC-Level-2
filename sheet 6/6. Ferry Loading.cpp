#include<bits/stdc++.h>
using namespace std;
void processTheQueue(queue<double> &Q, int &travelCounter, string &ferryPosition, double ferryLen) {
	double ferryLoad = 0;
	double carLen = 0;
	// first thing we check if the queue is empty
	if (Q.empty()) goto Deload;
	carLen = Q.front();
		// while the ferry fit the car we load it 
	while (ferryLoad + carLen <= ferryLen) {
			// load the car
		ferryLoad += carLen;
			// remove it from the queue
		Q.pop();
			// update the len of the car if the queue is not empty
		if (Q.empty()) break;
		carLen = Q.front();
	}

	Deload:
	// after finish loading we go to the other side and deload and count a travel
	if (ferryPosition == "right") ferryPosition = "left";
	else ferryPosition = "right";
	ferryLoad = 0;	
	travelCounter++;
}

int main() {
	int testCases; cin >> testCases;
	while (testCases--) {
		int ferryLen, numCars;
		cin >> ferryLen >> numCars;
			// car length, car side
		queue<double> leftQ;
		queue<double> rightQ;

			// fill the queue
		for (int i = 0; i < numCars; i++) {
			double carLen; cin >> carLen;
			string carSide; cin >> carSide;
			if (carSide == "left") leftQ.push( carLen / 100);
			else rightQ.push(carLen / 100);
		}

			// process qeuries
		int travelCounter = 0;
		string ferryPosition = "left";
			// while one of the two queues still have cars
		while (!rightQ.empty() || !leftQ.empty()) {
			if (ferryPosition == "left")
				processTheQueue(leftQ, travelCounter, ferryPosition, ferryLen);		
			else if (ferryPosition == "right" ) 
				processTheQueue(rightQ, travelCounter, ferryPosition, ferryLen);
			
		}
		cout << travelCounter << endl;
	}
}