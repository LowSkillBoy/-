#pragma once
#include"Key.h"
#include <map>
#include<list>
#include<string>

class RSA2_0
{
private:
	int id = 0;
	int C;
	vector<int> decode;
	map<char, int > Table;
	map<int, char > BackTable;
	string ReturnCode;
	string ReturnText;
	vector<int> safe;
	int T;
	Key k;
public:
	RSA2_0();
	string Encrypt(string);
	string Decrypt(string);
};

