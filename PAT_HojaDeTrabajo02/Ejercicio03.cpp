#include "Ejercicio03.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>

int Ejercicio03::calculate(string s)
{
    std::stack<int> numbers;
    std::stack<char> operators;
    std::vector<char> validOperators = { '+', '-', '*', '/' };

    int num = 0;
    for (char c : s) {
        if (c == ' ') {
            continue;  // Saltar espacios en blanco
        }

        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        }
        else {
            numbers.push(num);
            num = 0;

            while (!operators.empty() && std::find(validOperators.begin(), validOperators.end(), operators.top()) != validOperators.end()) {
                if ((c == '+' || c == '-') && (operators.top() == '*' || operators.top() == '/')) {
                    break;
                }
                int b = numbers.top();
                numbers.pop();
                int a = numbers.top();
                numbers.pop();
                char op = operators.top();
                operators.pop();

                if (op == '+') {
                    numbers.push(a + b);
                }
                else if (op == '-') {
                    numbers.push(a - b);
                }
                else if (op == '*') {
                    numbers.push(a * b);
                }
                else if (op == '/') {
                    numbers.push(a / b);
                }
            }

            operators.push(c);
        }
    }

    numbers.push(num);

    while (!operators.empty()) {
        int b = numbers.top();
        numbers.pop();
        int a = numbers.top();
        numbers.pop();
        char op = operators.top();
        operators.pop();

        if (op == '+') {
            numbers.push(a + b);
        }
        else if (op == '-') {
            numbers.push(a - b);
        }
        else if (op == '*') {
            numbers.push(a * b);
        }
        else if (op == '/') {
            numbers.push(a / b);
        }
    }

    return numbers.top();
}

