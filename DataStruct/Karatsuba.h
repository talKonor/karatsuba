#pragma once
#include "RegularLong.h"
using namespace std;
vector<int> karatsuba(vector<int> x, vector<int> y);
vector<int> adder(vector<int> x, vector<int> y);
vector<int> addTo(vector<int> bigger, vector<int> smaller);
vector<int> upbyTen(vector<int> x, int power);
vector<int> sub(vector<int> x, vector<int> y);
void equalSize(vector<int>& x, vector<int>& y);
void removeLeadZeros(vector<int>& x);
void AddLeadZeros(vector<int>& x, int size);
vector<int>splitVector(vector<int>& x);
void printArry(vector<int> res);