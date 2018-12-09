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
		reduce(v, total, pos);
	}
	else {
		for (int i = pos; i < pos+v[pos+1]; ++i) {
			total += v[2+i];
		}
		v.erase(v.begin()+pos, v.begin()+pos+2+v[pos+1]);
   	/*
		for (int i = 0; i < v.size(); ++i) {
			cout << v[i] << " ";
		}
		cout << "pos: " << pos << " | total: " << total << endl;
		//   */
	}
}
int len(vector<int> v, int pos) {
	int ret = 0;
	int childrenLeft = v[pos];
	if (childrenLeft) {
		ret += 2 + v[pos+1];
		while (childrenLeft) {
			ret += len(v, pos + 2);
			pos += len(v, pos + 2);
			childrenLeft--;
		}
		return ret;
	}
	else {
		return 2 + v[pos+1];
	}
}
/*
vector<int> child(vector<int> v, int index) {
	if (index) {
		vector<int> ret;

	}
	else {
		vector<int> ret;

	}
}
*/
/*
void reduce(vector<int> &v, int &total, int pos, int end) {
	if (v[pos] == 0) {
		for (int i = 0; i < v[pos+1]; ++i) {
			total += v[pos+2+i];
		}
	}
	else {

	}
}
*/

int func(vector<int> v, int pos) {
	if (v[pos] == 0) {
		int ret = 0;
		for (int i = 0; i < v[pos+1]; ++i) {
			ret += v[pos+2+i];
		}
		return ret;
	}
	int point = pos + 2;
	//vector<int> vals(v[pos]);
	const int n = v[pos];
	int vals[n];
	for (int i = 0; i < v[pos]; ++i) {
		vals[i] = func(v, point);
		point += len(v, point);
	}
	int ret = 0;
	for (int i = 0; i < v[pos+1]; ++i) {
		if (v[pos + len(v,pos) - 1 - i] <= v[pos] and v[pos + len(v,pos) - 1 - i]) {
			ret += vals[v[pos + len(v,pos) - 1 - i] - 1];
		}
	}
	return ret;
}


int answer2() {
	int x;
	vector<int> v;
	while (cin >> x) {
		v.push_back(x);
	}

	return func(v, 0);
}























//
