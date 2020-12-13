#include"KaratsubaNotRec.h"
vector<int> KaratsubaNotRec(vector<int> x, vector<int> y) {
	Stack s;
	ItemType curr(x, y);
	vector<int> returnValue;
	bool returnFromRec = false;
	do {
		if (returnFromRec) {
			curr = s.pop();
		}
		if (curr.line == START) {
			if (curr.x.size() <= 1 || curr.y.size() <= 1) {
				returnValue = longMult(curr.x, curr.y);
				returnFromRec = true;
			}
			else {
				curr.line = AFTER_FIRST;
				s.push(curr);
			}
		}

	} while (!s.isEmpty());

}

