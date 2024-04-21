#include <iostream>
#include <string>
using namespace std;

int main() {
    string test1 = "T|F";
    orFunction(test1);

    string test2 = "T&F";
    andFunction(test2);

    string test3 = "T!F";
    notFunction(test3);

    string test4 = "T@F";
    nandFunction(test4);

    string test5 = "T$F";
    xorFunction(test5);
}

string orFunction(string expression){
    string ans = "";
    if(expression[0] == 'T' || expression[2] == 'T'){
        ans = "T";
    }

    if(expression[0] == 'F' || expression[2] == 'T'){
        ans = "T";
    }

    if(expression[0] == 'T' || expression[2] == 'F'){
        ans = "T";
    }

    if(expression[0] == 'F' || expression[2] == 'F'){
        ans = "F";
    }

    return ans;
}

string andFunction(string expression){
    string ans = "";
    if(expression[0] == 'T' && expression[2] == 'T'){
        ans = "T";
    }

    if(expression[0] == 'F' && expression[2] == 'T'){
        ans = "F";
    }

    if(expression[0] == 'T' && expression[2] == 'F'){
        ans = "F";
    }

    if(expression[0] == 'F' && expression[2] == 'F'){
        ans = "T";
    }

    return ans;
}

string notFunction(string expression){
    string ans = "";
    if(expression[0] == 'T' && !(expression[2] == 'T')){
        ans = "F";
    }

    if(expression[0] == 'F' && !(expression[2] == 'T')){
        ans = "T";
    }

    if(expression[0] == 'T' && !(expression[2] == 'F')){
        ans = "T";
    }

    if(expression[0] == 'F' && !(expression[2] == 'F')){
        ans = "F";
    }

    return ans;
}

string nandFunction(string expression){
    string ans;
    if (expression[0] == 'T' && expression[2] == 'T'){
        ans = "F";
    }
    else if (expression[0] == 'T' && expression[2] == 'F'){
        ans = "T";
    }
    else if (expression[0] == 'F' && expression[2] == 'T'){
        ans = "T";
    }
    else if (expression[0] == 'F' && expression[2] == 'F'){
        ans = "T";
    }
    return ans;
}

string xorFunction(string expression){
    string ans;
    if (expression[0] == 'T' && expression[2] == 'T'){
        ans = "F";
    }
    else if (expression[0] == 'T' && expression[2] == 'F'){
        ans = "T";
    }
    else if (expression[0] == 'F' && expression[2] == 'T'){
        ans = "T";
    }
    else if (expression[0] == 'F' && expression[2] == 'F'){
        ans = "F";
    }
    return ans;
}