#include<bits/stdc++.h>
using namespace std; 
int main() {
	int numberOfCommands;
	while (cin >> numberOfCommands) {
		int  isQ = 0, isPQ = 0, isStk = 0, checks = 0;
		queue<int> Q;
		priority_queue<int> PQ;
		stack<int> Stk;
		for (int i = 0; i < numberOfCommands; i++) {
			int command, value; cin >> command >> value;
				// if the command is 1 we insert the value into out data structures
			if (command == 1) Q.push(value), PQ.push(value), Stk.push(value);
				// if command is 2 we check the pop of each data structure and compare with value
			else if (command == 2) {
				checks++;
				if (!Q.empty()) {					
					// get the pop of each data structure
					int queuePop = Q.front(), priorityQueuePop = PQ.top(), stackPop = Stk.top();
					// remove one element from each data structure for the next loop
					Q.pop(), PQ.pop(), Stk.pop();
					// check if the return value is equal to the return from each data structure
					if (value == queuePop) isQ++;
					if (value == priorityQueuePop) isPQ++;
					if (value == stackPop) isStk++;
				}
			}		
		}

		if ((isStk == checks && isQ == checks) || (isStk == checks && isPQ == checks) || (isQ == checks && isPQ == checks)) 
			cout << "not sure" << endl;
		else if (isStk != checks && isQ != checks && isPQ != checks) 
			cout << "impossible" << endl;
		else if (isStk == checks) 
			cout << "stack" << endl;
		else if (isQ == checks) 
			cout << "queue" << endl;
		else if (isPQ == checks) 
			cout << "priority queue" << endl;
	}
	return 0;
}