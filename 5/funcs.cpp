#include "funcs.h"


int answer1() {
	string s;
	cin >> s;
	bool go = true;
	while (go) {
		go = false;
		for (int i = 0; i < s.length()-1; ++i) {
			if (abs(s[i] - s[i-1]) == ('a' - 'A')) {
				s = s.substr(0,i-1) + s.substr(i+1);
				go = true;
				i -= 2;
			}
		}
	}
	return s.length();
}

int answer2() {
	string s;
	cin >> s;
	string arr[26];
	for (int i = 0; i < 26; ++i) {
		for (int j = 0; j < s.length(); ++j) {
			if (!(s[j] == 'a'+i || s[j] == 'A'+i)) {
				arr[i] += s[j];
			}
		}
	}
	double min = s.length() + 1000;
	for (int j = 0; j < 26; ++j) {
		bool go = true;
		while (go) {
			go = false;
			for (int i = 0; i < arr[j].length()-1; ++i) {
				if (abs(arr[j][i] - arr[j][i-1]) == ('a' - 'A')) {
					arr[j] = arr[j].substr(0,i-1) + arr[j].substr(i+1);
					go = true;
					i -= 2;
				}
			}
		}
		if (arr[j].length() < min) {
			min = arr[j].length();
		}
	}
	return min;
}























//
