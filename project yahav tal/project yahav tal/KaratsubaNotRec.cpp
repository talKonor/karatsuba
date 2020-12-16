#include"KaratsubaNotRec.h"
vector<int> KaratsubaNotRec(vector<int> x, vector<int> y) {
	return x;
}
	/*Stack s;
	ItemType curr(x, y);
	vector<int> returnValue;
	vector<int> sumx, sumy;
	bool returnFromRec = false;
	do {
		if (returnFromRec) {
			curr = s.pop();
		}
		if (curr.line == START) {
			if (curr.x.size() <= 4 || curr.y.size() <= 4) {
				returnValue = longMult(curr.x, curr.y);
				returnFromRec = true;
			}
			else {
				if (curr.x.size() % 2 != 0 && curr.x.size() != 1)AddLeadZeros(curr.x, 1);
				if (curr.y.size() % 2 != 0 && curr.y.size() != 1)AddLeadZeros(curr.y, 1);
				curr.line = AFTER_FIRST;
				s.push(curr);
				curr.x.resize(curr.x.size() / 2);
				curr.y.resize(curr.y.size() / 2);
				curr.line = START;
				returnFromRec = false;
			}
		}
		else if (curr.line == AFTER_FIRST) {
			curr.ac = returnValue;
			curr.line = AFTER_SECOND;
			s.push(curr);
			curr.x = splitVector(curr.x);
			curr.y = splitVector(curr.y);
			curr.line = START;
			returnFromRec = false;
		}
		else if (curr.line == AFTER_SECOND) {
			curr.bd = returnValue;
			curr.line = AFTER_THIRD;
			s.push(curr);
			vector<int>b = splitVector(curr.x);
			vector<int>d= splitVector(curr.y);
			curr.x.resize(curr.x.size() / 2);
			curr.y.resize(curr.y.size() / 2);
			sumx = adder(curr.x, b);
			sumy = adder(curr.y, d);
			removeLeadZeros(sumx);
			removeLeadZeros(sumy);
			equalSize(sumx, sumy);
			curr.x = sumx;
			curr.y = sumy;
			curr.line = START;
			returnFromRec = false;
		}
		else if (curr.line == AFTER_THIRD) {
			curr.abcd = returnValue;
			returnFromRec = true;
			vector<int>first, mid,acSumbd,end;
			acSumbd = adder(curr.ac, curr.bd);
			 upbyTen(curr.ac, curr.x.size());
			removeLeadZeros(acSumbd);
			equalSize(curr.abcd, acSumbd);
			mid = sub(curr.abcd, acSumbd);
			removeLeadZeros(mid);
			 upbyTen(mid, (curr.x.size() / 2));
			mid = adder(curr.ac, mid);
			removeLeadZeros(mid);
			end = adder(mid, curr.bd);
			removeLeadZeros(end);
			returnValue = end;
			curr.out = end;
			}
	} while (!s.isEmpty());
	return returnValue;
}
		 */
