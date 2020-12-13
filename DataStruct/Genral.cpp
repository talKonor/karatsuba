#include "Genral.h"

vector<int> convertToInt(string number) {
	int size = number.length();
	vector<int>res;
	for (int i = 0; i < size; i++) {
		//res.insert(res.begin(), number[i] - '0');
		res.push_back(number[i] - '0');
	}
	return res;

}

