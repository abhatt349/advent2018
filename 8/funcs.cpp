#include "funcs.h"


int answer1() {
	int x;
	vector<int> v;
	while (cin >> x) {
		v.push_back(x);
	}
	int total = 0;
	reduce(v, total, 0);
	return total;
}

void reduce(vector<int> &v, int &total, int pos) {
	if (v[pos]) {
		reduce(v, total, pos+2);
		v[pos]--;
		for (int i = 0; i < v.size(); ++i) {
			cout << v[i] << " ";
		}
		cout << "pos: " << pos << endl;
		reduce(v, total, pos);
	}
	else {
		for (int i = pos; i < pos+v[1]; ++i) {
			total += v[2+i];
		}
		v.erase(v.begin()+pos, v.begin()+pos+2+v[pos+1]);
	}
}


int answer2() {
	return 0;
}























//
