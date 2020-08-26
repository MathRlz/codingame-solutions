#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Bender {
	struct State {
		bool inverted = false;
		bool breaker = false;
		enum Direction {
			SOUTH,
			EAST,
			NORTH,
			WEST
		} dir = SOUTH;
		struct Pos {
			int x, y;
		}p;

		bool operator==(const State& s2) {
			return breaker == s2.breaker &&
				dir == s2.dir &&
				inverted == s2.inverted &&
				p.x == s2.p.x &&
				p.y == s2.p.y;
		}
	};
	State state;
	vector<State> states;
	int priority = 0;
	bool alive = true;

	void find_loop() {
		int c = states.size() - 1;
		for (int i = states.size() - 2; i >= 0; --i) {
			if (states[c] == states[i]) {
				int d = i;
				while (d > 0 && c > i) {
					if (!(states[d] == states[c]))
						return;
					d--; c--;
				}
				states.clear();
				alive = false;
				std::cout << "LOOP" << endl;
			}
		}
	}

	void print_moves() {
		for (const auto& state : states)
			std::cout << dir_to_string(state.dir) << endl;
	}

	State::Pos new_pos() {
		State::Pos pos = state.p;
		switch (state.dir) {
		case State::SOUTH:
			pos.y++;
			break;
		case State::EAST:
			pos.x++;
			break;
		case State::NORTH:
			pos.y--;
			break;
		case State::WEST:
			pos.x--;
			break;
		}
		return pos;
	}

	void change_dir() {
		if (!state.inverted) {
			state.dir = static_cast<State::Direction>(priority);
		}
		else {
			state.dir = static_cast<State::Direction>(3 - priority);
		}
		priority++;
	}

	bool can_go(char symbol) {
		if (symbol == '#' || (!state.breaker && symbol == 'X')) {
			return false;
		}
		return true;
	}

	State::Pos teleport(const vector<string>& map) {
		for (int i = 1; i < map.size() - 1; i++) {
			for (int j = 1; j < map[i].length() - 1; j++) {
				if (map[i][j] == 'T' && (i != state.p.y || j != state.p.x)) {
					return State::Pos{ j, i };
				}
			}
		}
	}

	string dir_to_string(State::Direction dir) {
		switch (dir) {
		case State::SOUTH:
			return "SOUTH";
		case State::EAST:
			return "EAST";
		case State::NORTH:
			return "NORTH";
		case State::WEST:
			return "WEST";
		}
	}

	void clear_priority() {
		priority = 0;
	}

	void go(vector<string>& map) {
		auto tmp_p = new_pos();
		clear_priority();
		while (!can_go(map[tmp_p.y][tmp_p.x])) {
			change_dir();
			tmp_p = new_pos();
		}
		state.p = tmp_p;
		states.push_back(state);
		find_loop();
		char symbol = map[state.p.y][state.p.x];
		if (symbol == 'X')
			map[state.p.y][state.p.x] = ' ';
		else if (symbol == '$')
			alive = false;
		else if (symbol == 'S')
			state.dir = State::SOUTH;
		else if (symbol == 'E')
			state.dir = State::EAST;
		else if (symbol == 'N')
			state.dir = State::NORTH;
		else if (symbol == 'W')
			state.dir = State::WEST;
		else if (symbol == 'I')
			state.inverted = !state.inverted;
		else if (symbol == 'B')
			state.breaker = !state.breaker;
		else if (symbol == 'T')
			state.p = teleport(map);
	}
};

int main()
{
	int L, C;
	cin >> L >> C; cin.ignore();
	vector<string> map(L);
	Bender b;
	for (int i = 0; i < L; ++i) {
		string row;
		getline(cin, row);
		map[i] = row;
		auto f = map[i].find('@');
		if (f != string::npos) {
			b.state.p.y = i;
			b.state.p.x = f;
		}
	}
	while (b.alive) {
		b.go(map);
	}
	b.print_moves();
	
	return 0;
}