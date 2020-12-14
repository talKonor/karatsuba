
#include "Karatsuba.h"
#include <iostream>
vector<int> karatsuba(vector<int> x,vector<int> y){

	if (x.size() <= 4 || y.size() <= 4) {
		vector<int> res = longMult(x, y);
		return res;
	}
	if (x.size() % 2 != 0 && x.size()!=1)AddLeadZeros(x, 1);
	if (y.size() % 2 != 0 && y.size() != 1)AddLeadZeros(y, 1);
	vector<int> a(x);
	a.resize(a.size() / 2);
	vector<int> b = splitVector(x);
	vector<int> c(y);
	c.resize(c.size() / 2);
	vector<int> d= splitVector(y);
	vector<int> ac, bd, sumx, sumy, abcd,acSumbd;
	vector<int> first, middle, end;
	ac = karatsuba(a, c); //cout << "ac: "; printArry(ac); printArry(longMult(a, c));
	bd = karatsuba(b, d); // cout << "bd: "; printArry(bd); printArry(longMult(b, d));
	sumx = adder(a, b);
	removeLeadZeros(sumx);
	sumy = adder(c, d);
	removeLeadZeros(sumy);
	equalSize(sumx, sumy); //cout << "sumx size: " << sumx.size(); cout << ",sumy size: " << sumy.size();
	abcd = karatsuba(sumx, sumy); //cout << "sumx: "; printArry(sumx); cout << "sumy: "; printArry(sumy);  cout << "abcd: "; printArry(abcd); printArry(longMult(sumx, sumy));
	first = upbyTen(ac, x.size());
	acSumbd = adder(ac, bd);
	//removeLeadZeros(acSumbd);
	equalSize(abcd, acSumbd);
	middle = sub(abcd, acSumbd);
	//removeLeadZeros(middle);
	middle = upbyTen(middle, (x.size() / 2));
	middle = adder(first, middle);
	//removeLeadZeros(middle);
	end = adder(middle, bd);
	//removeLeadZeros(end);
 	return end;
}
//adder(adder(upbyTen(ac, 2), upbyTen(sub(sub(abcd, ac, 2), bd, 2 * 2), 2 / 2), 2), bd, 2);
/*int* test() {
	int ac[2] = { 0,8 };
	int bd[2] = { 4,5 };
	int abcd[4] = { 0,0,9,1 };
	int size = 2;
	int* firstPart = upbyTen(ac, 2, 2);
	printArry(firstPart, 4);
	int* acAddbd = adder(ac, bd, 2, 2);
	printArry(acAddbd, 3);
	int* abcd_Sub_ac_Add_bd = sub(abcd, acAddbd,4,3);
	printArry(abcd_Sub_ac_Add_bd, 4);
	int* midPart = upbyTen(abcd_Sub_ac_Add_bd, 4, 2/ 2);
	printArry(midPart, 5);
	int* partOne_Two = adder(firstPart, midPart, 4, 5);
	printArry(partOne_Two, 6);
	return adder(partOne_Two, bd, 6, 2);
	//return adder(upbyTen(ac, size, size), upbyTen(sub(sub(abcd, ac, size), bd, size), size, size), size, size);
} */

vector<int> upbyTen(vector<int> x,int power) {
	/*if (power % 2 != 0)
	{
		power = power + 1;
	}*/

	vector<int> res(x.size()+ power, 0);
	
	for (int i = 0; i < x.size(); i++)
	{
		res[i] = x[i];
	}
	return res;

}
vector<int> sub(vector<int> x, vector<int> y) {
	int sizex = x.size();
	int sizey = y.size();
	vector<int> res(sizex, 0);
	for (int i = 0; i<sizey; i++) {
		if (x[sizex - i-1] < y[sizey - i-1]) {
			x[sizex - i - 2]--;
			res[sizex-i-1] =x[sizex - i - 1] - y[sizey - i - 1] + 10;
		}
		else {
			res[sizex - i-1] =x[sizex - i - 1] - y[sizey - i - 1];
		}
	}
	for (int i = sizey; i < sizex; i++)
	{
		res[sizex - i-1] = x[sizex - i - 1];
		
	}
	
	//result.removeLeadZeros();
	return res;
}
vector<int> adder(vector<int> x, vector<int> y) {
	if (x.size() > y.size())
	{
		return addTo(x, y);
	}
	else return addTo(y, x);

}
vector<int> addTo(vector<int> bigger, vector<int> smaller)
{
	int bigSize = bigger.size();
	int smallSize = smaller.size();
	vector<int>res(bigSize + 1, 0);
	for(int i=0;i< smallSize;i++){
		res[bigSize - i] += bigger[bigSize-1 - i] + smaller[smallSize-1 - i];
		if (res[bigSize - i] > 9) {
			res[bigSize - i - 1]+= res[bigSize - i]/ 10;
			res[bigSize - i] %= 10;
		}
	}
	for (int i = smallSize; i < bigSize; i++) {
		res[bigSize - i] += bigger[bigSize - 1 - i];
		if (res[bigSize - i] > 9) {
			res[bigSize - i - 1] += res[bigSize - i] / 10;
			res[bigSize - i] %= 10;
		}
	}
	//result.removeLeadZeros();
	return res;

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
	vector<int> res;
	for (int i = x.size() / 2; i < x.size(); i++) {
		res.push_back(x[i]);
	}
	return res;
}

