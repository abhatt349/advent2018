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


struct node
{
    long val;
    struct node *next;
    struct node *prev;
};



long answer1();
long answer2();
