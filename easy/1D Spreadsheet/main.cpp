#include <iostream>
#include <string>

using namespace std;

struct cell {
	string op;
	int val, val1, val2;
	struct cell* dep1 = nullptr, * dep2 = nullptr;
	bool calculated = false;
};

int calc(string op, int val1, int val2) {
	if (op == "VALUE")
		return val1;
	if (op == "ADD")
		return val1 + val2;
	if (op == "SUB")
		return val1 - val2;
	if (op == "MULT")
		return val1 * val2;
}
int eval(struct cell* cell) {
	if (cell->calculated)
		return cell->val;

	if (cell->dep1 != nullptr)
		cell->val1 = eval(cell->dep1);
	if (cell->dep2 != nullptr)
		cell->val2 = eval(cell->dep2);

	cell->val = calc(cell->op, cell->val1, cell->val2);
	cell->calculated = true;
	return cell->val;
}

int main()
{
	int N;
	cin >> N;
	string op, arg1, arg2;

	cell* cells = new cell[N];
	for (int i = 0; i < N; ++i) {
		cin >> op >> arg1 >> arg2;
		cells[i].op = op;

		if (arg1[0] == '$') {
			cells[i].dep1 = &cells[stoi(arg1.substr(1))];
		}
		else {
			cells[i].dep1 = nullptr;
			cells[i].val1 = stoi(arg1);
		}
		if (arg2[0] == '$') {
			cells[i].dep2 = &cells[stoi(arg2.substr(1))];
		}
		else if (arg2[0] != '_') {
			cells[i].dep2 = nullptr;
			cells[i].val2 = stoi(arg2);
		}
	}
	for (int i = 0; i < N; ++i)
		cout << eval(&cells[i]) << endl;
	delete[] cells;
}