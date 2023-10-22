#include "Ejercicio03.h"

int Ejercicio03::calculate(std::string s) 
{
    return evaluateExpression(s);
}
int evaluateExpression(const std::string& s) {
    std::stack<int> numStack;
    std::stack<char> opStack;
    int num = 0;
    char sign = '+';

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        }
        if (!isdigit(c) && c != ' ' || i == s.length() - 1) {
            if (sign == '-') {
                numStack.push(-num);
            }
            else if (sign == '+') {
                numStack.push(num);
            }
            else if (sign == '*') {
                int top = numStack.top();
                numStack.pop();
                numStack.push(top * num);
            }
            else if (sign == '/') {
                int top = numStack.top();
                numStack.pop();
                numStack.push(top / num);
            }
            num = 0;
            sign = c;
        }
    }

    int result = 0;
    while (!numStack.empty()) {
        result += numStack.top();
        numStack.pop();
    }

    return result;
}