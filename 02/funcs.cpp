#include "funcs.h"

int answer1() {
	string s;
	int twos = 0;
	int threes = 0;
	while (cin >> s) {
		vector<int> arr(26, 0);
		for (int i = 0; i < s.size(); ++i) {
			arr[s[i] - 'a']++;
		}
		for (int i = 0; i < 26; i++) {
			if (arr[i] == 2) {
				twos++;
				break;
			}
		}
		for (int i = 0; i < 26; i++) {
			if (arr[i] == 3) {
				threes++;
				break;
			}
		}
	}
	return twos * threes;
}

string helper(string s1, string s2) {
	int x = 0;
	for (int i = 0; i < s1.size(); ++i) {
		if (s1[i] != s2[i]) {
			x++;
		}
	}
	string s;
	if (x == 1) {
		for (int i = 0; i < s1.size(); ++i) {
			if (s1[i] == s2[i]) {
				s += s1[i];
			}
		}
	}
	return s;
}

string answer2() {
	string s;
	vector<string> arr;
	while (cin >> s) {
		arr.push_back(s);
	}
	for (int i = 0; i < arr.size(); ++i) {
		for (int j = 0; j < arr.size(); ++j) {
			if (helper(arr[i],arr[j]).size()) {
				return helper(arr[i], arr[j]);
			}
		}
	}
	return 0;
}













//
