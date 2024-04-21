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
    }
    if (openParen != closeParen) {
        return false;
    }
    return true;
}