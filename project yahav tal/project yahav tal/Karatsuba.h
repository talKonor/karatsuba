#pragma once
#include "RegularLong.h"
#include "intArr.h"
using namespace std;
intArr karatsuba(intArr& x, intArr& y);
//intArr karatsuba(intArr x, intArr y);
//intArr adder(intArr x, intArr y);
intArr adder(intArr& x, intArr& y);
//intArr addTo(intArr bigger, intArr smaller);
intArr addTo(intArr& bigger, intArr& smaller);
void upbyTen(intArr& x, int power);
intArr sub(intArr& x, intArr& y);
void equalSize(intArr& x, intArr& y);
void removeLeadZeros(intArr& x);
void intArrsplitVector(intArr& x);
void printArry(intArr res);
bool Checksub(intArr& x, intArr& y);
intArr mult(int x, int y);