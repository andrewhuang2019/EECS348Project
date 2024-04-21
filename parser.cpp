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
        string parenthesesHandler(string);
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

string Parser::parenthesesHandler(string expr) {
    map<int, int> parenCount;                       // Creates map to keep track of parentheses count (see next for loop)
    int openParen = 0;                              // Creates ints to keep track of parentheses count
    int closeParen = 0;
    for (int i = 0; i < sizeof(expr); i++) {        // For every index in string, generates count of how many open parentheses there have been minus count of how many close parentheses there have been, and appends it to map
        if (expr[i] == '(') {
            openParen++;
        }
        if (expr[i] == ')') {
            closeParen++;
        }
        parenCount[i] = openParen - closeParen;
    }
    int maxDepth = 0;
    for (int i = 0; i < sizeof(expr); i++) {        // Generates count of max parentheses depth that expression reaches
        if (parenCount[i] > maxDepth) {
            maxDepth = parenCount[i];
        }
    }
    int startIndex = 0;
    while (parenCount[startIndex] != maxDepth) {    // Sets starting index of operation area to first place where max depth is reached
        startIndex++;
    }
    int endIndex = startIndex;
    while (parenCount[endIndex] == maxDepth) {      // Sets ending index of operation area to end of this particular max depth region
        endIndex++;
    }
    endIndex++;
    string evaluateStr = expr.substr(startIndex+1,(endIndex-startIndex-2));             // Generates substring from operation area (excluding parentheses) to be evaluated
    expr.replace(startIndex,(endIndex-startIndex),evaluate(evaluateStr));        // Replaces evaluation area (including parentheses) with evaluated substring
    return expr;                                                                        // Returns input string with the area replaced
}

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

/* int main() {
    Parser myParser = Parser();
    string sampleExpr = "((F$((T|F)&(F@(T|F))))|(T$(T&F)))";
    cout << sampleExpr << "\n";
    string evaluateSample = myParser.parenthesesHandler(sampleExpr);
    cout << evaluateSample << "\n";
    string evaluateEvaluate = myParser.parenthesesHandler(evaluateSample);
    cout << evaluateEvaluate;
    return 0;
} */