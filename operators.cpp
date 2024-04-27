#include <iostream>
#include <string>
using namespace std;

class Operators {
    private:
        char trueValue;
        char falseValue;
    public:
        //constructor passes in two characters to be stored in the True/False variables
        Operators(char t, char f){
            trueValue = t;
            falseValue = f;
        }
        Operators(){

        }

        //evaluates expression as an OR gate and returns True/False variable based on evaluation
        string orFunction(string expression){
            string ans = "";
            if(expression[0] == trueValue && expression[2] == trueValue){
                ans = trueValue;
            }

            else if(expression[0] == falseValue && expression[2] == trueValue){
                ans = trueValue;
            }

            else if(expression[0] == trueValue && expression[2] == falseValue){
                ans = trueValue;
            }

            else if (expression[0] == falseValue && expression[2] == falseValue){
                ans = falseValue;
            }
            return ans;
        }

        //evaluates expression as an AND gate and returns True/False variable based on evaluation
        string andFunction(string expression){
            string ans = "";
            if(expression[0] == trueValue && expression[2] == trueValue){
                ans = trueValue;
            }

            else if(expression[0] == falseValue && expression[2] == trueValue){
                ans = falseValue;
            }

            else if(expression[0] == trueValue && expression[2] == falseValue){
                ans = falseValue;
            }

            else if(expression[0] == falseValue && expression[2] == falseValue){
                ans = falseValue;
            }
            return ans;
        }

        //evaluates expression as an NOT gate and returns True/False variable based on evaluation
        string notFunction(string expression){
            string ans = "";
            if(expression[1] == falseValue){
                ans = trueValue;
            }

            else if(expression[1] == trueValue){
                ans = falseValue;
            }

            return ans;
        }

        //evaluates expression as an NAND gate and returns True/False variable based on evaluation
        string nandFunction(string expression){
            string ans;
            if (expression[0] == trueValue && expression[2] == trueValue){
                ans = falseValue;
            }
            else if (expression[0] == trueValue && expression[2] == falseValue){
                ans = trueValue;
            }
            else if (expression[0] == falseValue && expression[2] == trueValue){
                ans = trueValue;
            }
            else if (expression[0] == falseValue && expression[2] == falseValue){
                ans = trueValue;
            }
            return ans;
        }

        //evaluates expression as an XOR gate and returns True/False variable based on evaluation
        string xorFunction(string expression){
            string ans;
            if (expression[0] == trueValue && expression[2] == trueValue){
                ans = falseValue;
            }
            else if (expression[0] == trueValue && expression[2] == falseValue){
                ans = trueValue;
            }
            else if (expression[0] == falseValue && expression[2] == trueValue){
                ans = trueValue;
            }
            else if (expression[0] == falseValue && expression[2] == falseValue){
                ans = falseValue;
            }
            return ans;
        }
};