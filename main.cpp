#include <iostream>
#include <string>
#include "parser.cpp"

using namespace std;

Parser parse = Parser();

void readInput();

int main(){
    readInput();
    return 0;
}

void readInput(){
    string userInput;
    getline(cin,userInput);
    userInput = parse.removeWhitespace(userInput);

    while (userInput.size() > 1){
        userInput = parse.evaluate(userInput);
    }
    cout << userInput << endl;

    // if (parse.isValid(userInput)){
    //     throw ("Invalid Input");
    // } else {

    // }
    
}