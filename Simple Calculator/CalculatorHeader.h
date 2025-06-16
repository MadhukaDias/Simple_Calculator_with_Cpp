#define CALCULATOR_H
#include <string>

bool Parameterscheck (std::string&, int&);	//The function for check the parameters.
void Bracketerror (int*, int);	//The function that will show the error for wrong bracket placement.
void Characterseparation(std::string&, const int&, char*, float*);	//This function will separate the numbers and other characters of the parameter to each arrays.
float execution(char*, float*, int*, int, bool&);	//This is the function where the calculation part happens.
void inbracketsimplifier(char*, float*, int*, int&, bool&);	//The function will help to simplify the brackets if they exist.
float normalsimplifier(char*, float*, int*, int&, bool&);	//The function will help to do the operation after all the brackets are simplified.
float formularprocessor(std::string&, bool&);	//This is the function which is holding Characterseparation, inbracketsimplifier and normalsimplifier functions.
int runCalculator();	//Main function to run calculator with user input