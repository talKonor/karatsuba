#include "Genral.h"

int* doCarry(int* arr, int size);
int main() {
	int n;
	string number;
	vector<int> x, y,result;
	cout << "Please enter digit number: ";
	cin >> n;
	cout << "Please enter the number: ";   
	cin >> number;
	x=convertToInt(number);
	cout << "Please enter the number: ";
	cin >> number;
	y=convertToInt(number);
	result = longMult(x, y);
	cout << endl;
    if (x.size() % 2 != 0 && x.size()!=1)AddLeadZeros(x, 1);
	if (y.size() % 2 != 0 && y.size() != 1)AddLeadZeros(y, 1);
	result = karatsuba(x, y);
	vector<int>res = longMult(x, y);
	removeLeadZeros(result);
	removeLeadZeros(res);
	cout << "Long multiplication: x * y = ";
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i];
	}
	cout << endl;
	cout << "Karatsuba (recursive): x * y = ";
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i];
	}
} 
	//equalSize(test1, test2);

	//result = doCarry(result, 2 * n);
	//result = test();
	//result.printArry(2 * n);*/
	  
	/*vector<int> test2{ 1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9,1,2,3 };
	vector<int> test1{ 1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9,1,2,3 };
	equalSize(test1, test2);
	vector<int>res=karatsuba(test1,test2);
	cout << endl;
	vector<int>res2 = longMult(test1, test2);
 */
	

//}

