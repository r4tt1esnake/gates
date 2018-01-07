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

	for(int i = 0; i < gateNum; i++) {
		gateArr[i] = 0;
	}

	for(int i = 0; i < planeNum; i++) {
		for(int j = requiredDockArr[i] - 1; j > 0; j--) {
			if(gateArr[j] == 0) {
				gateArr[j]++;
				break;
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
	file.open("s3.2.in");

	file >> gateNum;
	file >> planeNum;

	requiredDockArr = new int[planeNum];

	for(int i = 0; i < planeNum; i++) {
		file >> requiredDockArr[i];
	}

}