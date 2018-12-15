#include "funcs.h"

int marc(string s) {
	return stoi(s.substr(6,2)) * 60 * 24 * 31 +
				 stoi(s.substr(9,2)) * 60 * 24 +
				 stoi(s.substr(12,2))* 60 +
				 stoi(s.substr(15,2));
}

int whatmin(string s) {
	return stoi(s.substr(15,2));
}

bool help(string i, string j) {
	return marc(i) < marc(j);
}

int answer1() {
	string s;
	vector<string> v;
	while (getline(cin, s)) {
		v.push_back(s);
	}
	sort(v.begin(), v.end(), help);
	int minutes[4000] = {};
	int guard;
	bool awake;
	for (int i = 0; i < v.size(); ++i) {
		//cout << guard << "\t" << v[i] << endl;
		if (v[i][19] == 'G') {
			awake = true;
			guard = stoi(v[i].substr(26,v[i].length()-39));
		}
		else if (v[i][19] == 'f') {
			awake = false;
		}
		else if (v[i][19] == 'w') {
			awake = true;
			minutes[guard] += marc(v[i]) - marc(v[i-1]);
			//cout << guard << "\t" << "woke up after " << marc(v[i]) - marc(v[i-1]) << endl;
		}
	}
	int max = -1;
	guard = -1;
	for (int i = 0; i < 4000; ++i) {
		if (minutes[i] > max) {
			max = minutes[i];
			guard = i;
		}
	}
	int guardperm = guard;
	int which[60] = {};
	for (int i = 0; i < v.size(); ++i) {
		//cout << guard << "\t" << v[i] << endl;
		if (v[i][19] == 'G') {
			awake = true;
			guard = stoi(v[i].substr(26,v[i].length()-39));
		}
		else if (v[i][19] == 'f') {
			awake = false;
		}
		else if (v[i][19] == 'w') {
			awake = true;
			if (guard == guardperm) {
				for (int j = whatmin(v[i-1]); j < whatmin(v[i]); ++j) {
					which[j]++;
				}
			}
			//cout << guard << "\t" << "woke up after " << marc(v[i]) - marc(v[i-1]) << endl;
		}
	}
	max = -1;
	int bro = -1;
	for (int i = 0; i < 60; ++i) {
		if (which[i] > max) {
			max = which[i];
			bro = i;
		}
	}
	return guardperm * bro;  // */
}

int answer2() {
	string s;
	vector<string> v;
	while (getline(cin, s)) {
		v.push_back(s);
	}
	sort(v.begin(), v.end(), help);
	int guard;
	bool awake;
	int **which;
	which = new int*[60];
	for (int i = 0; i < 60; ++i) {
		which[i] = new int[4000];
	}
	for (int i = 0; i < 60; ++i) {
		for (int j = 0; j < v.size(); ++j) {
			//cout << guard << "\t" << v[j] << endl;
			if (v[j][19] == 'G') {
				awake = true;
				guard = stoi(v[j].substr(26,v[j].length()-39));
			}
			else if (v[j][19] == 'f') {
				awake = false;
			}
			else if (v[j][19] == 'w') {
				awake = true;
				for (int n = whatmin(v[j-1]); n < whatmin(v[j]); ++n) {
					which[n][guard]++;
				}
				//cout << guard << "\t" << "woke up after " << marc(v[j]) - marc(v[j-1]) << endl;
			}
		}
	}
	int maxi = -1;
	int maxj = -1;
	int max = -1;
	for (int i = 0; i < 60; ++i) {
		for (int j = 0; j < 4000; ++j) {
			if (which[i][j] > max) {
				maxi = i;
				maxj = j;
				max = which[i][j];
				cout << which[i][j] << " ";
			}
		}
		cout << endl;
	}
	for (int i = 0; i < 60; ++i) {
		delete which[i];
	}
	delete which;
	cout << maxi << " " << maxj << endl;
	return maxi * maxj;
}












//
