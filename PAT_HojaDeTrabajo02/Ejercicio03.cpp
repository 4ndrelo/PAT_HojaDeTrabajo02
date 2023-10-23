#include "Ejercicio03.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <string>
#include <stack>
#include <cctype>


int Ejercicio03::calculate(string s)
{
    stack<int> nums;
    stack<char> ops;
    int num = 0;
    char op = '+';

    for (char c : s) {
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (op == '+') {
                nums.push(num);
            }
            else if (op == '-') {
                nums.push(-num);
            }
            else if (op == '*') {
                int prev = nums.top();
                nums.pop();
                nums.push(prev * num);
            }
            else if (op == '/') {
                int prev = nums.top();
                nums.pop();
                nums.push(prev / num);
            }

            num = 0;
            op = c;
        }
    }

    if (op == '+') {
        nums.push(num);
    }
    else if (op == '-') {
        nums.push(-num);
    }
    else if (op == '*') {
        int prev = nums.top();
        nums.pop();
        nums.push(prev * num);
    }
    else if (op == '/') {
        int prev = nums.top();
        nums.pop();
        nums.push(prev / num);
    }

    int result = 0;
    while (!nums.empty()) {
        result += nums.top();
        nums.pop();
    }

    return result;
}

