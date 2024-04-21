#include <iostream>
#include <string>
#include <stdbool.h>
using namespace std;



class Parser {

    private:
    char operators[5] = {'&','|','!','@','$'};

    public:

    int main() {
        //example of getting user input and removing whitespace
        string expr;
        getline(cin, expr);
        expr = removeWhitespace(expr);
        cout << expr;
        return true;
    }

    string removeWhitespace(string expr);
    bool isValid(string input);

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
    }

    string removeWhitespace(string expr){
        string::iterator end_pos = remove(expr.begin(), expr.end(), ' ');
        expr.erase(end_pos, expr.end());
        return expr;
    }

};