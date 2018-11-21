#include <iostream>
#include <list> 
#include "windows.h"
#include <locale>
#include <cmath> 
#include <windows.h>
#include <conio.h>
#include <stdlib.h> 
#include <stdio.h>
#include "Key.h"
#include"RSA.h"
#include "AlphaCode.h"
#include "RSA2.0.h"

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string text,code;
	/*
	RSA R;
	cout << "Введіть текст який потрібно зашифрувати: " << endl;
	getline(cin, text);
	R.encrypt(text);
	cout << endl;
	getline(cin, text);
	R.decrypt(text);
	
	AlphaCode A;
	cout << "Введіть текст який потрібно зашифрувати: " << endl;
	getline(cin, text);
	A.Encrypt(text);
	cout << endl;
	getline(cin, code);
	A.Decrypt(code);*/
	RSA2_0 RS;
	cout << "Введіть текст який потрібно зашифрувати: " << endl;
	getline(cin, text);
	RS.Encrypt(text);
	cout << endl;
	getline(cin, code);
	RS.Decrypt(code);
	_getch();
	return 0;
}
