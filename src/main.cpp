#include <iostream>
#include <string>
#include "parser.cpp"

using namespace std;

int readInput();

int main(){
    readInput();
    return 0;
}

int readInput(){

    //creates placeholder variables for user input
    string choice = "N";
    string trueValueInput = "T";
    string falseValueInput = "F";
    char trueValue = 'T';
    char falseValue = 'F';

    cout << //This outputs a beautifully crafted bee with our logo
        //in order to represent the wonderful abbreviation B.E.E. we have used throughout this project
        "\n        ....         .......\n"             
        " .:...  .=+++-.   .::::::::::\n"            
        "..::-=+-.   :+-  .::::::::::.    .\n"       
        "      .==.   -+  .:::::::::.  .----:.\n"    
        "       .+:   :+: .:::::::::..:------:.\n"   
        "     ...------+- .:::::::: .---------.\n"   
        "    .--------=+--.::::::...----------.\n"   
        " .#%=-----**=-----:::::..------------.\n"   
        " -@*----+@@@@@=----:::..-----------.\n"     
        "  ------*@@@@@+------::--===++++=:..\n"     
        "   ------#@@%*-----====++===-=####=:=**:\n" 
        "   :--------------======+#*-:::*###-::.\n"  
        "   .-------------========##+:::-*##+:.\n"   
        "     .---------==========###-:::+###:.\n"   
        "       ....:=============###*:::=###..\n"   
        "     .*****++-++=======::####:::=#+.\n"     
        "     ......:=+=.-+=:++:::####:::..\n"       
        "       .=++=-. .++..++:   ...\n"            
        "              .++. .++:\n"                  
        "              -+-. .=+.\n\n"; 

    cout << 
        "   __ ____  _____   _  _______  ___   _  _____    _________\n"
        "  / // / / / / _ | / |/ / ___/ / _ | / |/ / _ \\  / ___/ __ \\\n"
        " / _  / /_/ / __ |/    / (_ / / __ |/    / // / / /__/ /_/ /\n"
        "/_//_/\\____/_/ |_/_/|_/\\___/ /_/ |_/_/|_/____/  \\___/\\____(_)\n\n";

    //gets the choice of if the user wants to use their own variables for True/False
    cout << "Do you want to use your own variables for T and F?(Y/N): ";

    getline(cin, choice); //store answer in choice

    if (choice != "Y" && choice != "N"){
        cout << "Enter Y or N"; //if invalid reprompt user
        return 0;
    }

    //if the choice above is Y for yes, then gathers user information for True/False variables
    if (choice == "Y"){

        cout << "Enter value for T: ";
        cin >> trueValueInput;

        if (trueValueInput.length() > 1) {
            cout << "Variables must be one character.";
            return 0;
        }

        cout << "Enter value for F: ";
        cin >> falseValueInput;

        if (falseValueInput.length() > 1) {
            cout << "Variables must be one character.";
            return 0;
        }

        if (trueValueInput == falseValueInput){
            cout << "Variables must be unique.";
            return 0;
        }

        trueValue = trueValueInput[0];
        falseValue = falseValueInput[0];

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
    if (userInput.size() == 0){
        cout << "Evaluation: " << "Invalid Expression" << endl;
        return 0;
    }

    //ouputs original expression
    cout << "Expression: " << userInput << endl;
    try{
        //organizes and sends result as "True" or "False"
        userInput = parse.expressionOverarching(userInput);
        string trueVal;
        trueVal += trueValue;
        string result = (userInput == trueVal) ? "True" : "False";
        cout << "Evaluation: " << result << endl;
    } catch(...){
        cout << "Invalid Expression" << endl;
    }
    return 0;
}
