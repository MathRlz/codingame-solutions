#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Vec3 {
	long x, y, z;
};
struct Apple {
	Vec3 pos;
	long r;
};

long long distanceSquared(const Vec3& pos1, const Vec3& pos2) {
	long long dx = pos1.x - pos2.x;
	long long dy = pos1.y - pos2.y;
	long long dz;
	if (pos1.z > pos2.z)
		dz = 0;
	else
		dz = pos1.z - pos2.z;
	return dx * dx + dy * dy + dz * dz;
}

bool doesItCollide(const Apple& a1, const Apple& a2) {
	long long rSquared = a1.r + a2.r;
	rSquared *= rSquared;
	return distanceSquared(a1.pos, a2.pos) < rSquared;
}

int main()
{
	int N, fallingApple;
	cin >> N >> fallingApple; cin.ignore();
	vector<Apple> apples(N);
	for (int i = 0; i < N; i++) {
		cin >> apples[i].pos.x >> apples[i].pos.y >> apples[i].pos.z >> apples[i].r; cin.ignore();
	}

	vector<Apple> fallingApples;
	fallingApples.push_back(apples[fallingApple]);
	apples.erase(apples.begin() + fallingApple);

	while (fallingApples.size() > 0) {
		auto apple = fallingApples[0];
		for (auto it = apples.begin(); it != apples.end();) {
			if (doesItCollide(apple, *it) == true) {
				fallingApples.push_back(*it);
				it = apples.erase(it);
			}
			else {
				++it;
			}
		}
		fallingApples.erase(fallingApples.begin());
	}
	cout << apples.size();
	return 0;
}