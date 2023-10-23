#pragma once

#include <string>
#include <Node.h>
using std::string;

class Ejercicio03
{
public:
	int calculate(string s);
	int getPrecedence(char op);
	bool isOperator(char c);
	vector<string> infixToPostfix(string s);
	int evaluatePostfix(vector<string> postfix);
};

