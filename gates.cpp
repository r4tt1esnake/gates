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

	for(int i = 0; i < planeNum; i++) {
		if(gateArr[requiredDockArr[planeNum] - 1] == 0) {
			gateArr[requiredDockArr[planeNum] - 1]++;
		}
		else {
			for(int i = requiredDockArr[planeNum] - 1; i > 0; i--) {
				if(gateArr[i] == 0) {
					gateArr[i]++;
					break;
				}
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

}

void getInput() {

	std::ifstream file;
	file.open("s3.1.in");

	file >> gateNum;
	file >> planeNum;

	requiredDockArr = new int[planeNum];

	for(int i = 0; i < planeNum; i++) {
		file >> requiredDockArr[i];
	}

}