#include <iostream>
#include <string>
#include <stdbool.h>
#include <map>
#include <algorithm>
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
/*
string parenthesesHandler(string expr) {
    Parser parse = Parser();
    int openParen = 0;
    int closeParen = 0;
    int index = 0;
    int openIndex;
    for (int i = 0; i < sizeof(expr); i++) {
        if (expr[i] == '(') {
            openParen++;
            if (openParen == 1) {
                openIndex = index;
            }
        }
        if (expr[i] == ')') {
            closeParen++;
        }
        index++;
        if (openParen == closeParen && openParen != 0) {
            break;
        }
    }
    if (openParen == 0) {
        if (parse.isValid(expr)) {
            
        };
    } else {
        string subParen = expr.substr(openIndex,index);
        return parenthesesHandler(subParen);
    }
    
}
*/

string parenthesesHandler(string expr) {
    map<int, int> parenCount;
    int openParen = 0;
    int closeParen = 0;
    for (int i = 0; i < sizeof(expr); i++) {
        if (expr[i] == '(') {
            openParen++;
        }
        if (expr[i] == ')') {
            closeParen++;
        }
        parenCount[i] = openParen - closeParen;
    }
    int maxDepth = 0;
    for (int i = 0; i < sizeof(expr); i++) {
        if (parenCount[i] > maxDepth) {
            maxDepth = parenCount[i];
        }
    }
    int startIndex = 0;
    for (int i = 0; i < sizeof(expr); i++) {
        if (parenCount[i] == maxDepth) {
            break;
        }
        startIndex++;
    }
    int endIndex = startIndex;
    while 
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
                if (expr[i+1] == '(' || expr[i+1] == ')' || expr[i+1] == ' ') {
                    return false;
                }
            }
        }
    }
}