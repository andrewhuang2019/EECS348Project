#include <iostream>
#include <string>
#include "parser.cpp"

using namespace std;

void readInput();

int main(){
    readInput();
    return 0;
}

void readInput(){

    //creates placeholder variables for user input
    string choice = "N";
    char trueValue = 'T';
    char falseValue = 'F';

    //gets the choice of if the user wants to use their own variables for True/False
    cout << "Do you want to use your own variables for T and F?(Y/N): ";

    getline(cin, choice);

    //if the choice above is Y for yes, then gathers user information for True/False variables
    if (choice == "Y"){

        cout << "Enter value for T: ";
        cin >> trueValue;

        cout << "Enter value for F: ";
        cin >> falseValue;

        cin.ignore(); //ignores \n leftover from cin above for the cin below

    }

    //gathers user expression to be evaluated
    string userInput = " ";
    cout << "Enter expression: ";
    getline(cin, userInput);

    //creates parser using the T/F variables above. 
    Parser parse = Parser(trueValue, falseValue);

    //removes whitespace inbetween expression and then parses expression
    userInput = parse.removeWhitespace(userInput);

    //ouputs original expression
    cout << "Expression: " << userInput << endl;
    
    userInput = parse.expressionOverarching(userInput);
    
    //organizes and sends result as "True" or "False"
    string trueVal;
    trueVal += trueValue;
    string result = (userInput == trueVal) ? "True" : "False";
    cout << "Evaluation: " << result << endl;
}