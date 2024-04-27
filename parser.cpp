#include <iostream>
#include <string>
#include <stdbool.h>
#include <map>
#include <algorithm>
#include "operators.cpp"

using namespace std;

class Parser {
    private:
        char operators[5] = {'&','|','!','@','$'};
        char trueValue;
        char falseValue;
        Operators ops = Operators(trueValue, falseValue);

    public:
        //ops = Operators(trueValue, falseValue);
        //: ops(t, f), trueValue('T'), falseValue('F') 
        Parser(char t, char f) {
            trueValue = t;
            falseValue = f;
            ops = Operators(trueValue, falseValue);
        }

        Parser(){

        }
        string removeWhitespace(string);
        string evaluate(string);
        string expressionOverarching(string);
        string expressionHandler(string);
        bool isValid(string);
        int printValues();
};

int Parser::printValues(){
    cout << trueValue;
    cout << falseValue;
    return 0;
}

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
string Parser::expressionOverarching(string expr) {
    while (expr.size() > 1){
        expr = expressionHandler(expr);
    }
    return expr;
}

string Parser::expressionHandler(string expr) {
    for (int i = 0; i < expr.size(); i++) {
        if (expr[i] == '!' && expr[i+1] != '(' && expr[i+1] != ')') {
			expr.replace(i,2,ops.notFunction(expr.substr(i,2)));
        }
    }
    cout << expr << "\n";
    // map<int, int> parenCount;                       // Creates map to keep track of parentheses count (see next for loop)
    // int openParen = 0;                              // Creates ints to keep track of parentheses count
    // int closeParen = 0;
    // for (int i = 0; i < sizeof(expr); i++) {        // For every index in string, generates count of how many open parentheses there have been minus count of how many close parentheses there have been, and appends it to map
    //     if (expr[i] == '(') {
    //         openParen++;
    //     }
    //     if (expr[i] == ')') {
    //         closeParen++;
    //     }
    //     parenCount[i] = openParen - closeParen;
    // }
    // //cout << openParen << "\n" << closeParen << "\n";
    // /* if (openParen != closeParen) {
    //     throw std::runtime_error("ERROR: Parentheses mismatch");
    // } */
    // int maxDepth = 0;
    // for (int i = 0; i < sizeof(expr); i++) {        // Generates count of max parentheses depth that expression reaches
    //     if (parenCount[i] > maxDepth) {
    //         maxDepth = parenCount[i];
    //     }
    // }
    // int startIndex = 0;
    // while (parenCount[startIndex] != maxDepth) {    // Sets starting index of operation area to first place where max depth is reached
    //     startIndex++;
    // }
    // int endIndex = startIndex;
    // while (parenCount[endIndex] == maxDepth) {      // Sets ending index of operation area to end of this particular max depth region
    //     endIndex++;
    // }
    // endIndex++;
    if (expr.size() == 3 && isValid(expr) && expr[0] != '('){       // Checks if there are no parentheses left and evaluates
        return evaluate(expr);
    }
    int endIndex = 0;
    while (expr[endIndex] != ')'){         
        endIndex++;
    }
    int startIndex = endIndex;
    while (expr[startIndex] != '('){
        startIndex--;
    }
    int length = endIndex-startIndex;
    if (length == 2){                     // Runs if there is a single value enclosed in parentheses
        expr.erase(startIndex,1);
        expr.erase(endIndex-1,1);
        return expr;
    } else{
        string evaluateStr = expr.substr(startIndex+1,(endIndex-startIndex-1));             // Generates substring from operation area (excluding parentheses) to be evaluated
        cout << "Step: " << evaluateStr << endl;
        if (isValid(evaluateStr)){
            expr.replace(startIndex,(endIndex-startIndex+1),evaluate(evaluateStr));        // Replaces evaluation area (including parentheses) with evaluated substring
            return expr;                                                                        // Returns input string with the area replaced
        } else {
            return "Invalid expression";
        }
    }
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
    if (expr[0] != 'T' && expr[0] != 'F'){
        return false;
    }
    if (expr[2] != 'T' && expr[2] != 'F'){
        return false;
    }
    for (int i = 0; i < 5; i++){
        if (expr[1] == operators[i]){
            return true;
        }
    }
    return false;
}

string Parser::evaluate(string expr){
    //returns a T or F value based on what the second value (operator) of the string expression is 
    if (expr[1] == '|'){
        return ops.orFunction(expr);
    } else if (expr[1] == '&') {
        return ops.andFunction(expr);
    } else if (expr[1] == '@'){
        return ops.nandFunction(expr);
    } else if (expr[1] == '$') {
        return ops.xorFunction(expr);
    } else { //throws an error if the second expression is not either. 

        throw std::runtime_error("Invalid operator in expression");

    }

}



int main() {
    Parser myParser = Parser('T', 'F');
    string sampleExpr = "! F | ! T";

    sampleExpr = myParser.removeWhitespace(sampleExpr);
    string newExpr = myParser.expressionOverarching(sampleExpr);
    cout << newExpr;
    return 0;
}

