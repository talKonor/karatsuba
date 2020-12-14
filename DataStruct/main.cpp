#include "Genral.h"

int main() {
	string n;
	string number;
	vector<int> x, y,result;
	int size;
	cin >> n;
	if (!checkInput(n,DONT_CARE)){
		cout << "wrong output";
		return 0;
	}
	size = std::stoi(n);
	if (size == 0) {
		return 0;
	}   
	cin >> number;
	if (!checkInput(number,size)) {
		cout << "wrong output";
		return 0;
	}
	x=convertToInt(number);
	cin >> number;
	if (!checkInput(number,size)) {
		cout << "wrong output";
		return 0;
	}
	y=convertToInt(number);
	while ((x.size() & (x.size() - 1)) != 0) {
		AddLeadZeros(x, 1);
	}
	while ((y.size() & (y.size() - 1)) != 0) {
		AddLeadZeros(y, 1);
	}
	result = measureLongMult(x,y);
	removeLeadZeros(result);
	cout << "Long multiplication: x * y = ";
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i];
	}
	cout << endl;
	result = measureKaratsuba(x,y);
	removeLeadZeros(result);
	cout << "Karatsuba (recursive): x * y = ";
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i];
	}
	cout << endl;
	result = measureKaratsubaNotRec(x,y);
	removeLeadZeros(result);
	cout << "Karatsuba (iterative): x * y = ";
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i];
	}

	cout << endl;
} 



