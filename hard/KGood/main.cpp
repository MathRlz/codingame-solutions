#include <iostream>
#include <string>

using namespace std;

bool isValid(int count[], int k) {
	int val = 0;
	for (int i = 0; i < 26; i++)
		if (count[i] > 0)
			val++;
	return (k >= val);
}

int main()
{
	string S;
	getline(cin, S);
	int K;
	cin >> K; cin.ignore();

	int count[26] = { 0 };
	int curr_start = 0, curr_end = 0;
	int max_len = 0;

	count[S[0] - 'a'] = 1;
	for (int i = 1; i < S.length(); i++) {
		count[S[i] - 'a']++;
		curr_end++;

		while (!isValid(count, K))
			count[S[curr_start++] - 'a']--;

		if (curr_end - curr_start + 1 > max_len)
			max_len = curr_end - curr_start + 1;
	}
	
	cout << max_len;
	return 0;
}