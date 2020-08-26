#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct calc {
	int startDate, endDate;
};

int main()
{
	int N, J, D;
	cin >> N; cin.ignore();

	vector<calc> calcs(N);
	for (int i = 0; i < N; i++) {
		cin >> J >> D; cin.ignore();
		calcs[i].startDate = J;
		calcs[i].endDate = J + D - 1;
	}
	sort(calcs.begin(), calcs.end(), [](const auto& c1, const auto& c2) -> bool {
		return c1.endDate < c2.endDate;
		});

	int currEnd = -1, count = 0;
	for (const auto& calc : calcs) {
		if (currEnd < calc.startDate) {
			currEnd = calc.endDate;
			count++;
		}
	}
	cout << count << endl;

	return 0;
}