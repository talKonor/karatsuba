#pragma once
#include <string>
#include <iostream>
#include"Karatsuba.h"
#include "RegularLong.h"
#include "KaratsubaNotRec.h"
#define DONT_CARE -1
using namespace std;
//intArr convertToInt(string number);
bool checkInput(string num, int numSize);

intArr measureLongMult(intArr& x, intArr& y);
intArr measureKaratsuba(intArr& x, intArr& y);
intArr measureKaratsubaNotRec(intArr& x, intArr& y);