#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int to_val(const string& s) {
    switch (s[0]) {
    case 'J':
        return 11;
    case 'Q':
        return 12;
    case 'K':
        return 13;
    case 'A':
        return 14;
    default:
        return stoi(s.substr(0, s.length() - 1));
    }
}

int main()
{
    int n, m;
    queue<int> q1, q2;
    string tmp;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        q1.push(to_val(tmp));
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> tmp;
        q2.push(to_val(tmp));
    }

    int roundCounter = 0;
    while (q1.size() > 0 && q2.size() > 0) {
        vector<int> warPile1, warPile2;
        warPile1.push_back(q1.front());
        warPile2.push_back(q2.front());
        q1.pop(); q2.pop();

        while (warPile1.back() == warPile2.back()) {
            if (q1.size() < 4 || q2.size() < 4) {
                cout << "PAT";
                return 0;
            }
            for (int i = 0; i < 4; ++i) {
                warPile1.push_back(q1.front());
                warPile2.push_back(q2.front());
                q1.pop(); q2.pop();
            }
        }
        if (warPile1.back() > warPile2.back()) {
            for (auto& c : warPile1)
                q1.push(c);
            for (auto& c : warPile2)
                q1.push(c);
        }
        else {
            for (auto& c : warPile1)
                q2.push(c);
            for (auto& c : warPile2)
                q2.push(c);
        }
        roundCounter++;
    }

    cout << (q1.size() > 0 ? '1' : '2') << ' ' << roundCounter << endl;
}