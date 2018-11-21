#pragma once
#include"Key.h"
#include <map>
#include<list>
#include<string>
class RSA : public Key
{
private:
	int id = 0;
	long int C;
	vector<int> code;
	vector<int>decode;
	map<char,int > Table;
	map<int, char > BackTable;
	string ReturnCode;
	list<string> NewText;
	string Text;
	vector<int> safe;
	int T;
	Key K;
	vector<int> Dcode;
public:
	RSA();
	string encrypt(string );
	string decrypt(string);
};
