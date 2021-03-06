#pragma once

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
#include <cmath>
#include <vector>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

int answer1();
int answer2();
void reduce(vector<int> &v, int &total, int pos);
int len(vector<int> v, int pos);
void reduce(vector<int> &v, int &total, int pos, int end);
