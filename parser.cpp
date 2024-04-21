#include <iostream>
#include <string>
#include <stdbool.h>
using namespace std;

class Parser {
    private:
        char operators[5] = {'&','|','!','@','$'};

    public:
        string removeWhitespace(string expr);
        bool isValid(string input);
};

string Parser::removeWhitespace(string expr){
    string::iterator end_pos = remove(expr.begin(), expr.end(), ' ');
    expr.erase(end_pos, expr.end());
    return expr;
}

bool Parser::isValid(string expr) {
    int openParen = 0;
    int closeParen = 0;
    for (int i = 0; i < sizeof(expr); i++) {
        if (expr[i] == '(') {
            openParen++;
        }
        if (expr[i] == ')') {
            closeParen++;
        }
        for (int j = 0; j < sizeof(operators); j++) {
            if (expr[i] == operators[j]) {
                for (int k = 0; k < sizeof(operators); k++) {
                    if (expr[i+1] == operators[k]) {
                        return false;
                    }
                }
                if (expr[i+1] == '(' || expr[i+1] == ')') {
                    return false;
                }
            }
        }
    }
}