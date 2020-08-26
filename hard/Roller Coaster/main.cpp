#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int checkForLoop(const vector<vector<int>>& rides, const vector<int>& ride) {
	for (int i = 0; i < rides.size(); ++i) {
		if (rides[i] == ride)
			return i;
	}
	return -1;
}
int main() {
	int no_places, no_groups, runs;
	cin >> no_places;
	cin >> runs;
	cin >> no_groups;
	vector<int> groups(no_groups);
	for (int i = 0; i < no_groups; ++i)
		cin >> groups[i];


	long long money = 0;
	vector<vector<int>> rides;

	int groupIndex = 0;
	for (int i = 0; i < runs; ++i) {
		int on_ride = 0;
		vector<int> ride;
		int groups_on_ride = 0;
		while (groups_on_ride < no_groups) {
			if (on_ride + groups[groupIndex] > no_places)
				break;
			on_ride += groups[groupIndex];
			ride.push_back(groupIndex);
			groups_on_ride++;
			if (++groupIndex == groups.size())
				groupIndex = 0;
		}

		ride.push_back(on_ride);
		int loopIndex = checkForLoop(rides, ride);
		if (loopIndex >= 0) {
			long long remaining_rides = runs - i;
			long long cycles = remaining_rides / (rides.size() - loopIndex);
			long long leftOver = remaining_rides % (rides.size() - loopIndex);
			long long loopVal = 0;
			for (int j = loopIndex; j < rides.size(); ++j)
				loopVal += *(rides[j].end() - 1);
			long long leftOverVal = 0;
			for (int j = loopIndex; j < loopIndex + leftOver; ++j)
				leftOverVal += *(rides[j].end() - 1);
			money += cycles * loopVal + leftOverVal;
			break;
		}
		else {
			money += on_ride;
			rides.push_back(ride);
		}
	}
	cout << money;
	return 0;
}