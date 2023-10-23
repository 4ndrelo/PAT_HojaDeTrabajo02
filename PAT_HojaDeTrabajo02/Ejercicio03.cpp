#include "Ejercicio03.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <cctype>



int Ejercicio03::calculate(string s)
{
    stack<int> numbers;
    stack<char> operators;

    int num = 0;
    int result = 0;
    int sign = 1;  // 1 representa positivo, -1 representa negativo

    for (char c : s) {
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        }
        else {
            if (c == '+') {
                result += sign * num;
                sign = 1;
            }
            else if (c == '-') {
                result += sign * num;
                sign = -1;
            }
            else if (c == '*') {
                int prev = numbers.top();
                numbers.pop();
                result += sign * prev;
                num = 0;
            }
            else if (c == '/') {
                int prev = numbers.top();
                numbers.pop();
                result += sign * prev;
                num = 0;
            }
            else if (c == ' ') {
                // Ignorar espacios en blanco
                continue;
            }
        }
    }

    result += sign * num;
    return result;
}

