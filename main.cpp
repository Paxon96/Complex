#include<iostream>
#include<math.h>
#include <stdlib.h>
#include "complex.h"

using namespace std;

int main()
{
	Complex c1(5,2), c2(3,-2);
	Complex c3(3.0,5.90), c4(1,1);
	
	Complex c5;
	c5 = 2 * c1;
	cout << c5<< endl;
	//cout<< amplituda(c3) << endl << faza(c3) << endl;
	//cout << c4 << endl << czRzecz(c2) << "\t" << czUro(c2) << endl;
	
	//cout<< amplituda(c3) << endl;
	c5 = c2 * c1;
	cout << c5<< endl;
	
	c5 = c3 + c4;
	cout << c5<< endl;
return 0;
}
