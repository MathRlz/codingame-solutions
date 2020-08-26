#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
	int w, h, noMeasureX, noMeasureY;
	cin >> w >> h >> noMeasureX >> noMeasureY; cin.ignore();

	noMeasureX += 2; noMeasureY += 2;
	vector<int> x(noMeasureX), y(noMeasureY);
	x[0] = 0; y[0] = 0; x[noMeasureX - 1] = w; y[noMeasureY - 1] = h;

	for (int i = 1; i < noMeasureX - 1; i++)
		cin >> x[i];
	for (int i = 1; i < noMeasureY - 1; i++)
		cin >> y[i];

	unordered_map<long, int> mx, my;
	for (int i = 0; i < x.size(); ++i)
		for (int j = i + 1; j < x.size(); ++j)
			mx[x[j] - x[i]]++;
	for (int i = 0; i < y.size(); ++i)
		for (int j = i + 1; j < y.size(); ++j)
			my[y[j] - y[i]]++;

	int noSquares = 0;
	auto& longest = (mx.size() > my.size()) ? mx : my;
	auto& shortest = (mx.size() > my.size()) ? my : mx;

	for (auto& k : longest)
		if (shortest.find(k.first) != shortest.end())
			noSquares += k.second * shortest[k.first];
	cout << noSquares;
	return 0;
}