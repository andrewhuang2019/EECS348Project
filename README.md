# **Boolean Logic Simulator in C++**

![Image alt text](logo.svg)  

## Introduction:
This project simulates digital logic systems in C++, through the comprehensive definition of functionality with gates and their interaction with expressions containing boolean True and False input. 

The gates that are implemented in this project are: AND, OR, NOT, NAND, XOR.  

## News:  
Began Implementation phase of the program - added three C++ files (main.cpp, parser.cpp, and operators.cpp).  
Added Test Cases document, which contains a table with testing for the program.  
Added User Manual document, which provides an in-depth description of how to use the program.  
Added Quick Start Section, giving users easy steps to follow to run the program.  

## Functionality:
#### Truth Value Input
Input from the user through the terminal or a file system is read so that the string expressions can be parsed. 

#### Error Handling
False inputs of any kind caught and relative information is relayed back to the user. This includes missing operators, wrong characters, and any other errors. 

#### Expression Parsing
The ability to translate string expressions (e.g T, F, &, |) to C++ boolean logic (e.g &&, ||) in a cohesive methodology. Stores the information so that later calculations can be made. 

#### Parenthesis Handling
Parsing allows for usage of parenthesis to prioritize evaluation of expressions. Program is able to understand when false parenthesis input is made. 

#### Calculation and Output
Logical parsing systems within the program are able to be combined together to calculate the final True or False output, and then the result is relayed back to the user through the same method that they input the expression in. 

## Examples of Valid and Invalid Expressions: 
#### Valid  
(T | F) $ F  =>  True  
(F @ T) | (T @ F)  =>  False  
(((((T | F) & F) | (T & (T | F))) @ (T @ T)) $ (! (T | F)))  =>  True  

#### Invalid  
!&T  [Mising operand after NOT]  
T = !(T & T)  [Variable defined in terms of itself]  
True | F  [Inconsistent characters]  

More examples can be found in the [Test Cases](doc/TestCases.pdf) document.  

## Quick Start (How to Run): 

Below is a quick tutorial on how to use the project.  

1. Download the latest release on the right of the GitHub.  

Picture here  

2. Unzip the files of the project.  

Picture here  

3. Navigate to the project folder "src" in the terminal.  

Picture here  

4. To compile the code, use the command below: 

`g++ main.cpp`

5. To see the output, use the command below:

`./a.out`

6. Input if you want to use variables other than T/F for the expression.  

Picture here  

7. Input the expression.  

Picture here  

8. The program will return an output.  

Picture here  

If you have any more questions or want a more in-depth explanation, reference the [User Manual](doc/UserManual.pdf).  