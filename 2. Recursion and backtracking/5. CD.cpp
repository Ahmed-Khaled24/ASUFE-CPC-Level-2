#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &tracks, vector<int> &curResult, vector<int> &bestCase, int index, int sum, int max) {
	int bestCaseSum = accumulate(bestCase.begin(), bestCase.end(), 0);
	// Base case
	if (sum > max) 
		return;
	if (index >= tracks.size()) {
		if (sum > bestCaseSum)
			bestCase = curResult;
		return;
	}

	// ---------------------------------

	curResult.push_back(tracks.at(index));
	int newSum = sum + tracks.at(index);
	solve(tracks, curResult, bestCase, index + 1, newSum, max);

	curResult.pop_back();
	solve(tracks, curResult, bestCase, index + 1, sum, max);	
}

int main() {
	int maxDuration;
	while (cin >> maxDuration) {
		// read inputs
		int numberOfTracks; cin >> numberOfTracks;
		vector<int> tracks(numberOfTracks);
		for (int i = 0; i < numberOfTracks; i++) cin >> tracks.at(i);

		// solving
		vector<int> curResult, bestCase;
		if (accumulate(tracks.begin(), tracks.end(), 0) <= maxDuration) 
			bestCase = tracks;
		else 
			solve(tracks, curResult, bestCase, 0, 0, maxDuration);
		
		// printing
		int resultSum = accumulate(bestCase.begin(), bestCase.end(), 0);
		for (auto track : bestCase) cout << track << " ";
		cout << "sum:" << resultSum << endl;
	}
}