#include"KaratsubaNotRec.h"
intArr KaratsubaNotRec(intArr& x, intArr& y) {
	Stack s;
	Item curr(x, y);
	intArr returnValue;
	intArr sumx, sumy;
	intArr new_y;
	intArr new_x;
	int counter = 0;
	bool returnFromRec = false;
	do {
		if (returnFromRec) {
			curr = s.pop();
		}
		if (curr.line == START) {
				int ac_zeroes = zeroesToRemove(curr.x, curr.y);
				new_x.split(&curr.x[ac_zeroes], curr.x.size() - ac_zeroes);
				new_y.split(&curr.y[ac_zeroes], curr.y.size() - ac_zeroes);
			if (new_x.size() <= 1 && new_y.size() <= 1) {
				
				returnValue = mult(new_x[0], new_y[0]);
			//	cout << curr.x << "*" << curr.y << "=" <<returnValue<< endl;
				returnFromRec = true;
			if (curr.x.leadingZeros() == curr.x.size() || curr.y.leadingZeros() == curr.y.size())
				returnValue = mult(0, 0);
			}
			else {
				curr.line = AFTER_FIRST;
				curr.freeOwnership(); 
				if (new_x.size() % 2 != 0 && new_x.size() > 1){
					if (ac_zeroes == 0) {
						new_x.addLeadZeros(1);
						new_y.addLeadZeros(1);
					}
				}
				curr.new_size = new_x.size();
			    curr.a.split(&new_x[0], new_x.size() / 2);
				curr.b.split(&new_x[new_x.size() / 2], new_x.size() / 2);
				curr.c.split(&new_y[0], new_y.size() / 2);
				curr.d.split(&new_y[new_y.size() / 2], new_y.size() / 2);
				s.push(curr);
				
				curr.x=curr.a;
				curr.y=curr.c;
				//curr.x.split(&new_x[0], new_x.size() / 2);
				//curr.y.split(&new_y[0], new_y.size() / 2);
				curr.line = START;
				returnFromRec = false;
			}
		}
		else if (curr.line == AFTER_FIRST) {
			
			curr.ac = returnValue;
			//cout << "ac: " << curr.ac << endl;
			curr.line = AFTER_SECOND;
			curr.freeOwnership();
			s.push(curr);
			curr.x=curr.b;
			curr.y=curr.d;
			//curr.x.split(&curr.x[curr.x.size()/2], curr.x.size()/2);
			//curr.y.split(&curr.y[curr.y.size()/2], curr.y.size()/2);
			curr.line = START;
			returnFromRec = false;
		}
		else if (curr.line == AFTER_SECOND) {

			curr.bd = returnValue;
			//cout << "bd: " << curr.bd << endl;

//			cout << " a: " << a << " b: " << b << " c: " << c << " d: " << d  <<endl;
			if (Checksub(curr.b, curr.a)) {
				sumx = sub(curr.b, curr.a);
				if (Checksub(curr.c, curr.d)) {
					sumy = sub(curr.c, curr.d);
					curr.line = AFTER_THIRD1;
				}
				else {
					sumy = sub(curr.d, curr.c);
					curr.line = AFTER_THIRD2;
				}
			}
			else {
				sumx = sub(curr.a, curr.b);
				if (Checksub(curr.c, curr.d)) {
					sumy = sub(curr.c, curr.d);
					curr.line = AFTER_THIRD2;
				}
				else {
					sumy = sub(curr.d, curr.c);
					curr.line = AFTER_THIRD1;
				}
			}

			curr.freeOwnership();
			s.push(curr);
			curr.x = sumx;
			curr.y = sumy;
			curr.line = START;
			returnFromRec = false;
		}
		else {
			intArr first, mid, acSumbd, end;
			returnFromRec = true;
			/*int ac_zeroes = zeroesToRemove(curr.x, curr.y);
			new_x.split(&curr.x[ac_zeroes], curr.x.size() - ac_zeroes);
			new_y.split(&curr.y[ac_zeroes], curr.y.size() - ac_zeroes);
			if (new_x.size() % 2 != 0 && new_x.size() > 1) {
				if (ac_zeroes == 0) {
					new_x.addLeadZeros(1);
					new_y.addLeadZeros(1);
				}
			}*/
			curr.abcd = returnValue;
		//	cout << "abcd: " << curr.abcd << endl;
			if (curr.line == AFTER_THIRD1) {
				acSumbd = adder(curr.ac, curr.bd);
				mid = adder(curr.abcd, acSumbd);
			}
			if (curr.line == AFTER_THIRD2) {
				acSumbd = adder(curr.ac, curr.bd);
				mid = sub(acSumbd, curr.abcd);
			}
			//-----//
			if (counter == 4083)
				int i = 0;
			curr.ac.upByTen(curr.new_size);
			mid.upByTen((curr.new_size + 1) / 2);
			mid = adder(curr.ac, mid);
			end = adder(mid, curr.bd);
			end.setOwner(false);
			returnValue = end;
			returnValue.setOwner(false);
			curr.out = end;
			//cout<<"ac: "<<curr.ac<<"|| bc: "<<curr.bd << "|| abcd: " << curr.abcd << endl;
			counter++;
			//cout << counter << endl;
			curr.freeOwnership();
			}
	} while (!s.isEmpty());
	return returnValue;
}
		 
