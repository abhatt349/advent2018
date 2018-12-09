#include "funcs.h"


int answer1() {
	string s;
	bool arr[26][26] = {{}};
	for (int i = 0; i < 26; ++i) {
		for (int j = 0; j < 26; ++j) {
			arr[i][j] = true;
		}
	}
	while (getline(cin, s)) {
		arr[s[36]-'A'][s[5]-'A'] = false;
		//cout << s[36]-'A' << " " << s[5]-'A' << endl;
	}
	s = "";
	bool done[26] = {false};
	while (s.length() < 26) {
		for (int i = 0; i < 26; ++i) {
			bool yea = true;
			for (int j = 0; j < 26; ++j) {
				yea = yea and arr[i][j];
			}
			if (yea and !done[i]) {
				s += 'A' + i;
				for (int j = 0; j < 26; ++j) {
					arr[j][i] = true;
				}
				done[i] = true;
				i = 26;
			}
		}
		if (s.length()) {
			cout << s << endl;
		}
	}
	cout << s << endl;
	return 0;
}

int answer2() {
	string s;
	bool arr[26][26] = {{}};
	for (int i = 0; i < 26; ++i) {
		for (int j = 0; j < 26; ++j) {
			arr[i][j] = true;
		}
	}
	while (getline(cin, s)) {
		arr[s[36]-'A'][s[5]-'A'] = false;
		//cout << s[36]-'A' << " " << s[5]-'A' << endl;
	}
	int workers[5] = {};
	int left[5] = {};
	for (int i = 0; i < 5; ++i) {
		workers[i] = -1;
		left[i] = -1;
	}
	s = "";
	bool done[26] = {false};
	int second = 0;
	while (s.length() < 26) {

		for (int i = 0; i < 5; ++i) {
			if (left[i] == 0) {
				s += 'A' + workers[i];
				for (int j = 0; j < 26; ++j) {
					arr[j][workers[i]] = true;
				}
				workers[i] = -1;
			}
		}

		for (int i = 0; i < 26; ++i) {
			bool yea = true;
			for (int j = 0; j < 26; ++j) {
				yea = yea and arr[i][j];
			}
			if (yea and !done[i]) {
				for (int j = 0; j < 5; ++j) {
					if (workers[j] == -1) {
						workers[j] = i;
						left[j] = 61 + i;
						done[i] = true;
						j = 5;
					}
				}
			}
		}
		//cout << second << "\t" << workers[0] << "\t" << workers[1] << "\t" << workers[2] << "\t" << workers[3] << "\t" << workers[4] << "\t" << s << endl;
		for (int i = 0; i < 5; ++i) {
			left[i]--;
		}
		second++;
	}
	//cout << s << endl;
	return second-1;
}























//
