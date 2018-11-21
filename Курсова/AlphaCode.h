#pragma once
#include"Key.h"
#include <map>
#include<list>
#include<string>

class AlphaCode
{
private:
	map<char, int > Text;
	map<int, char > BackText;
	int id = 0;
	string ReturnCode;
	string ReturnText;
	vector<int>decode;
public:
	AlphaCode();
	string Encrypt(string);
	string Decrypt(string);
};

