#include "Genral.h"
//
//int main1() {
//	string n;
//	string number;
//	vector<int> x, y;
//	int size;
//	vector<int>a = { 5,5 };
//	vector<int>b = { 4,8 };
//	vector<int>res;
//	
//	cin >> n;
//
//	if (!checkInput(n,DONT_CARE)){
//		cout << "wrong output";
//		return 0;
//	}
//	size = std::stoi(n);
//	if (size == 0) {
//		return 0;
//	}   
//	cin >> number;
//	if (!checkInput(number,size)) {
//		cout << "wrong output";
//		return 0;
//	}
//	x.convertToInt(number);
//	cin >> number;
//	if (!checkInput(number,size)) {
//		cout << "wrong output";
//		return 0;
//	}
//	y.convertToInt(number);
//	/*while ((x.size() & (x.size() - 1) )!= 0) {
//		AddLeadZeros(x, 1);
//
//	  }
//   while ((y.size() & (y.size() - 1)) != 0) {
//		AddLeadZeros(y, 1);
//	} */
//   vector<int>result1, result2, result3;
//   result1 = measureLongMult(x,y);
//	removeLeadZeros(result1);
//	cout << "Long multiplication: x * y = ";
//	for (int i = 0; i < result1.size(); i++)
//	{
//		cout << result1[i];
//	}
//	cout << endl;
//	result2=measureKaratsuba(x,y);
//	removeLeadZeros(result2);
//	cout << "Karatsuba (recursive): x * y = ";
//	for (int i = 0; i < result2.size(); i++)
//	{
//		cout << result2[i];
//	}
//	cout << endl;
//	/*result = measureKaratsubaNotRec(x,y);
//	removeLeadZeros(result);
//	cout << "Karatsuba (iterative): x * y = ";
//	for (int i = 0; i < result.size(); i++)
//	{
//		cout << result[i];
//	}  */
//
//	cout << endl;
//} 

int main() {
	string n;
	string number;
	int size;

	cin >> n;

	if (!checkInput(n, DONT_CARE)) {
		cout << "wrong output";
		return 0;
	}
	size = std::stoi(n);
	if (size == 0) {
		return 0;
	}
	cin >> number;
	if (!checkInput(number, size)) {
		cout << "wrong output";
		return 0;
	}
	intArr x(size);
		x.convertToInt(number);
	cin >> number;
	if (!checkInput(number, size)) {
		cout << "wrong output";
		return 0;
	}
	intArr y(size);
	y.convertToInt(number);
	//intArr x(10);
	//intArr y(6);
	//x.junk(3);
	//y.junk(3);
	//cout << "x: " << x << " y: " << y << endl;
	int i = 0;
	cout <<endl;

	cout << "LongMult: "<<endl;
	intArr result = measureLongMult(x, y);
	cout << result << endl;

	cout << "KARTABUSHA: "<<endl;
	intArr result1 = measureKaratsuba(x, y);
	cout << result1 << endl;

	cout << "KARTABUSHA: " << endl;
	intArr result2 = measureKaratsubaNotRec(x, y);
	cout << result2 << endl;


	//	cout << result[i];
	//}
	//intArr result1 = measureLongMult(x, y);
	//removeLeadZeros(result1);
	//cout << "Long multiplication: x * y = ";
	//for (int i = 0; i < result1.size(); i++)
	//{
	//	cout << result1[i];
	//}
	//cout << endl;
	//intArr result2 = measureKaratsuba(x, y);
	//removeLeadZeros(result2);
	//cout << "Karatsuba (recursive): x * y = ";
	//for (int i = 0; i < result2.size(); i++)
	//{
	//	cout << result2[i];
	//}
	//cout << endl;
	//intArr result = measureKaratsubaNotRec(x,y);
	//removeLeadZeros(result);
	//cout << "Karatsuba (iterative): x * y = ";
	//for (int i = 0; i < result.size(); i++)
	//{
	//	cout << result[i];
	//}  

	cout << endl;
}


/*while ((x.size() & (x.size() - 1) )!= 0) {
	x.addLeadZeros(1);

  }
while ((y.size() & (y.size() - 1)) != 0) {
	 y.addLeadZeros(1);
 } */