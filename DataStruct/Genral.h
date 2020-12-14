#pragma once
#include <string>
#include <iostream>
#include"Karatsuba.h"
#include "RegularLong.h"
#include "KaratsubaNotRec.h"
#define DONT_CARE -1
using namespace std;
vector<int> convertToInt(string number);
bool checkInput(string num, int numSize);

vector<int> measureLongMult(vector<int>x, vector<int>y);
vector<int> measureKaratsuba(vector<int>x, vector<int>y);
vector<int> measureKaratsubaNotRec(vector<int>x, vector<int>y);