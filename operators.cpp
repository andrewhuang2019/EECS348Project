#include <iostream>
#include <string>
using namespace std;

class Operators {
    private:
        char trueValue;
        char falseValue;
    public:
        Operators(char trueValue, char falseValue){
            this->trueValue = trueValue;
            this->falseValue = falseValue;
        }
        string orFunction(string expression){
            string ans = "";
            if(expression[0] == trueValue && expression[2] == trueValue){
                ans = "T";
            }

            else if(expression[0] == falseValue && expression[2] == trueValue){
                ans = "T";
            }

            else if(expression[0] == trueValue && expression[2] == falseValue){
                ans = "T";
            }

            else if (expression[0] == falseValue && expression[2] == falseValue){
                ans = "F";
            }
            return ans;
        }

        string andFunction(string expression){
            string ans = "";
            if(expression[0] == trueValue && expression[2] == trueValue){
                ans = "T";
            }

            else if(expression[0] == falseValue && expression[2] == trueValue){
                ans = "F";
            }

            else if(expression[0] == trueValue && expression[2] == falseValue){
                ans = "F";
            }

            else if(expression[0] == falseValue && expression[2] == falseValue){
                ans = "T";
            }
            return ans;
        }

        string notFunction(string expression){
            string ans = "";
            if(expression[1] == falseValue){
                ans = "T";
            }

            else if(expression[1] == trueValue){
                ans = "F";
            }

            return ans;
        }

        string nandFunction(string expression){
            string ans;
            if (expression[0] == trueValue && expression[2] == trueValue){
                ans = "F";
            }
            else if (expression[0] == trueValue && expression[2] == falseValue){
                ans = "T";
            }
            else if (expression[0] == falseValue && expression[2] == trueValue){
                ans = "T";
            }
            else if (expression[0] == falseValue && expression[2] == falseValue){
                ans = "T";
            }
            return ans;
        }

        string xorFunction(string expression){
            string ans;
            if (expression[0] == trueValue && expression[2] == trueValue){
                ans = "F";
            }
            else if (expression[0] == trueValue && expression[2] == falseValue){
                ans = "T";
            }
            else if (expression[0] == falseValue && expression[2] == trueValue){
                ans = "T";
            }
            else if (expression[0] == falseValue && expression[2] == falseValue){
                ans = "F";
            }
            return ans;
        }
};