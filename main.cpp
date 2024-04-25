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

    string choice = "Y";
    char trueValue = 'T';
    char falseValue = 'F';

    cout << "Do you want to use your own variables for T and F?(Y/N): ";

    getline(cin, choice);

    if (choice == "Y"){

        cout << "Enter value for T: ";
        cin >> trueValue;

        cout << "Enter value for F: ";
        cin >> falseValue;

    }

    Parser parse = Parser(trueValue, falseValue);

    string userInput;
    cout << "Enter expression: ";
    getline(cin,userInput);
    userInput = parse.removeWhitespace(userInput);

    /*
    while (userInput.size() > 1){
        userInput = parse.expressionHandler(userInput);
    }*/
    cout << userInput << endl;

    // if (parse.isValid(userInput)){
    //     throw ("Invalid Input");
    // } else {

    // }
    
}