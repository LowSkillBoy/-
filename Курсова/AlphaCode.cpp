#include "AlphaCode.h"

AlphaCode::AlphaCode()
{
	char trans;
	for (int i = 65; i <= 90; i++) {
		id++;
		trans = (char)i;
		Text.emplace(trans, id);
		BackText.emplace(id, trans);
	}
	for (int i = 97; i <= 122; i++) {
		id++;
		trans = (char)i;
		Text.emplace(trans, id);
		BackText.emplace(id, trans);
	}
	id++;
	Text.emplace(' ', id);
	BackText.emplace(id, ' ');
	
	
}

string AlphaCode::Encrypt(string text) {
	Key k;
	k.OpenKey();
	char tmp;
	int Inttmp;
	int Result;
	ReturnCode += BackText[k.gete()];
	for (int i = 0; i < text.length(); i++) {
		tmp = text[i];

		Inttmp = Text[tmp];
		if (Inttmp == 53) {
			Result = Text[53];
			ReturnCode += BackText[Result];
		}
		else {
			Result = Inttmp + k.gete();
			if (Result > 53) {
				Inttmp=Result;
				Result = Inttmp - k.gete();
			}
			ReturnCode += BackText[Result];
		}
	}
	cout << ReturnCode;
	return ReturnCode;
}


string AlphaCode::Decrypt(string code) {
	Key k;
	string tmp;
	k.OpenKey();
	int Inttmp;
	int Result;
	int value;
	char strtmp;
	int okey=Text[code[0]];
	for (int i = 1; i < code.length(); i++) {

				strtmp=code[i];
				Inttmp = Text[strtmp];
				if (Inttmp == 53) {
					value = Text[53];
					decode.push_back(value);
				}else{
				value = Inttmp - okey;
				decode.push_back(value);
		}

	}
	Inttmp = 0;
	for (int i = 0; i < decode.size(); i++) {

		Inttmp = decode[i];
		tmp = BackText[Inttmp];
		ReturnText += tmp;

	}
	cout << ReturnText;
	return ReturnText;
}