#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int W;
	int H;
	cin >> W >> H; cin.ignore();
	vector<string> map(H);
	for (int i = 0; i < H; i++) {
		string line;
		getline(cin, line);
		map[i] = line;
	}

	for (int letter = 0; letter < W; letter += 3) {
		int posY = 0, posX = letter;
		while (posY < H) {
			if (posX > 1 && map[posY][posX - 1] == '-')
				posX -= 3;
			else if (posX < W - 1 && map[posY][posX + 1] == '-')
				posX += 3;
			posY++;
		}

		cout << map[0][letter] << map[H - 1][posX] << endl;
	}
}