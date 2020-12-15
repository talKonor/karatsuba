#include "Genral.h"
#include<chrono>
#include <ostream>
#include <iomanip>
#include<fstream>
vector<int> convertToInt(string number) {
	int size = number.length();
	vector<int>res;
	for (int i = 0; i < size; i++) {
		//res.insert(res.begin(), number[i] - '0');
		res.push_back(number[i] - '0');
	}
	return res;
}

bool checkInput(string num,int numSize) {
	int size = num.length();
	if(size!=numSize&& numSize!=DONT_CARE)	return false;
	if (num[0] == '0'&&size!=1 && numSize==DONT_CARE)return false;
	for (int i = 0; i < size; i++) {
		if (!(num[i] >= '0' && num[i] <= '9'))
			return false;
	}
	return true;
}

vector<int> measureLongMult(vector<int> x, vector<int> y)
{
	vector<int>res;	auto start = chrono::high_resolution_clock::now();
	// unsync the I/O of C and C++.
	ios_base::sync_with_stdio(false);
	res = longMult(x, y);// Here you put the name of the function you wish to measure
	auto end = chrono::high_resolution_clock::now();
	// Calculating total time taken by the program.
	double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	ofstream myfile("measure.txt"); // The name of the file
	myfile << "Time taken by function LongMult is : " << fixed
		<< time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();

	return res;

}

vector<int> measureKaratsuba(vector<int> x, vector<int> y, vector<int>& res)
{

	auto start = chrono::high_resolution_clock::now();
	// unsync the I/O of C and C++.
	ios_base::sync_with_stdio(false);
	 karatsuba(x, y,res);// Here you put the name of the function you wish to measure
	auto end = chrono::high_resolution_clock::now();
	// Calculating total time taken by the program.
	double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	ofstream myfile("measure.txt", ios::app); // The name of the file
	myfile << "Time taken by function Karatsuba is : " << fixed
		<< time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();

	return res;
}

vector<int> measureKaratsubaNotRec(vector<int> x, vector<int> y)
{
	vector<int>res;	auto start = chrono::high_resolution_clock::now();
	// unsync the I/O of C and C++.
	ios_base::sync_with_stdio(false);
	res = KaratsubaNotRec(x, y);// Here you put the name of the function you wish to measure
	auto end = chrono::high_resolution_clock::now();
	// Calculating total time taken by the program.
	double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	ofstream myfile("measure.txt", ios::app); // The name of the file
	myfile << "Time taken by function KaratsubaNotRec is : " << fixed
		<< time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();

	return res;
}



