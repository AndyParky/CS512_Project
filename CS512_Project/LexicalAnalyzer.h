#pragma once
#include <iostream>
#include <vector>


using namespace std;

struct token {
	string t_input;
	double t_value;
};

class LexicalAnalyzer
{
public:
	bool get_token(token);
	bool isSymbol(char);

	LexicalAnalyzer(string);
	~LexicalAnalyzer();
private:
	bool scan_number(char);
	
};

