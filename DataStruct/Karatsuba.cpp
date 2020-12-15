
#include "Karatsuba.h"
#include <iostream>




intArr& karatsuba(intArr& x, intArr& y){

	if (x.size() <= 1 && y.size() <= 1) {
		return mult(x[0], y[0]);
	}
	if (x.size() % 2 != 0 && x.size() > 1)
		x.addLeadZeros(1);
	if (y.size() % 2 != 0 && y.size() > 1)
		y.addLeadZeros(1);
	intArr ac, bd, sumx, sumy, abcd, acSumbd;
	intArr end;
	intArr start, middle;
	intArr a(&x[0],x.size()/2);
	intArr b(&x[x.size()/2], x.size() / 2);
	intArr c(&y[0],y.size()/2);
	intArr d(&y[y.size() / 2], y.size() / 2);
	 ac= karatsuba(a, c); 
	 bd= karatsuba(b, d); 
	if (Checksub(b,a)) {		
		 sumx=sub(b, a);
		if (Checksub(c, d)) {
			sumy= sub(c, d);
			abcd=karatsuba(sumx, sumy);
			acSumbd=adder(ac, bd);
		    middle=adder(abcd, acSumbd);
		}
		else {
			sumy = sub(d, c);
			abcd = karatsuba(sumx, sumy);
			acSumbd = adder(ac, bd);
			middle = sub(acSumbd, abcd);
		}
	}
	else {
		sumx = sub(a, b);
		if (Checksub(c, d)) {
			sumy = sub(c, d);
			abcd = karatsuba(sumx, sumy);
			acSumbd = adder(ac, bd);
			middle = sub(acSumbd, abcd);
		}
		else {
			sumy = sub(d, c);
			abcd = karatsuba(sumx, sumy);
			acSumbd = adder(ac, bd);
			middle = adder(abcd, acSumbd);
		}
	}

	ac.upByTen(x.size());
	middle.upByTen((x.size() / 2));
    start=adder(ac, middle);
	end=adder(start, bd);
	end.setOwner(false);
	return end;
}

bool Checksub(intArr& x, intArr& y) {
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

intArr& mult(int x, int y) {

	int mult = x * y;
	if (mult > 9) {
		intArr res(2);
		res[0] = mult / 10;
		res[1] = mult % 10;
		res.setOwner(false);
		return res;
	}
	else {
		intArr res(1);
		res[0] = mult;
		res.setOwner(false);
		return res;
	}
}

intArr& sub(intArr& x, intArr& y) {
	int sizex = x.size();
	int sizey = y.size();
	intArr res(sizex, 0);
	for (int i = 0; i < sizey; i++) {
		if (x[sizex - i - 1] < y[sizey - i - 1]) {
			x[sizex - i - 2]--;
			res[sizex - i - 1] = x[sizex - i - 1] - y[sizey - i - 1] + 10;
		}
		else {
			res[sizex - i - 1] = x[sizex - i - 1] - y[sizey - i - 1];
		}
	}
	for (int i = sizey; i < sizex; i++)
	{
		res[sizex - i - 1] = x[sizex - i - 1];

	}

	res.setOwner(false);
	return res;
}
intArr& adder(intArr& x, intArr& y) {
	if (x.size() > y.size())
	{
		return addTo(x, y);
	}
	else return addTo(y, x);

}
intArr& addTo(intArr& bigger, intArr& smaller)
{
	int bigSize = bigger.size();
	int smallSize = smaller.size();
	intArr res(bigSize + 1);
	for (int i = 0;i < smallSize;i++) {
		res[bigSize - i] += bigger[bigSize - 1 - i] + smaller[smallSize - 1 - i];
		if (res[bigSize - i] > 9) {
			res[bigSize - i - 1] += res[bigSize - i] / 10;
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
	res.setOwner(false);
	return res;

}



//void printArry(intArr res) {
//	for (int i = 0; i < res.size(); i++)
//		cout << res[i];
//	cout << endl;
//}
//void equalSize(intArr& x, intArr& y)
//{
//	if (x.size() == y.size()) return;
//	if (x.size() > y.size()) {
//		AddLeadZeros(y, x.size()- y.size());
//	}
//	else
//	{
//		AddLeadZeros(x, y.size()-x.size());
//	}
//}
//void removeLeadZeros(intArr& x) {
//	while (x.front()== 0 &&x.size()>1)
//	{
//		x.erase(x.begin());
//	}
//}


//intArrsplitVector(intArr& x) {
//	intArr res(x.size()/2);
//	int index = 0;
//	for (int i = x.size() / 2; i < x.size(); i++,index++) {
//		res[index]=x[i];
//	}
//	return res;
//}

