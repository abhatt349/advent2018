#include "funcs.h"

int answer1() {
	int a, b, c, d;
	string s1, s2, s3;
	char c1, c2;
	int arr[1000][1000] = {};
	while (cin >> s1 >> s2 >> a >> c1 >> b >> s3 >> c >> c2 >> d) {
		for (int i = a; i < a+c; ++i) {
			for (int j = b; j < b+d; ++j) {
				arr[i][j]++;
			}
		}
	}
	int ret = 0;
	for (int i = 0; i < 1000; ++i) {
		for (int j = 0; j < 1000; ++j) {
			if (arr[i][j] > 1) {
				ret++;
			}
		}
	}
	return ret;   // */
}

string answer2() {
	int a, b, c, d;
	string s1, s2, s3;
	char c1, c2;
	int arr[1000][1000] = {};
	int ctr = 1;
	while (ctr < 1350) {
		cin >> s1 >> s2 >> a >> c1 >> b >> s3 >> c >> c2 >> d;
		for (int i = a; i < a+c; ++i) {
			for (int j = b; j < b+d; ++j) {
				arr[i][j]++;
			}
		}
		ctr++;
	}
	while (cin >> s1 >> s2 >> a >> c1 >> b >> s3 >> c >> c2 >> d) {
		bool check = true;
		for (int i = a; i < a+c; ++i) {
			for (int j = b; j < b+d; ++j) {
				if (arr[i][j] > 1) {
					check = false;
				}
			}
		}
		if (check) {
			return s1;
		}
	}

}













//
