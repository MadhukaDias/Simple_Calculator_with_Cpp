#include <iostream>	//Header files.
#include <math.h>
#include <string>
#include "CalculatorHeader.h"
using namespace std;

void Bracketerror (int* y, int k)	//In this function, switch-case is used and the error will show according to the corresponidng value.
{
	switch (y[k])
	{
		case 1: cout<<"\nThe closing bracket of ')' does not exist.";break;
		case 2: cout<<"\nThe closing bracket of ']' does not exist.";break;
		case 3: cout<<"\nThe closing bracket of '}' does not exist.";break;
	}
}

//This is the function that check the parameters.
//The error will show for each error in the parameter if the parameter is incorrect.
bool Parameterscheck (string& input, int& charactercount)
{
	int count=0, x, k=0, Errorcount=0;
	// Calculate maximum possible bracket depth (input length / 2)
	int maxBracketDepth = (input.length() / 2) + 1;
	int* y = new int[maxBracketDepth];	//This array is for check the brackets - dynamic allocation
	y[k]=0;
	charactercount=0;
	
	if (input.empty())	//If there is no input.
	{
		cout<<"No input formula.";
		delete[] y;
		return false;
	}
	
	cout<<"Input:\n"<<input<<endl;	//Show the input that you entered.
	for (int i=0; i < input.length(); i++)
	{
		charactercount++;
		if (input[i]!='+' &&
			input[i]!='-' &&
			input[i]!='/' &&
			input[i]!='*' &&
			input[i]!='%' &&
			input[i]!='=' &&
			input[i]!='(' &&
			input[i]!='[' &&
			input[i]!='{' &&
			input[i]!=')' &&
			input[i]!=']' &&
			input[i]!='}' &&
			!isdigit(input[i]))
		{
			cout<<"\nOnly '+' , '-' , '*' , '/' , '%', '=', brackets and digits are allowed.";
			Errorcount++;
		}
		if (input[i]=='(')
		{
			k++;
			y[k]=1;
		}
		else if (input[i]=='[')
		{
			k++;
			y[k]=2;	
		}
		else if (input[i]=='{')
		{
			k++;
			y[k]=3;
		}
		if (input[i]==')')
		{
			if (i+1 < input.length() && input[i+1]!='+' &&
				input[i+1]!='-' &&
				input[i+1]!='*' &&
				input[i+1]!='/' &&
				input[i+1]!='%' &&
				input[i+1]!=')' &&
				input[i+1]!=']' &&
				input[i+1]!='}' &&
				input[i+1]!='=')
			{
				cout<<"\nThere should be a mathematical operation or a closing bracket after a closing bracket.";
				Errorcount++;
			}
			x=1;
			if (x==y[k])
			{
				k--;
			}
			else
			{
				Bracketerror (y, k);
				k--;
				Errorcount++;
			}
		}
		else if (input[i]==']')
		{
			if (i+1 < input.length() && input[i+1]!='+' &&
				input[i+1]!='-' &&
				input[i+1]!='*' &&
				input[i+1]!='/' &&
				input[i+1]!='%' &&
				input[i+1]!=')' &&
				input[i+1]!=']' &&
				input[i+1]!='}' &&
				input[i+1]!='=')
			{
				cout<<"\nThere should be a mathematical operation or a closing bracket after a closing bracket.";
				Errorcount++;
			}
			x=2;
			if (x==y[k])
			{
				k--;
			}
			else
			{
				Bracketerror (y, k);
				k--;
				Errorcount++;
			}
		}
		else if (input[i]=='}')
		{
			if (i+1 < input.length() && input[i+1]!='+' &&
				input[i+1]!='-' &&
				input[i+1]!='*' &&
				input[i+1]!='/' &&
				input[i+1]!='%' &&
				input[i+1]!=')' &&
				input[i+1]!=']' &&
				input[i+1]!='}' &&
				input[i+1]!='=')
			{
				cout<<"\nThere should be a mathematical operation or a closing bracket after a closing bracket.";
				Errorcount++;
			}
			x=3;
			if (x==y[k])
			{
				k--;
			}
			else
			{
				Bracketerror (y, k);
				k--;
				Errorcount++;
			}
		}
		if (input[i]=='=')
		{
			count++;
			if (i+1 < input.length())
			{
				cout<<"\nThe formula does not end with an equal sign.";
				Errorcount++;
			}
		}
		if (input[i]=='+' ||
			input[i]=='-' ||
			input[i]=='*' ||
			input[i]=='/' ||
			input[i]=='%')
		{
			if (i+1 < input.length() && (input[i+1]=='+' ||
			input[i+1]=='-' ||
			input[i+1]=='*' ||
			input[i+1]=='/' ||
			input[i+1]=='%'))
			{
				cout<<"\nTwo mathematical operations can't be placed next to each other.";
				Errorcount++;
			}
		}
	}
	if (k>0)		//If closing brackets are more than open brackets.
	{
		cout<<"\nThe closing bracket(s) do/does not exist.";
		Errorcount++;
	}
	else if (k<0)	//If open brackets are more than closing brackets.
	{
		cout<<"\nClosing bracket(s) exist(s) without open bracket.";
		Errorcount++;
	}
	if (count==0)	//If input has no '=' sign.
	{
		cout<<"\nThe formula does not have an equal sign.";
		Errorcount++;
	}
	else if (count>1)	//If input has more than one '=' sign.
	{
		cout<<"\nToo many equal signs.";
		Errorcount++;
	}	if (charactercount>1000)  // Increased limit for longer expressions
	{
		cout<<"\nInput is too long.";
		Errorcount++;
	}
	
	delete[] y;
	if (Errorcount==0)	//If the input is correct, return true.
	{
		return true;
	}
	else	//If the input is incorrect, return false.
	{
		return false;
	}
}

void Characterseparation(string& input, const int& RealSize, char* formularcharacters, float* formularnumbers)	//This is where the characters will separate.
{
	float number;
	int Realcharactercount = 0;
	for (int i=0, q=0; i < input.length() && input[i]!='=' && i<RealSize && q<RealSize-2; i++, q++)
	{
		if (isdigit(input[i]))	//If the character is digit...
		{
			number=(input[i]-'0');	//Convert it to float.
			formularcharacters[q]=':';
			for (i++; i<RealSize && i < input.length(); i++)
			{
				if (isdigit(input[i]))
				{
					number= number*10+(input[i]-'0');	//If there are more than one digit after the previous one, all of them get as a single number.
					if (i < RealSize) formularnumbers[i]=1.2;
				}
				else
				{
					if (i < RealSize) formularnumbers[i]=1.2;	//Else, avoid the second for loop.
					formularnumbers[q]=number;
					i--;
					break;
				}
			}
		}
		else if (input[i]=='(' || input[i]=='[' || input[i]=='{')	//If it is a '(', '[' or '{', assign that as a '('.
		{
			formularcharacters[q]='(';
			formularnumbers[q]=1.2;
		}
		else if (input[i]==')' || input[i]==']' || input[i]=='}')	//If it is a ')', ']' or '}', assign that as a ')'.
		{
			formularcharacters[q]=')';
			formularnumbers[q]=1.2;
		}
		else	//If the character is anything else of them, normally assign it.
		{
			formularcharacters[q]=input[i];
			formularnumbers[q]=1.2;
		}
		Realcharactercount=q;
	}
	//Here, the arrays will end with below characters.
	if (Realcharactercount+2 < RealSize)
	{
		Realcharactercount=Realcharactercount+1;
		formularcharacters[Realcharactercount]='=';
		formularcharacters[Realcharactercount+1]='\0';
		formularnumbers[Realcharactercount]=1.2;
		formularnumbers[Realcharactercount+1]='\0';
	}
}

float execution(char* formularcharacters, float* formularnumbers, int* openindex, int b, bool& error) //This is where the calculation part happens.
{
	float ans=0.0f;	//Initially, the answer is 0.
	//According to each statement the calculation will happen.
	//Here, 4 for-loops are used to do the simplification in BODMAS order.
	//If there is an error in Remainder or Division, bool error becomes true.
	if (((formularcharacters[0]=='%') && formularcharacters[1]=='=') ||
		((formularcharacters[0]=='%') && formularcharacters[1]==':' && formularnumbers[1]==0))
	{
		cout<<"\nRemainder execution error!\nDenominator is 0!";
		error=true;
		return 111;
	}
	else if (((formularcharacters[0]=='/') && formularcharacters[1]=='=') ||
			 ((formularcharacters[0]=='/') && formularcharacters[1]==':' && formularnumbers[1]==0))
	{
		cout<<"\nDivision execution error!\nDenominator is 0!";
		error=true;
		return 111;
	}
	if ((formularcharacters[0]=='*' || formularcharacters[0]=='+' || formularcharacters[0]=='-') && formularcharacters[1]=='=')
	{
		return 0;
	}
	if ((formularcharacters[0]=='%' || formularcharacters[0]=='/') && formularcharacters[1]==':' && formularnumbers[1]!=0)
	{
		formularcharacters[0]=':';
		formularnumbers[0]=0.0f;
		for (int g=1; formularcharacters[g]!='\0'; g++)
		{
			formularcharacters[g]=formularcharacters[g+1];
			formularnumbers[g]=formularnumbers[g+1];
		}
	}
	else if (formularcharacters[0]=='+' && formularcharacters[1]==':')
	{
		for (int g=0; formularcharacters[g]!='\0'; g++)
		{
			formularcharacters[g]=formularcharacters[g+1];
			formularnumbers[g]=formularnumbers[g+1];
		}
	}
	else if (formularcharacters[0]=='-' && formularcharacters[1]==':')
	{
		formularcharacters[0]=':';
		formularnumbers[0]=0-formularnumbers[1];
		for (int g=1; formularcharacters[g]!='\0'; g++)
		{
			formularcharacters[g]=formularcharacters[g+1];
			formularnumbers[g]=formularnumbers[g+1];
		}
	}
	for (int i=openindex[b]+1; formularcharacters[i]!=')' && formularcharacters[i]!='='; i++)
	{
		if (formularcharacters[i]=='%')
		{
			if (formularcharacters[i-1]==':' && formularcharacters[i+1]==':' && formularnumbers[i+1]!=0)
			{
				ans=(fmod(formularnumbers[i-1],formularnumbers[i+1]));
				formularcharacters[i-1]=':';
				formularnumbers[i-1]=ans;
				for (int g=i; formularcharacters[g]!='\0'; g++)
				{
					formularcharacters[g]=formularcharacters[g+2];
					formularnumbers[g]=formularnumbers[g+2];
				}
			}
			else if ((formularcharacters[i-1]=='(' && formularcharacters[i+1]==':') && formularnumbers[i+1]!=0)
			{
				ans=0;
				formularcharacters[i]=':';
				formularnumbers[i]=ans;
				for (int g=i+1; formularcharacters[g]!='\0'; g++)
				{
					formularcharacters[g]=formularcharacters[g+1];
					formularnumbers[g]=formularnumbers[g+1];
				}
			}
			else if (((formularcharacters[i+1]=='=') || (formularcharacters[i-1]==':' && formularcharacters[i+1]==':' && formularnumbers[i+1]==0)) ||
					 ((formularcharacters[i+1]==')') && (formularcharacters[i-1]=='(')) ||
					 ((formularcharacters[i-1]=='(' && formularcharacters[i+1]==':') && formularnumbers[i+1]==0))
			{
				cout<<"\nRemainder execution error!\nDenominator is 0!";
				error=true;
				return 111;
			}
			i--;
		}
	}
	for (int i=openindex[b]+1; formularcharacters[i]!=')' && formularcharacters[i]!='='; i++)
	{
		if (formularcharacters[i]=='/')
		{
			if (formularcharacters[i-1]==':' && formularcharacters[i+1]==':' && formularnumbers[i+1]!=0)
			{
				ans=(formularnumbers[i-1]/formularnumbers[i+1]);
				formularcharacters[i-1]=':';
				formularnumbers[i-1]=ans;
				for (int g=i; formularcharacters[g]!='\0'; g++)
				{
					formularcharacters[g]=formularcharacters[g+2];
					formularnumbers[g]=formularnumbers[g+2];
				}
			}
			else if ((formularcharacters[i-1]=='(' && formularcharacters[i+1]==':') && formularnumbers[i+1]!=0)
			{
				ans=0;
				formularcharacters[i]=':';
				formularnumbers[i]=ans;
				for (int g=i+1; formularcharacters[g]!='\0'; g++)
				{
					formularcharacters[g]=formularcharacters[g+1];
					formularnumbers[g]=formularnumbers[g+1];
				}
			}
			else if (((formularcharacters[i+1]=='=') || (formularcharacters[i-1]==':' && formularcharacters[i+1]==':' && formularnumbers[i+1]==0)) ||
					 ((formularcharacters[i+1]==')') || (formularcharacters[i-1]=='(')) ||
					 ((formularcharacters[i-1]=='(' && formularcharacters[i+1]==':') && formularnumbers[i+1]==0))
			{
				cout<<"\nDivision execution error!\nDenominator is 0!";
				error=true;
				return 111;
			}
			i--;
		}
	}
	for (int i=openindex[b]+1; formularcharacters[i]!=')' && formularcharacters[i]!='='; i++)
	{
		if (formularcharacters[i]=='*')
		{
			if (formularcharacters[i-1]==':' && formularcharacters[i+1]==':')
			{
				ans=(formularnumbers[i-1]*formularnumbers[i+1]);
				formularcharacters[i-1]=':';
				formularnumbers[i-1]=ans;
				for (int g=i; formularcharacters[g]!='\0'; g++)
				{
					formularcharacters[g]=formularcharacters[g+2];
					formularnumbers[g]=formularnumbers[g+2];
				}
			}
			else if (formularcharacters[i+1]=='=')
			{
				formularcharacters[i+1]=':';
				formularcharacters[i+2]='=';
				formularcharacters[i+3]='\0';
				formularnumbers[i+1]=0.0f;
				formularnumbers[i+2]=1.2;
				formularnumbers[i+3]='\0';
			}
			else if (formularcharacters[i-1]=='(' && formularcharacters[i+1]==')')
			{
				ans=0;
				formularcharacters[i]=':';
				formularnumbers[i]=ans;
			}
			else if (formularcharacters[i-1]=='(' && formularcharacters[i+1]==':')
			{
				ans=0;
				formularcharacters[i]=':';
				formularnumbers[i]=ans;
				for (int g=i+1; formularcharacters[g]!='\0'; g++)
				{
					formularcharacters[g]=formularcharacters[g+1];
					formularnumbers[g]=formularnumbers[g+1];
				}
			}
			else if (formularcharacters[i-1]==':' && formularcharacters[i+1]==')')
			{
				ans=0;
				formularcharacters[i-1]=':';
				formularnumbers[i-1]=ans;
				for (int g=i; formularcharacters[i]!='\0'; g++)
				{
					formularcharacters[g]=formularcharacters[g+1];
					formularnumbers[g]=formularnumbers[g+1];
				}
			}
			i--;
		}
	}
	for (int i=openindex[b]+1; formularcharacters[i]!=')' && formularcharacters[i]!='='; i++)
	{
		if (formularcharacters[i]=='+')
		{
			if (formularcharacters[i-1]==':' && formularcharacters[i+1]==':')
			{
				ans=(formularnumbers[i-1]+formularnumbers[i+1]);
				formularcharacters[i-1]=':';
				formularnumbers[i-1]=ans;
				for (int g=i; formularcharacters[g]!='\0'; g++)
				{
					formularcharacters[g]=formularcharacters[g+2];
					formularnumbers[g]=formularnumbers[g+2];
				}
			}
			else if (formularcharacters[i+1]=='=')
			{
				formularcharacters[i]='=';
				formularcharacters[i+1]='\0';
				formularnumbers[i]=1.2;
				formularnumbers[i+1]='\0';
			}
			else if (formularcharacters[i-1]=='(' && formularcharacters[i+1]==')')
			{
				ans=0;
				formularcharacters[i]=':';
				formularnumbers[i]=ans;
			}
			else if (formularcharacters[i-1]=='(' && formularcharacters[i+1]==':')
			{
				ans=(0+formularnumbers[i+1]);
				formularcharacters[i]=':';
				formularnumbers[i]=ans;
				for (int g=i+1; formularcharacters[g]!='\0'; g++)
				{
					formularcharacters[g]=formularcharacters[g+1];
					formularnumbers[g]=formularnumbers[g+1];
				}
			}
			else if (formularcharacters[i-1]==':' && formularcharacters[i+1]==')')
			{
				ans=(formularnumbers[i-1]+0);
				formularcharacters[i-1]=':';
				formularnumbers[i-1]=ans;
				for (int g=i; formularcharacters[i]!='\0'; g++)
				{
					formularcharacters[g]=formularcharacters[g+1];
					formularnumbers[g]=formularnumbers[g+1];
				}
			}
			i--;
		}
		else if (formularcharacters[i]=='-')
		{
			if (formularcharacters[i-1]==':' && formularcharacters[i+1]==':')
			{
				ans=(formularnumbers[i-1]-formularnumbers[i+1]);
				formularcharacters[i-1]=':';
				formularnumbers[i-1]=ans;
				for (int g=i; formularcharacters[g]!='\0'; g++)
				{
					formularcharacters[g]=formularcharacters[g+2];
					formularnumbers[g]=formularnumbers[g+2];
				}
			}
			else if (formularcharacters[i+1]=='=')
			{
				formularcharacters[i]='=';
				formularcharacters[i+1]='\0';
				formularnumbers[i]=1.2;
				formularnumbers[i+1]='\0';
			}
			else if (formularcharacters[i-1]=='(' && formularcharacters[i+1]==')')
			{
				ans=0;
				formularcharacters[i]=':';
				formularnumbers[i]=ans;
			}
			else if (formularcharacters[i-1]=='(' && formularcharacters[i+1]==':')
			{
				ans=(0-formularnumbers[i+1]);
				formularcharacters[i]=':';
				formularnumbers[i]=ans;
				for (int g=i+1; formularcharacters[g]!='\0'; g++)
				{
					formularcharacters[g]=formularcharacters[g+1];
					formularnumbers[g]=formularnumbers[g+1];
				}
			}
			else if (formularcharacters[i-1]==':' && formularcharacters[i+1]==')')
			{
				ans=(formularnumbers[i-1]-0);
				formularcharacters[i-1]=':';
				formularnumbers[i-1]=ans;
				for (int g=i; formularcharacters[i]!='\0'; g++)
				{
					formularcharacters[g]=formularcharacters[g+1];
					formularnumbers[g]=formularnumbers[g+1];
				}
			}
			i--;
		}
	}
	if (formularcharacters[openindex[b]+1]==':')
	{
		ans=formularnumbers[openindex[b]+1];
	}
	else if (ans=='\0' || ans==0)
	{
		return 0.0f;
	}
	return ans;
}

void inbracketsimplifier(char* formularcharacters, float* formularnumbers, int* openindex, int& b, bool& error)	//This is where brackets are getting to simplify.
{
	float x;
	for (int c=0; formularcharacters[c]!='\0'; c++)
	{
		if (formularcharacters[c]=='(')	//Save the index of the latest open bracket.
		{
			b++;
			openindex[b]=c;
		}
		//In below statement, the execution function will call and do the simplification within the brackets.
		//Also, the loop will start from the index of the latest open bracket again until all the brackets are simplified.
		if (formularcharacters[c]==')')
		{
			if (formularcharacters[c-1]=='(')
			{
				formularcharacters[c-1]=':';
				formularnumbers[c-1]=0.0f;
				for (int g=c; formularcharacters[g]!='\0'; g++)
				{
					formularcharacters[g]=formularcharacters[g+1];
					formularnumbers[g]=formularnumbers[g+1];
				}
			}
			else
			{
				x= execution(formularcharacters, formularnumbers, openindex, b, error);
				if (error)
				{
					break;
				}
				formularcharacters[openindex[b]]=':';
				formularnumbers[openindex[b]]=x;
				for (int g=openindex[b]+1; formularcharacters[g]!='\0'; g++)
				{
					formularcharacters[g]=formularcharacters[g+2];
					formularnumbers[g]=formularnumbers[g+2];
				}
			}
			b--;
			c=openindex[b];
		}
	}
}

float normalsimplifier(char* formularcharacters, float* formularnumbers, int* openindex, int& b, bool& error)	//Calculation outside the brackets.
{
	float d;
	d=execution(formularcharacters, formularnumbers, openindex, b, error);	//The execution function will call in here too.
	return d;
}

float formularprocessor(string& input, bool& error)
{
    int charactercount;
    if (Parameterscheck(input, charactercount))	//Call this function to check the parameters.
    {
        cout<<"\nParameter Check - Passed\n-------------------------------------------------------------------------------"<<endl;
        if (input[0]=='=')
        {
            return 0;
        }
        
        // Calculate array sizes dynamically based on input length
        const int RealSize = charactercount + 10; // Extra buffer for safety
        const int maxDepth = (charactercount / 2) + 5; // Maximum bracket depth

        // Use dynamic memory allocation with calculated sizes
        int* openindex = new int[maxDepth];
        int b=0;
        openindex[0]=-1;
        float* formularnumbers = new float[RealSize];
        char* formularcharacters = new char[RealSize];

        // Initialize arrays
        for(int i = 0; i < RealSize; i++) {
            formularnumbers[i] = 0.0f;
            formularcharacters[i] = '\0';
        }
        for(int i = 0; i < maxDepth; i++) {
            openindex[i] = -1;
        }

        Characterseparation(input, RealSize, formularcharacters, formularnumbers);
        if (formularcharacters[0]==':' && formularcharacters[1]=='=')
        {
            float result = formularnumbers[0];
            delete[] openindex;
            delete[] formularnumbers;
            delete[] formularcharacters;
            return result;
        }
        inbracketsimplifier(formularcharacters, formularnumbers, openindex, b, error);
        if (error)
        {
            cout<<"\n-------------------------------------------------------------------------------\nExecution - Failed"<<endl;
            delete[] openindex;
            delete[] formularnumbers;
            delete[] formularcharacters;
            return 111;
        }
        else
        {
            float f = normalsimplifier(formularcharacters, formularnumbers, openindex, b, error);
            if (error)
            {
                cout<<"\n-------------------------------------------------------------------------------\nExecution - Failed"<<endl;
                delete[] openindex;
                delete[] formularnumbers;
                delete[] formularcharacters;
                return 111;
            }
            else
            {
                cout<<"\nExecution - Passed\n-------------------------------------------------------------------------------"<<endl;
                delete[] openindex;
                delete[] formularnumbers;
                delete[] formularcharacters;
                if (f==-0 || f==+0)
                {
                    return 0;
                }
                else
                {
                    return f;
                }
            }
        }
    }
    else
    {
        error=true;
        cout<<"\n-------------------------------------------------------------------------------\nParameter Check - Failed"<<endl;
        return 111;
    }
}

int runCalculator()
{
    bool error = false;
    string userInput;
    
    cout << "\n***********************************SIMPLE CALCULATOR***********************************\n\n";
    cout << "Enter a mathematical expression ending with '=' (e.g., 2+3*4=): ";
    getline(cin, userInput);
    
    if (userInput.empty()) {
        cout << "No input provided." << endl;
        return 1;
    }
    
    float result = formularprocessor(userInput, error);
    
    if (error) {
        return 1;
    } else {
        cout << "\nAnswer:\n" << result << endl;
        return 0;
    }
}
