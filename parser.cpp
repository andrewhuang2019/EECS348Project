#include <iostream>
#include <string>
#include <stdbool.h>
using namespace std;

char operators[] = {'&','|','!','@','$'};

string removeWhitespace(string expr);
bool isValid(string expr);

int main() {
    //example of getting user input and removing whitespace
    string expr;
    getline(cin, expr);
    expr = removeWhitespace(expr);
    cout << expr;
}

string removeWhitespace(string expr){
    string::iterator end_pos = remove(expr.begin(), expr.end(), ' ');
    expr.erase(end_pos, expr.end());
    return expr;
}

bool isValid(string expr) {
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
    if (openParen != closeParen) {
        return false;
    }
    return true;
}