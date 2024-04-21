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
        string removeWhitespace(string);
        string evaluate(string);
        bool isValid(string);
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

// string parenthesesHandler(string expr) {
//     map<int, int> parenCount;
//     int openParen = 0;
//     int closeParen = 0;
//     for (int i = 0; i < sizeof(expr); i++) {
//         if (expr[i] == '(') {
//             openParen++;
//         }
//         if (expr[i] == ')') {
//             closeParen++;
//         }
//         parenCount[i] = openParen - closeParen;
//     }
//     int maxDepth = 0;
//     for (int i = 0; i < sizeof(expr); i++) {
//         if (parenCount[i] > maxDepth) {
//             maxDepth = parenCount[i];
//         }
//     }
//     int startIndex = 0;
//     for (int i = 0; i < sizeof(expr); i++) {
//         if (parenCount[i] == maxDepth) {
//             break;
//         }
//         startIndex++;
//     }
//     int endIndex = startIndex;
//     while 
// }

// bool Parser::isValid(string expr) {
//     int openParen = 0;
//     int closeParen = 0;
//     for (int i = 0; i < sizeof(expr); i++) {
//         if (expr[i] == '(') {
//             openParen++;
//         }
//         if (expr[i] == ')') {
//             closeParen++;
//         }
//         for (int j = 0; j < sizeof(operators); j++) {
//             if (expr[i] == operators[j]) {
//                 for (int k = 0; k < sizeof(operators); k++) {
//                     if (expr[i+1] == operators[k]) {
//                         return false;
//                     }
//                 }
//                 if (expr[i+1] == '(' || expr[i+1] == ')') {
//                     return false;
//                 }
//             }
//         }
//     }
// }

bool Parser::isValid(string expr){
    for (int i = 0; i < 5; i++){
        if (expr[1] == operators[i]){
            return true;
        }
    }
    if (expr[0] != 'T' || expr[0] != 'F'){
        return false;
    }
    if (expr[2] != 'T' || expr[2] != 'F'){
        return false;
    }
    return true;
}

string Parser::evaluate(string expr){
    for (int i = 0; i < sizeof(expr); i++){
        if (expr[i] == ')'){
            string operand = expr.substr(i-3,3);
            std::cout << operand << endl;
            expr[i-4] = 'T';
            expr.erase(i-3, 4);
            return expr;
            }
        }
    string operand = expr.substr(0,3);
    std::cout << operand << endl;
    expr[0] = 'T';
    expr.erase(1, 3);
    return expr;
}