#include <stdio.h>
#include<string.h>
#include<ctype.h>

#define size 100

char stack[size];                //GLOBAL Declaration of stack
char ifix[size],pfix[size];       //GLOBAL Declaration of infix and postfix array
int top = -1;                   //GLOBAL Declaration of top

int Push(char a)  // Function for PUSH operation
{
    stack[++top] = a;
    return 0;
}

char pop()        // Function for POP operation
{
    if(top == -1)
      return -1;
    else
      return stack[top--];
}

int priority(char a)
{
    if(a=='^') 
        return 3;           //highest priority of the exponential operator
    else if(a=='*'||a=='/')
        return 2 ;          // 2nd highest priority of the multiplication and division operator
    else if(a=='+'||a=='-')
        return  1;          // 2nd highest priority of the addition and substraction operator
    else 
        return 0;            //default case
}

void i_to_p(char ifix[size]) //function to convert infix operation to postfix operation
{
    char current,x;
    int i=0,k=0;

    Push('#');
    
    while((current=ifix[i++]) != '\0')
    {
        if(current == '(')
        {
            Push(current); //directly pushes '(' onto the stack
        }
        else if(isalnum(current))      //returns a non-zero integer if an argument passed to the function is an alphanumeric 
           {
              pfix[k++]=current;
           }
        else if(current == ')')
            {
                while(stack[top] != '(')
                    pfix[k++]=pop();
                x=pop();
            }
            else
            {
                while(priority(stack[top]) >= priority(current))     //if priority of infix element(current) is equal to or less than the the top element the top element gets poped onto the pfix[] array 
                    pfix[k++]=pop();
                Push(current);
            }
    }   //end of while loop
    
    while(stack[top] != '#')  // Pops from stack until empty
    {
        pfix[k++]=pop();
    }
    pfix[k]='\0';          // Makes postfix as valid string
    printf("\nThe converted POSTFIX Expression : %s",pfix);
    
}   //function to convert infix operation to postfix operation ends

void eval() 
{   
    int i=0,a,b;
    while(pfix[i]!='\0')                //while loop begins
    {
        if(isalpha(pfix[i]))
        {   
            getchar();
            printf("\n \nEnter %c :",pfix[i]);
            scanf("\n \n %c",&pfix[i]);
            Push(pfix[i]-'0');
        }
        else if(isdigit(pfix[i]))        //isdigit function to check is it a numeric digit or not
        {
            Push(pfix[i]-'0');
        }
        else 
        {   
            b=pop();
            a=pop();                //when we find an operator we pop() twice first pop() goes for 2nd operator and the 2nd pop() goes for the 1st operator
            if(pfix[i]=='+')
            Push(a+b);
            else if(pfix[i]=='-')
            Push(a-b);
            else if(pfix[i]=='*')
            Push(a*b);
            else if(pfix[i]=='/')
            Push(a/b);
            else if(pfix[i]=='^')
            Push(a^b);
        }
    i++;                                            //increment of iteration variable
    }
    	printf("\nAnswer is: %d",pop());             //display evaluated answer
}

int main()  // Main Program
{
 printf("Enter INFIX Expression : ");
    scanf("%s",ifix);
    i_to_p(ifix);
    eval();
   
    return 0;
}   // Main Program ends
