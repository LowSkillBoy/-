#include "Key.h"
int NOD(int a)
{
	int c,b;
	b = rand() % 10;
	while (b==1) {
		b= rand() % 10;
		c = a % b;
		a = b;
		b = c;
	}
	return b;
}
Key::Key() {
	n = p * q;
	f = (p - 1)*(q - 1);
}

int Key::OpenKey() {
	int i = 2;
		do{

		e = NOD(f);

		if (e%i == 0 && e < f) {
			if (e % 2 == 0) { e++; }
			break;

		}
		i++;
	}while (i <= (sqrt(abs(e))));
	
	return e;
}
int Key::CloseKey(int e) {
	int  arr[] = { 1,2,3,4,5,6,7,8,9 };
	
	for(int j=0;j<9;j++){
		d = (3*f + 1) /e;
		if (d%arr[j] == 0 ) {
			I=arr[j];
			break;

		}
	}
	
	return d;
}
int Key::Res(){
Result = (I*f + 1) / d;

return Result;
}
int Key::getn() { return n; }
int  Key::gete() { return e; }
int Key::getd() { return d; }
int Key::getResult() { return Result; }