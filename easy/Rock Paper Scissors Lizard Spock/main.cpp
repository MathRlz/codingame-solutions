#include <iostream>
#include <string>
#include <vector>

using namespace std;

int gameTable[5][5] = {
	{-1, 1, 0, 0, 4},
	{1, -1, 2, 3, 1},
	{0, 2, -1, 2, 4},
	{0, 3, 2, -1, 3},
	{4, 1, 4, 3, -1}
};

struct player {
	int num;
	int signVal;
	vector<int> opponents;
	player(int num, char sign) : num(num) {
		if (sign == 'R')
			signVal = 0;
		else if (sign == 'P')
			signVal = 1;
		else if (sign == 'C')
			signVal = 2;
		else if (sign == 'L')
			signVal = 3;
		else if (sign == 'S')
			signVal = 4;
	}
};

player* battle(player* p1, player* p2) {
	p1->opponents.push_back(p2->num);
	p2->opponents.push_back(p1->num);
	int winner = gameTable[p1->signVal][p2->signVal];
	if (winner == p1->signVal) {
		delete p2;
		return p1;
	}
	else if (winner == p2->signVal) {
		delete p1;
		return p2;
	}
	else {
		if (p1->num < p2->num) {
			delete p2;
			return p1;
		}
		else {
			delete p1;
			return p2;
		}
	}
}

void war(player** players, int N) {
	if (N == 1) {
		auto winner = *players;
		cout << winner->num << endl;
		for (int i = 0; i < winner->opponents.size() - 1; ++i)
			cout << winner->opponents[i] << " ";
		cout << *(winner->opponents.end() - 1);
		delete[] players;
		return;
	}

	player** remaining = new player * [N / 2];
	for (int i = 0; i < N; i += 2) {
		player* winner = battle(players[i], players[i + 1]);
		remaining[i / 2] = winner;

	}
	war(remaining, N / 2);
	delete[] players;
}

int main()
{
	int N;
	cin >> N; cin.ignore();
	player** players = new player * [N];

	for (int i = 0; i < N; i++) {
		int NUMPLAYER;
		char SIGNPLAYER;
		cin >> NUMPLAYER >> SIGNPLAYER; cin.ignore();
		players[i] = new player(NUMPLAYER, SIGNPLAYER);
	}
	war(players, N);

	return 0;
}