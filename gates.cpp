#include <iostream>
#include <fstream>

int gateNum;
int planeNum;
int* requiredDockArr;

void getInput();

int main() {

	getInput();

	int* gateArr;
	gateArr = new int[gateNum];

	memset(gateArr, 0, gateNum * sizeof(int));

	bool airportClosed = false;

	for(int i = 0; i < planeNum; i++) {

		if(airportClosed) {
			break;
		}

		for(int j = requiredDockArr[i] - 1; j >= 0; j--) {
			if(gateArr[j] == 0) {
				gateArr[j]++;
				break;
			}
			if(j == 0 && gateArr[0] != 0) {
				airportClosed = true;
			}
		}

	}

	int count = 0;

	for(int i = 0; i < gateNum; i++) {
		if(gateArr[i] != 0) {
			count++;
		}
	}

	std::printf("%d\n", count);

	delete [] gateArr;

}

void getInput() {

	std::ifstream file;
	file.open("s3.10.in");

	file >> gateNum;
	file >> planeNum;

	requiredDockArr = new int[planeNum];

	for(int i = 0; i < planeNum; i++) {
		file >> requiredDockArr[i];
	}

}