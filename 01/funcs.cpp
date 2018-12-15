#include "funcs.h"

int answer1() {
	int x;
	int ret = 0;
	while (cin >> x) {
		ret += x;
	}
	return ret;
}

int answer2() {
	int x;
	vector<int> v;
	while (cin >> x) {
		v.push_back(x);
	}
	int i = 0;
	int ret = 0;
	vector<int> rets;
	while (1) {
		ret += v[i];
		for (int j = 0; j < rets.size(); ++j) {
			if (ret == rets[j]) {
				return ret;
			}
		}
		rets.push_back(ret);
		i = (i + 1) % v.size();
	}
	return 0;
}













//
