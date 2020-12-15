
#include "Karatsuba.h"
#include <iostream>
void karatsuba(vector<int> x,vector<int> y,vector<int>&res){

	if (x.size() <= 1 || y.size() <= 1) {
		res = longMult(x, y);
		return;
	}
	if (x.size() % 2 != 0 && x.size() > 1)
		AddLeadZeros(x, 1);
	if (y.size() % 2 != 0 && y.size() > 1)
		AddLeadZeros(y, 1);
	vector<int> ac, bd, sumx, sumy, abcd, acSumbd;
	vector<int> first, middle, mid;
	vector<int> a(x);
	a.resize(a.size() / 2);
	vector<int> b = splitVector(x);
	//x.resize(x.size() / 2);
	vector<int> c(y);
	c.resize(c.size() / 2);
	vector<int> d= splitVector(y);
	//y.resize(y.size() / 2);
	 karatsuba(a, c,ac); //cout << "ac: "; printArry(ac); printArry(longMult(a, c));
	 karatsuba(b, d, bd); // cout << "bd: "; printArry(bd); printArry(longMult(b, d));
	if (Checksub(b,a)) {		
		 sub(b, a, sumx);
		if (Checksub(c, d)) {
			sub(c, d,sumy);
			karatsuba(sumx, sumy, abcd);
			adder(ac, bd, acSumbd);
		    adder(abcd, acSumbd, middle);
		}
		else {
			 sub(d, c, sumy);
			 karatsuba(sumx, sumy,abcd);
			 adder(ac, bd, acSumbd);
			 //equalSize(abcd, acSumbd);
			 sub(acSumbd, abcd, middle);
		}
	}
	else {
		  sub(a, b, sumx);
		if (Checksub(c, d)) {
			sub(c, d, sumy);
		    karatsuba(sumx, sumy, abcd);
			adder(ac, bd, acSumbd);
			//equalSize(abcd, acSumbd);
			sub(acSumbd, abcd, middle);
		}
		else {
		    sub(d, c,sumy);
			karatsuba(sumx, sumy, abcd);
			adder(ac, bd, acSumbd);
			adder(abcd, acSumbd, middle);
		}
	}
	//sumx = (a, b);
	//sumy = adder(c, d);
	//equalSize(sumx, sumy); //cout << "sumx size: " << sumx.size(); cout << ",sumy size: " << sumy.size();
	//abcd = karatsuba(sumx, sumy); //cout << "sumx: "; printArry(sumx); cout << "sumy: "; printArry(sumy);  cout << "abcd: "; printArry(abcd); printArry(longMult(sumx, sumy));
	//acSumbd = sub(ac, bd);
	upbyTen(ac, x.size());
	//equalSize(abcd, acSumbd);
	//middle = sub(abcd, acSumbd);
	removeLeadZeros(ac);
	removeLeadZeros(middle);
	upbyTen(middle, (x.size() / 2));
    adder(ac, middle, mid);
	adder(mid, bd, res);
	removeLeadZeros(res);

}


void upbyTen(vector<int>& x,int power) {

	x.resize(x.size() + power, 0);
}
bool Checksub(vector<int> x, vector<int> y) {
	int i = 0;
	
	while (i < x.size()) {
		if (x[i] > y[i])
			return true;
		else if (x[i] < y[i])
			return false;
		i++;
	}
	return true;
}
void sub(vector<int> x, vector<int> y,vector<int>& res) {
	int sizex = x.size();
	int sizey = y.size();
	
	//vector<int> res(sizex, 0);
	for (int i = 0; i < sizey; i++) {
		if (x[sizex - i - 1] < y[sizey - i - 1]) {
			x[sizex - i - 2]--;
			res.insert(res.begin(),x[sizex - i - 1] - y[sizey - i - 1] + 10);
		}
		else {
			res.insert(res.begin(), x[sizex - i - 1] - y[sizey - i - 1]);
		}
	}
}
void adder(vector<int> x, vector<int> y,vector<int>&res) {
	if (x.size() >= y.size())
	{
	 addTo(x, y,res);
	 return;
	}
	 addTo(y, x,res);
	 return;

}
void addTo(vector<int> bigger, vector<int> smaller, vector<int>& res)
{
	int bigSize = bigger.size();
	int smallSize = smaller.size();
	int carry=0,sum;
	//AddLeadZeros(bigger, 1);
	for (int i = 0; i < smallSize; i++) {
		sum = bigger[bigSize - 1 - i] + smaller[smallSize - 1 - i] + carry;
		if (sum > 9) {
			res.insert(res.begin(), sum % 10);
			carry = sum / 10;
		}
		else {
			res.insert(res.begin(), sum);
			carry = 0;
		}

	}
	for (int i = smallSize; i < bigSize; i++) {
		sum= bigger[bigSize - 1 - i]+carry;
		if (sum > 9) {
			res.insert(res.begin(), sum % 10);
			carry = sum / 10;
		}
		else {
			res.insert(res.begin(), sum);
			carry = 0;
		}
	}
	if(carry!=0)  res.insert(res.begin(), carry);
}



void printArry(vector<int> res) {
	for (int i = 0; i < res.size(); i++)
		cout << res[i];
	cout << endl;
}
void equalSize(vector<int>& x, vector<int>& y)
{
	if (x.size() == y.size()) return;
	if (x.size() > y.size()) {
		AddLeadZeros(y, x.size()- y.size());
	}
	else
	{
		AddLeadZeros(x, y.size()-x.size());
	}
}
void removeLeadZeros(vector<int>& x) {
	while (x.front()== 0 &&x.size()>1)
	{
		x.erase(x.begin());
	}
}
void AddLeadZeros(vector<int>& x,int size) {

	for(int i=0;i<size;i++){
		x.insert(x.begin(), 0);
	 }
}

vector<int>splitVector(vector<int>& x) {
	vector<int> res(x.size()/2);
	int index = 0;
	for (int i = x.size() / 2; i < x.size(); i++,index++) {
		res[index]=x[i];
	}
	return res;
}

