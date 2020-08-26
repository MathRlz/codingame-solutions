#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, C, sum = 0;
	cin >> N >> C;
	vector<int> budg(N), part;
	for (int i = 0; i < N; i++) {
		int B;
		cin >> B;
		budg[i] = B;
		sum += B;
	}
	if (sum >= C){
		sum = 0;
		sort(budg.begin(), budg.end());
		int avg = (C - sum) / N;
		for (unsigned int i = 0; i < budg.size(); i++) {
			if (budg[i] < avg) {
				part.push_back(budg[i]);
				sum += budg[i];
			}
			else {
				part.push_back(avg);
				sum += avg;
			}
		}
		int i = N - 1;;
		while (sum != C) {
			if (part[i] < budg[i]) {
				part[i]++;
				sum++;
			}
			i--;
			if (i < 0)
				i = N - 1;
		}

		for (unsigned int i = 0; i < part.size(); i++) {
			cout << part[i] << endl;
		}
	}
	else
		cout << "IMPOSSIBLE" << endl;

	return 0;
}