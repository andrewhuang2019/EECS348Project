#include <iostream>
#include <string>
#include <stdbool.h>
#include <map>
#include <algorithm>
#include "operators.cpp"

using namespace std;

class Parser {
    private:
        char operators[5] = {'&','|','!','@','$'}; // list of all valid operator symbols
        char trueValue;
        char falseValue;
        Operators ops = Operators(trueValue, falseValue);

    public:
        //ops = Operators(trueValue, falseValue);
        //: ops(t, f), trueValue(trueValue), falseValue('F') 
        Parser(char t, char f) {
            trueValue = t;
            falseValue = f;
            ops = Operators(trueValue, falseValue);
        }

        string removeWhitespace(string);
        string evaluate(string);
        string expressionOverarching(string);
        string expressionHandler(string);
        bool isValid(string);
        int printValues();
};

//removes any spaces within expression. 
string Parser::removeWhitespace(string expr){
    string::iterator end_pos = remove(expr.begin(), expr.end(), ' ');
    expr.erase(end_pos, expr.end());
    return expr;
}

//runs the expressionHandler function until output size = 1 
string Parser::expressionOverarching(string expr) {
    while (expr.size() > 1){
        expr = expressionHandler(expr);
    }
    if (expr[0] != trueValue && expr[0] != falseValue){
        throw 505;
    }
    return expr;
}

/*
handles logic for a basic expression with parenthesis (ex: (!T) or (T&F))
after the evaluation of the expression, replaces the basic expression with T/F variable
returns resulting full string expression with replacement
*/
string Parser::expressionHandler(string expr) {
    for (int i = 0; i < expr.size(); i++) {
        if (expr[i] == '!' && expr[i+1] != '(' && expr[i+1] != ')') {
			expr.replace(i,2,ops.notFunction(expr.substr(i,2)));
        }
    }
    if (expr.size() == 1){
        return expr;
    }
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
        string evaluateStr = expr.substr(startIndex+1,(endIndex-startIndex-1));             
	// Generates substring from operation area (excluding parentheses) to be evaluated
        if (isValid(evaluateStr)){
            expr.replace(startIndex,(endIndex-startIndex+1),evaluate(evaluateStr));
		// Replaces evaluation area (including parentheses) with evaluated substring
            return expr;                                                                        
		// Returns input string with the area replaced
        } else {
            return "Invalid expression";
        }
    }
}

//checks if a 3 character expression is a valid statement
bool Parser::isValid(string expr){
    if (expr[0] != trueValue && expr[0] != falseValue){
        return false;
    }
    if (expr[2] != trueValue && expr[2] != falseValue){
        return false;
    }
    for (int i = 0; i < 5; i++){
        if (expr[1] == operators[i]){
            return true;
        }
    }
    return false;
}

//returns a T or F value based on what the second value (operator) of the string expression is 
string Parser::evaluate(string expr){

    if (expr[1] == '|'){
        return ops.orFunction(expr);
    } else if (expr[1] == '&') {
        return ops.andFunction(expr);
    } else if (expr[1] == '@'){
        return ops.nandFunction(expr);
    } else if (expr[1] == '$') {
        return ops.xorFunction(expr);
    } else { //throws an error if the second expression is not one of the valid operators |, &, @, $ 

        throw std::runtime_error("Invalid operator in expression");

    }

}
