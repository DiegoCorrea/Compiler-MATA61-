# Compiler a discipline from UFBA(Federal University of Bahia)  
### About  
Compiler writen in c/c++, to a small langague when is a mix from C and JS.  
  
### Inside the Compiler  

1. Lexical: Using Flex tool to generate a lexical approach  
2. Parser: Using Bison tool to verificate if the program is valid or not  
  

If you want configure the compiler, follow the steps:  
`sudo apt install flex`  
`sudo apt install bison`  
`sudo apt install gcc` 
`sudo apt install g++` 
  
Go to project folder and type:  
 * Just make the compiler: `make`  
 * Make and run test cases: `make run`  
   
Annotation: {fprintf\([^\)]*\);}