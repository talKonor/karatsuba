
#include "Karatsuba.h"
#include <iostream>




intArr karatsuba(intArr& x, intArr& y){
	//static int counter = 0;
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
	ac = karatsuba(a, c);//cout << "ac: " << ac;//intArr ac2 = longMult(a, c);cout << "|| ac long: " << ac2 << endl;
	bd = karatsuba(b, d);//cout << "bd: " << bd;//intArr bd2 = longMult(b, d);cout << "|| bd long: " << bd2 << endl;
	//if (counter == 4691)
	//	counter++;
	if (Checksub(b,a)) {		
		 sumx=sub(b, a);
		if (Checksub(c, d)) {
			sumy= sub(c, d);
			abcd = karatsuba(sumx, sumy);//;cout << "abcd: " << abcd;intArr abcd2 = longMult(sumx, sumy);cout << "|| abcd long: " << bd2 << endl;
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
	//cout << sumx<<"|"<<sumy<<"|  abcd: " << abcd;intArr abcd2 = longMult(sumx, sumy);cout << "|| abcd long: " << abcd2 << endl;
	ac.upByTen(x.size());// cout << "acUP: " << ac <<"next is mid: "<<middle<<"x.size()="<<x.size()<<endl;
	//counter++;cout << "counter=" << counter << endl;
	middle.upByTen(((x.size()+1) / 2));//cout << "midUP: " << middle << endl;
    start=adder(ac, middle);//cout << "start: " << start << endl;
	end=adder(start, bd);//cout << "end: " << end << endl;
	end.setOwner(false);
	//cout << "ac: " << ac << " middle: " << middle << " bd: " << bd << endl;
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

intArr mult(int x, int y) {

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

intArr sub(intArr& x, intArr& y) {// the problem of middle crashing is here: y.size>x.size even if x>y... so you wirte to memroy you dont own
	int sizex = x.size();
	int sizey = y.size();
	int max = std::max(sizex, sizey);
	int min = std::min(sizex, sizey);
	int carry = 0;
	intArr res(max);
	for (int i = 0; i < min; i++) {
		res[max - i - 1] = res[max - i - 1]+ x[sizex - i - 1] - y[sizey - i - 1];
		/*
		if (res[sizex - i - 1] < 0) {
			res[sizex - i - 1] += 10;
			res[sizex - i - 2]--;
		}*/
	}
	for (int i = min; i < max; i++)
	{
		if(sizex==max)
			res[max - i - 1] += x[sizex - i - 1];
		/*if (res[sizex - i - 1] < 0) {
			res[sizex - i - 1] += 10;
			res[sizex - i - 2]--;*/
		}
	/*if (sizex != sizey)
		res[0] += x[0];
	else
		res[0] = res[0] + (x[0] - y[0]);
		*/
	for (int i = 0; i < max-1; i++)
	{
		if (res[max - i - 1] < 0) {
			res[max - i - 1] += 10;
			res[max - i - 2]--;
		}
	}
	for (int i = 0; i < max - 1; i++)
	{
		if (res[i] < 0) {
			i++;
		}
	}
	//if (sizex != sizey)
		//res[0] += x[0];
	res.setOwner(false);
	return res;
}


intArr sub1(intArr& x, intArr& y) { //-> ONLY WORKS if array is same size and x>y
	int sizex = x.size();
	int sizey = y.size();
	int carry = 0;
	intArr res(sizex);
	for (int i = 0; i < sizey; i++) {
		if (x[i] < y[i]) {
			res[i - 1]--;
			res[i] = x[i] - y[i] + 10;
		}
		else {
			res[i] = x[i] - y[i];
		}
	}
	for (int i = sizey; i < sizex; i++)
	{
		res[i] = x[i];

	}

	res.setOwner(false);
	return res;
}
intArr adder(intArr& x, intArr& y) {
	if (x.size() > y.size())
	{
		return addTo(x, y);
	}
	else return addTo(y, x);

}
intArr addTo(intArr& bigger, intArr& smaller)
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

