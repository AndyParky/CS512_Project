/*
Comments:
Drew, please do this again and submit it with part 4. I'll grade it then. 
You need 3 fields in your token. The constructor only stores the string to parse. 
get_token parses it and returns the next token from that string (the parameter is the RETURN value). 
get_token prints out nothing. Your parsing is far too simplistic and won't quite work. 
You need to classify what you find and you need to convert everything into numbers that can be easily used and checked.
*/

/*
Exercises 3-5 rely on the following grammar:
expr ::= term [{+ | –} term]*
term ::= factor [{* | /} factor]*
factor ::= (expr) | number
where number is a real number as described in part 2 (I hope you’ve written out the syntax rule for number by now).  Make sure to report the proper errors at the proper levels in the code.

3.	Implement a lexical analyzer for this language.  Make sure to write out the grammar for the LA (include it in a comment).

// Grammar:
// I::=N
// N::= DN|D
// D::= 0|1|2|3|4|5|6|7|8|9|.|+|-|*|/|(|)|
*/
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>

#include "LexicalAnalyzer.h"

using namespace std;

bool LexicalAnalyzer::get_token(token thisToken)
{
	//print token
	cout << "Token: " << thisToken.t_input << "," << thisToken.t_value << endl;
	return false;
}

bool LexicalAnalyzer::isSymbol(char sym)
{
	if (sym == '(' || sym == ')' || sym == '+' || sym == '-' || sym == '*' || sym == '/') {
		return true;
	}
	else {
		return false;
	}
}

LexicalAnalyzer::LexicalAnalyzer(string expression)
{
	token myToken;
	string tokenString;
	int tokenValue = 0;

	cout << "tokenString at top of LexicalAnalyzer: " << expression << endl;
	//converts string to vector of chars
	vector<char> v(expression.begin(), expression.end());

	for (auto i : v) {
		if (isspace(i)) {
			//if space, count as delimiter
			//make recent contents of tokenString, tokenValue a token.
			myToken.t_input = tokenString;
			myToken.t_value = tokenValue; // position
			get_token(myToken);
			tokenString = "";
		}
		else if (isSymbol(i)){
			//if symbol, count as own token

			//wrap up previous token
			myToken.t_input = tokenString; 
			myToken.t_value = tokenValue; 
			get_token(myToken);
			tokenString = "";
			//set symbol as next token
			myToken.t_input = i;
			myToken.t_value += 1;
			get_token(myToken);
			tokenString = "";
		}
		else {
			//push char to string tokenString
			//increment tokenValue

			tokenString += i;
			myToken.t_value += 1;
		}
	}
	//tokenValue = 0;
	cin.get();
}

LexicalAnalyzer::~LexicalAnalyzer()
{
}

bool LexicalAnalyzer::scan_number(char c)
{
	if (isdigit(c)) {
		return true;
	}
	else
		return false;
}

int main() {
	string inputExpression;

	cout << "Input expression for evaluation: ";
	cin >> inputExpression;
	LexicalAnalyzer LA(inputExpression);

	cin.get();

	return 0;
}
