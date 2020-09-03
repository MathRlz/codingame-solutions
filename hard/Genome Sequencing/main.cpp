#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int sequenceLength(const vector<string>& subSequences) {
	string sequence = subSequences[0];
	for (size_t i = 1; i < subSequences.size(); ++i) {
		size_t j;
		for (j = 0; j < sequence.length(); ++j) {
			// subsequence already in sequence
			if (sequence.find(subSequences[i]) != string::npos) {
				break;
			}
			else if (sequence.substr(j) == subSequences[i].substr(0, sequence.length() - j)) {
				// append genomes that are not part of the sequence
				sequence += subSequences[i].substr(sequence.length() - j);
				break;
			}
		}
		if (j == sequence.length()) // didn't find subsequence - appending it
			sequence += subSequences[i];
	}
	return sequence.length();
}

int main() {
	int N;
	cin >> N; cin.ignore();
	vector<string> subSequences(N);
	for (int i = 0; i < N; i++)
		cin >> subSequences[i];
	sort(subSequences.begin(), subSequences.end());

	int minLength = numeric_limits<int>::max();
	do {
		minLength = min(minLength, sequenceLength(subSequences));
	} while (next_permutation(subSequences.begin(), subSequences.end()));

	cout << minLength << endl;
	return 0;
}