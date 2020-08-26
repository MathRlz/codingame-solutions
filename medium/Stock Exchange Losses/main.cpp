#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    int n;
    int stockValues[100000];
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        cin >> stockValues[i]; cin.ignore();
    }
    int maximalLoss = 0, lastPeakIndex = 0;
	for (int i = lastPeakIndex + 1; i < n; i++) {
		int lossOrGainFromLastPeak = stockValues[i] - stockValues[lastPeakIndex];
		if (lossOrGainFromLastPeak < 0 && lossOrGainFromLastPeak < maximalLoss) {
			maximalLoss = lossOrGainFromLastPeak;
		} else if (lossOrGainFromLastPeak > 0) {
			lastPeakIndex = i;
		}
	}
    cout << maximalLoss << endl;
	return 0;
}