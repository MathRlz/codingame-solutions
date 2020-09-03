#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct SpaceShip {
	double hp, damage, damageToShip, turnsToKill;
};

int main() {
	int N;
	cin >> N;
	vector<SpaceShip> spaceShips(N);
	for (auto& ship : spaceShips) {
		string type;
		int armor;
		cin >> type >> ship.hp >> armor >> ship.damage; cin.ignore();
		double damageToShip = (type == "FIGHTER") ? 20 : 10;
		damageToShip -= armor;
		damageToShip = (damageToShip > 0) ? damageToShip : 1;
		ship.damageToShip = damageToShip;
		ship.turnsToKill = ceil(ship.hp / damageToShip);
	}

	sort(spaceShips.begin(), spaceShips.end(), [](const SpaceShip& ship1, const SpaceShip& ship2) {
		return ship1.turnsToKill / ship1.damage < ship2.turnsToKill / ship2.damage;
		});

	int shield = 5000;
	while (shield >= 0 && spaceShips.size() > 0) {
		for (const auto& ship : spaceShips)
			shield -= ship.damage;
		spaceShips[0].hp -= spaceShips[0].damageToShip;
		if (spaceShips[0].hp <= 0)
			spaceShips.erase(spaceShips.begin());
	}

	if (shield >= 0)
		cout << shield << endl;
	else
		cout << "FLEE" << endl;
	return 0;
}