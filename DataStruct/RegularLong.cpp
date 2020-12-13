#include "RegularLong.h"
vector<int> longMult(vector<int> x, vector<int> y)
{
	if (x.size() >= y.size())
	{
		return SchoolMult(x, y);
	}
	return SchoolMult(y, x);
}
vector<int> SchoolMult(vector<int> x, vector<int> y) {
	int size= 2*x.size();
	int index = size;
	vector<int> res (size,0);
	int carry = 0, mult;
	int  intenalIndex;

	for (int i = y.size()-1;i>=0;i--)
	{
	  for(int j=x.size()-1;j>=0;j--)
	  {
		  intenalIndex = index - (size/2 - j);
		  mult = carry + x[j] * y[i];
		  res[index-(size/2-j)] += mult;
		  if (res[index - (size/2 - j)] > 9){
			  carry = res[index - (size/2 - j)] / 10;
			  res[index - (size/2 - j)] %= 10;
		  }
		  else carry = mult / 10;
		 
	  }
	  res[intenalIndex - 1] = carry;
	  carry = 0;
	  index--;
	}
	
	return res;


}