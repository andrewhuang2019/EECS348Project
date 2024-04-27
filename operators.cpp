#include <iostream>
#include <string>
using namespace std;

class Operators {
    private:
        char trueValue;
        char falseValue;
    public:
        Operators(char t, char f){
            trueValue = t;
            falseValue = f;
        }
        Operators(){

        }

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