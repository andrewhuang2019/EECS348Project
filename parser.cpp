#include <iostream>
#include <string>
#include <stdbool.h>
using namespace std;

char operators[] = {'&','|','!','@','$'};

string removeWhitespace(string expr);
bool isValid(string input);

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

bool isValid(string input) {
    int openParen = 0;
    int closeParen = 0;
    for (int i = 0; i < sizeof(input); i++) {
        if (input[i] == '(') {
            openParen++;
        }
        if (input[i] == ')') {
            closeParen++;
        }
        for (int j = 0; j < sizeof(operators); j++) {
            if (input[i] == operators[j]) {
                for (int k = 0; k < sizeof(operators); k++) {
                    if (input[i+1] == operators[k]) {
                        return false;
                    }
                }
                if (input[i+1] == '(' || input[i+1] == ')') {
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