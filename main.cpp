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
    cin >> userInput;
    cout << userInput << endl;

    
    if (parse.isValid(userInput)){
        throw ("Invalid Input");
    } else {

    }
    
}