# Boolean Logic Simulator in C++

## Introduction:

This project simulates digital logic systems in C++, through the comprehensive definition of functionality with gates and their interaction with expressions containing boolean True and False input. 

The gates that are implemented in this project are as follows:
AND, OR, NOT, NAND, XOR.


## Functionality:
Truth Value Input -  
Input from the user through the terminal or a file system is read so that the string expressions can be parsed. 

Error Handling -  
False inputs of any kind caught and relative information is relayed back to the user. This includes missing operators, wrong characters, and any other errors. 

Expression Parsing -  
The ability to translate string expressions (e.g T, F, &, |) to C++ boolean logic (e.g &&, ||) in a cohesive methodology. Stores the information so that later calculations can be made. 

Parenthesis Handling -  
Parsing allows for usage of parenthesis to prioritize evaluation of expressions. Program is able to understand when false parenthesis input is made. 

Calculation and Output -  
Logical parsing systems within the program are able to be combined together to calculate the final True or False output, and then the result is relayed back to the user through the same method that they input the expression in. 


## Examples of Valid and Invalid Expressions: 
Valid:  
T & F 

Invalid:  
& ! X


## Quick Start (How to Run): 

TBD

