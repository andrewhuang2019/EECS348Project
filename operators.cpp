#include <iostream>
#include <string>
using namespace std;

class Operators {
    private:
    public:
        string orFunction(string expression){
            string ans = "";
            if(expression[0] == 'T' && expression[2] == 'T'){
                ans = "T";
            }

            else if(expression[0] == 'F' && expression[2] == 'T'){
                ans = "T";
            }

            else if(expression[0] == 'T' && expression[2] == 'F'){
                ans = "T";
            }

            else if (expression[0] == 'F' && expression[2] == 'F'){
                ans = "F";
            }
            return ans;
        }

        string andFunction(string expression){
            string ans = "";
            if(expression[0] == 'T' && expression[2] == 'T'){
                ans = "T";
            }

            else if(expression[0] == 'F' && expression[2] == 'T'){
                ans = "F";
            }

            else if(expression[0] == 'T' && expression[2] == 'F'){
                ans = "F";
            }

            else if(expression[0] == 'F' && expression[2] == 'F'){
                ans = "T";
            }
            return ans;
        }

        string notFunction(string expression){
            string ans = "";
            if(expression[1] == 'F'){
                ans = "T";
            }

            else if(expression[1] == 'T'){
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
};