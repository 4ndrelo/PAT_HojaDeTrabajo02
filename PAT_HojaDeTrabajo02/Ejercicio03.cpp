#include "Ejercicio03.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <cctype>


using std::string;
using std::stack;



int Ejercicio03::calculate(string s)
{
    stack<int> nums;
    stack<char> ops;
    int num = 0;
    char op = '+';

    for (char c : s) {
        if (std::isdigit(c)) {
            num = num * 10 + (c - '0');
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!ops.empty() && (ops.top() == '*' || ops.top() == '/')) {
                int b = nums.top();
                nums.pop();
                int a = nums.top();
                nums.pop();
                char curr_op = ops.top();
                ops.pop();
                if (curr_op == '*') {
                    nums.push(a * b);
                }
                else if (curr_op == '/') {
                    nums.push(a / b);
                }
            }

            nums.push(num);
            num = 0;
            op = c;
            ops.push(c);
        }
        else if (c == ' ') {
            continue;
        }
    }

    while (!ops.empty()) {
        int b = nums.top();
        nums.pop();
        int a = nums.top();
        nums.pop();
        char curr_op = ops.top();
        ops.pop();
        if (curr_op == '+') {
            nums.push(a + b);
        }
        else if (curr_op == '-') {
            nums.push(a - b);
        }
        else if (curr_op == '*') {
            nums.push(a * b);
        }
        else if (curr_op == '/') {
            nums.push(a / b);
        }
    }

    return nums.top();


}

