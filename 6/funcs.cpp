#include "funcs.h"


int answer1() {
	int x[50];
	int y[50];
	char c;
	int i = 0;
	while (i < 50 && cin >> x[i] >> c >> y[i++]);
	int arr[1000][1000] = {};
	for (int i = 0; i < 1000; ++i) {
		for (int j = 0; j < 1000; ++j) {
			int minDist = 5000;
			int min = -1;
			bool notWork = false;
			for (int k = 0; k < 50; ++k) {
				if (abs(i-300-x[k]) + abs(j-300-y[k]) < minDist) {
					minDist = abs(i-300-x[k]) + abs(j-300-y[k]);
					min = k;
					notWork = false;
				}
				else if (abs(i-300-x[k]) + abs(j-300-y[k]) == minDist) {
					notWork = true;
				}
			}
			if (notWork) {
				arr[i][j] = 50;
			}
			else {
				arr[i][j] = min;
			}
		}
	}
	int count[51] = {};
	for (int i = 0; i < 1000; ++i) {
		for (int j = 0; j < 1000; ++j) {
			count[arr[i][j]]++;
		}
	}
	for (int i = 0; i < 1000; ++i) {
		count[arr[i][0]] = 0;
		count[arr[i][999]] = 0;
	}
	for (int j = 0; j < 1000; ++j) {
		count[arr[0][j]] = 0;
		count[arr[999][j]] = 0;
	}
	int max = -1;
	for (int i = 0; i < 50; ++i) {
		//cout << i << ": " << count[i] << endl;
		if (count[i] > max) {
			max = count[i];
		}
	}
	return max;
}

int answer2() {
	int size = 0;
	int x[50];
	int y[50];
	char c;
	int i = 0;
	while (i < 50 && cin >> x[i] >> c >> y[i++]);
	int arr[1000][1000] = {};
	for (int i = 0; i < 1000; ++i) {
		for (int j = 0; j < 1000; ++j) {
			for (int k = 0; k < 50; ++k) {
				arr[i][j] += abs(i-300-x[k]);
				arr[i][j] += abs(j-300-y[k]);
			}
		}
	}
	for (int i = 0; i < 1000; ++i) {
		for (int j = 0; j < 1000; ++j) {
			if (arr[i][j] < 10000) {
				size++;
			}
		}
	}
	return size;
}























//
