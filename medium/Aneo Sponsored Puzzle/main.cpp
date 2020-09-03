#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct trafficLight {
	double distance;
	double duration;
};

bool canMakeItGreen(const trafficLight& light, double speed) {
	double time = 3.6 * light.distance / speed;
	int lightChanges = static_cast<int> (time / light.duration);

	return lightChanges % 2 == 0;
}

int main() {
	int maxSpeed, lightCount;
	cin >> maxSpeed >> lightCount;
	vector<trafficLight> trafficLights(lightCount);
	for (int i = 0; i < lightCount; i++)
		cin >> trafficLights[i].distance >> trafficLights[i].duration;

	vector<int> possibleSpeeds(maxSpeed);
	iota(possibleSpeeds.begin(), possibleSpeeds.end(), 1);

	for (const auto& light : trafficLights) {
		auto it = possibleSpeeds.begin();
		while (it != possibleSpeeds.end()) {
			if (!canMakeItGreen(light, static_cast<double>(*it))) {
				it = possibleSpeeds.erase(it);
			}
			else {
				it++;
			}
		}
	}

	cout << *(possibleSpeeds.end() - 1);
	return 0;
}