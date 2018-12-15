#include "funcs.h"

int answer1() {
	vector<int> x;
	vector<int> y;
	vector<int> xv;
	vector<int> yv;
	string s0, s1, s2, s3, s4;
	int i = 0;
	while(cin >> s0 >> x[i] >> s1 >> y[i] >> s2 >> xv[i] >> s3 >> yv[i++] >> s4);
	for (int i = 0; i < x.size(); ++i) {
		cout << "position: " << x[i] << " " << y[i] << endl;
		cout << "velocity: " << xv[i] << " " << yv[i] << endl;
	}
	return 0;
}

int answer2() {
	return 0;
}























//
