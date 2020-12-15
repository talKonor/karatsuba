#pragma once
#include "RegularLong.h"
using namespace std;
void karatsuba(vector<int> x, vector<int> y, vector<int>& res);
//vector<int> karatsuba(vector<int> x, vector<int> y);
//vector<int> adder(vector<int> x, vector<int> y);
void adder(vector<int> x, vector<int> y, vector<int>& res);
//vector<int> addTo(vector<int> bigger, vector<int> smaller);
void addTo(vector<int> bigger, vector<int> smaller, vector<int>& res);
void upbyTen(vector<int>& x, int power);
void sub(vector<int> x, vector<int> y, vector<int>& res);
void equalSize(vector<int>& x, vector<int>& y);
void removeLeadZeros(vector<int>& x);
void AddLeadZeros(vector<int>& x, int size);
vector<int>splitVector(vector<int>& x);
void printArry(vector<int> res);
bool Checksub(vector<int> x, vector<int> y);