#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int treeSize = 0;
struct Node {
	char digit;
	vector<Node> children;
	Node(char digit) :digit(digit) { treeSize++; }
};

void insert(const string& number, Node& node) {
	if (number.length() == 0) return;

	auto it = find_if(node.children.begin(), node.children.end(), [&](const Node& node) {return node.digit == number[0]; });
	if (it == node.children.end()) {
		node.children.push_back(Node(number[0]));
		it = node.children.end() - 1;
	}
	insert(number.substr(1), *it);
}

int main() {
	int N;
	cin >> N;

	Node head(0);
	while (N--) {
		string number;
		cin >> number;
		insert(number, head);
	}
	cout << treeSize - 1;
	return 0;
}