#include "RSA.h"

int Pow(int a, int b) {
	long long answer = a;
	for (int i = 1; i <= b; i++)
		answer = a * a;
	return answer;
}
RSA::RSA()
{
	char trans;
	for (int i = 65; i <= 90; i++) {
		id++;
		trans = (char)i;
		Table.emplace(trans, id);
		BackTable.emplace(id, trans);
	}
	for (int i = 97; i <= 122; i++) {
		id++;
		trans = (char)i;
		Table.emplace(trans, id);
		BackTable.emplace(id, trans);
	}
	id++;
	Table.emplace(' ', id);
	BackTable.emplace(id, ' ');
}
string RSA::encrypt(string text) {
	Key k;
	string Cstr, Dstr;
	
	char tmp;
	k.OpenKey();
	safe.push_back(k.gete());
	for (int i = 0; i < text.length(); i++) {
		tmp = text[i];

		T = Table[tmp];

		C = (Pow(T, k.gete())) % k.getn();
		
		Cstr+=to_string(C);
		Cstr += '.';
		Dstr+= to_string(T);
		Dstr += '.';
		

	}
	ReturnCode+=Cstr;
	ReturnCode += '|';
	ReturnCode += Dstr;
	cout << ReturnCode;
	return ReturnCode;
}
string RSA::decrypt(string text) {
	Key k;
	int s;
	string tmp;
	int R;
	k.OpenKey();
	k.CloseKey(k.gete());
	k.Res();
	
	
	auto ptr = text.c_str();
	char *endptr = nullptr;
	char closeptr = '|';

	while (*ptr != closeptr) {
		auto value = strtol(ptr, &endptr, 10);
		if (ptr == endptr) {
			ptr++;
		}
		else {
			ptr = endptr;
			code.push_back(value);
		}
		}

	
		for (int i = 0; i < text.length(); i++) {
			
			auto value = strtol(ptr, &endptr, 10);
			if (ptr == endptr) {
				ptr++;
			}
			else {
				ptr = endptr;
				decode.push_back(value);
			}
				
		}


	for (int i = 0; i < decode.size(); i++) {
	
		T = decode[i];
		tmp = BackTable[T];
		Text += tmp;
		NewText.push_back(tmp);
	}
	cout << Text;
	return Text;
}
	

	

