#pragma once
#include <string>
#include <iostream>
using namespace std;
class intArr
{
public:
	intArr(int size, bool doinit=true,int init = 0);
	intArr(const intArr& origin);
	intArr();
	intArr(int* slice,int slice_size);
	void split(int* slice, int slice_size);
	~intArr();

	void junk(int size);

	int size();
	int leadingZeros();
	void setlogSize(int new_size);
	void convertToInt(string number);
	void upByTen(int power);
	void addLeadZeros(int zeroes);
	void setOwner(bool set);
	intArr& operator=(const intArr& int_arr);
	int& operator[](int i);
	friend ostream& operator<<(ostream& os, const intArr& arr);

private:
	bool owner;
	int* arr;
	int log_size;
	int real_size;
};

