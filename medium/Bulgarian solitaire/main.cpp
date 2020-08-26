#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int isLoop(const vector<vector<int>>& configurations, vector<int>& configuration) {
	for (int i = configurations.size() - 1; i >= 0; --i) {
		if (configurations[i] == configuration)
			return configurations.size() - i;
	}
	return 0;
}
void remZerosAndSort(vector<int>& vec) {
	vec.erase(std::remove(vec.begin(), vec.end(), 0), vec.end());
	sort(vec.begin(), vec.end());
}
int main()
{
	int N;
	cin >> N; cin.ignore();
	vector<vector<int>> configurations;
	configurations.push_back(vector<int>());
	for (int i = 0; i < N; i++) {
		int C;
		cin >> C; cin.ignore();
		configurations[0].push_back(C);
	}
	int i = 0;
	remZerosAndSort(configurations[0]);
	while (1) {
		vector<int> noweUstawienie;
		noweUstawienie.push_back(configurations[i].size());
		for (const auto& e : configurations[i]) {
			noweUstawienie.push_back(e - 1);
		}
		remZerosAndSort(noweUstawienie);
		int loop_length = isLoop(configurations, noweUstawienie);
		if (loop_length > 0) {
			cout << loop_length << endl;
			break;
		}
		configurations.push_back(noweUstawienie);
		i++;
	}
}