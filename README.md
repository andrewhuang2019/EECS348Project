# **Boolean Expression Evaluator (B.E.E.) in C++**

![image](https://github.com/andrewhuang2019/EECS348Project/assets/130803554/b71ec4c8-2edd-40e5-8c68-ffcc2961bd7d)

## Introduction:
This project simulates digital logic systems in C++, through the comprehensive definition of functionality with gates and their interaction with expressions containing boolean True and False input. 

The gates that are implemented in this project are: AND, OR, NOT, NAND, XOR.  

## News:  
Finished Implementation of the program - added three C++ files (main.cpp, parser.cpp, and operators.cpp).  
Added Test Cases document, which contains a table with testing for the program.  
Added additional self-made test cases for extra credit.  
Added User Manual document, which provides an in-depth description of how to use the program.  
Added Quick Start Section, giving users easy steps to follow to run the program.  
Created a release to download the program without the documentation and README files.  

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
All given inputs and outputs can be referenced in the [Outputs](doc/Outputs.pdf) document.

## Quick Start (How to Run): 

Below is a quick tutorial on how to use the project.  

1. Download the latest release on the right of the GitHub.  

<img width="1239" alt="Screenshot 2024-04-27 at 8 58 54 PM" src="https://github.com/andrewhuang2019/EECS348Project/assets/108380345/89184646-990d-4938-a3ed-b66f317b50f3">

2. Unzip the files of the project.  

<img width="765" alt="Screenshot 2024-04-27 at 8 57 31 PM" src="https://github.com/andrewhuang2019/EECS348Project/assets/108380345/c6430745-14cc-4e40-bf63-ce4ba21fb60d">

3. Navigate to the project folder in the terminal.  

<img width="266" alt="Screenshot 2024-04-27 at 8 58 21 PM" src="https://github.com/andrewhuang2019/EECS348Project/assets/108380345/3f203fe2-4e54-4147-a312-5f203ecbe16e">

4. To compile the code, use the command below: 

`g++ main.cpp`

5. To see the output, use the command below:

`./a.out`

6. Input if you want to use variables other than T/F for the expression.  

![image](https://github.com/andrewhuang2019/EECS348Project/assets/130803554/b6d03f8f-c315-43c3-a9bd-6874de18c2da)

7. Input the expression.  

![image](https://github.com/andrewhuang2019/EECS348Project/assets/130803554/304b09e6-0570-4685-9658-1622abd638a2)  

8. The program will return an output.  

![image](https://github.com/andrewhuang2019/EECS348Project/assets/130803554/5751e47d-20b4-4bfc-85a2-a0a80ee06283)

If you have any more questions or want a more in-depth explanation, reference the [User Manual](doc/UsersManual.pdf) (will prompt you to download the repository).
