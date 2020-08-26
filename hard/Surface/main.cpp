#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

struct point {
	int x, y;
};
int getWaterArea(vector<string> map, point p) {
	deque<point> stack;
	stack.push_back(p);

	int cnt = 0;
	while (stack.size() > 0) {
		p = stack.front(); stack.pop_front();
		if (false == (p.x >= 0 && p.y >= 0 && p.x < map[0].size() && p.y < map.size()))
			continue;

		if (map[p.y][p.x] == 'O') {
			map[p.y][p.x] = 'X';
			cnt++;
			stack.push_back(point{ p.x, p.y + 1 });
			stack.push_back(point{ p.x, p.y - 1 });
			stack.push_back(point{ p.x + 1, p.y });
			stack.push_back(point{ p.x - 1, p.y });
		}
	}
	return cnt;
}

int main()
{
	int L, H, N;
	cin >> L >> H; cin.ignore();

	vector<string> map(H);
	for (int i = 0; i < H; i++)
		getline(cin, map[i]);

	cin >> N;
	vector<point> points(N);
	for (int i = 0; i < N; i++)
		cin >> points[i].x >> points[i].y;

	for (const auto& point : points)
		cout << getWaterArea(map, point) << endl;

	return 0;
}