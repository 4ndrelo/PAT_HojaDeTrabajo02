#include "Ejercicio03.h"

int Ejercicio03::calculate(string s)
{
    int result = 0;  
    int num = 0;     
    int i = 0;
    int sign = 1;  
    for (char c : s) {
        if (isdigit(c)) {
            num = num * 10 + (c - '0'); 
        }
        else if (c == '+') {
            result += sign * num;  
            num = 0;  
            sign = 1; 
        }
        else if (c == '-') {
            result += sign * num;
            num = 0;
            sign = -1; 
        }
        else if (c == '*') {
            num = num * (s[++i] - '0'); 
        }
        else if (c == '/') {
            num = num / (s[++i] - '0'); 
        }
    }

    
    result += sign * num;

    return result;
}
