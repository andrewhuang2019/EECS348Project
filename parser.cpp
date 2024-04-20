#include <iostream>
#include <string>
#include <stdbool.h>
using namespace std;

char operators[] = {'&','|','!','@','$'}

bool isValid(string input) {
    int openParen = 0;
    int closeParen = 0;
    for (int i = 0; i < sizeof(input); i++) {
        if (input[i] == '(') {
            openParen++;
        }
        if (input[i] == ')') {
            closeParen++;
        }
    }
    if (openParen != closeParen) {
        return false;
    }
    return true;
}

int main() {

}