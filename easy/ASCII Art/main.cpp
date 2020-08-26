#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ?";
    vector<string> alpha_ascii;
    int L, H;
    string T;
    cin >> L >> H; cin.ignore();
    getline(cin, T);
    cerr << T;
    string line;
    for (int i = 0; i < H; i++) {
        getline(cin, line);
        alpha_ascii.push_back(line);
        cerr << line;
    }

    vector<string> output(H, "");
    for (int i = 0; i < T.length(); i++) {
        char s = toupper(T[i]);
        if ((s < 'A') or (s > 'Z'))
            s = '?';
        int index = alpha.find(s);
        for (int j = 0; j < H; j++)
            output[j] += alpha_ascii[j].substr(index * L, L);
    }

    for (int i = 0; i < H; i++)
        cout << output[i] << endl;

    return 0;
}