//Program to check if an expression is balanced or not
#include <stdio.h>
#include <strings.h>

int top = -1;
int MAX = 20; //both varibales can be used without initiating in main program.

char push(char *arr,char n) //adds elment to the stack
{
    if (top == MAX-1)
    {   
        printf("Error: Stack Overflow, %d cannot be added. \n", n);
        return n;
    }

    top++;
    arr[top] = n;
    return n;
}

char pop(char *arr) //removes top most element in a stack
{
    if (top == -1)
    {
        printf("Error: Stack Underflow, element can't be removed.");
        return 0;
    }
    return arr[top--];
}

int size(char *arr) //returns MAX of the stack
{
    return top+1;
}

int isEmpty(char *arr) //checks if the stack is empty or not
{
    if (top == -1)
        return 1;

    return 0;
}

int isFull(char *arr) //checks if the stack is full or not
{
    if (top == MAX-1)
        return 1;

    return 0;
}

int display(char *arr) //displays the stack
{
    for (int i = 0; i <= top; i++)
    {
        printf("%c", arr[i]);
        printf(" ");
    }
}


int isbracketmatch(char a, char b)
{
    if (a == '(' && b == ')')
        return 1;

    else if (a == '[' && b == ']')
        return 1;

    else if (a == '{' && b == '}')
        return 1;
    
    else if (a == '<' && b == '>')
        return 1;
    
    else
        return 0;

}

int main(){
    
    char mystack[MAX];
    char expr[MAX];

    printf("Enter expression: ");
    gets(expr);

    for (int i = 0; i < MAX; i++ )
    {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[' || expr[i] == '<')
        {
            push(mystack, expr[i]);
        }

        if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']' || expr[i] == '>')
        {
                if (isEmpty(mystack) == 1)
                {
                    printf("The expression is imbalanced");
                    return 0;
                }

                else
                {
                    char temp = pop(mystack);

                    if (isbracketmatch(temp, expr[i]) == 0)
                    {
                        printf("The expression is imbalanced");
                        return 0;
                    }
                }
        }

    }

    if (isEmpty(mystack) == 1)
    {
        printf("The expression is balanced");
    }

    else
    {
        printf("The expression is imbalanced");
    }    
    return 0;
}