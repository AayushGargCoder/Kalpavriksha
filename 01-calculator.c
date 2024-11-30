#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX 101
// use typedef  so that no write to use struct everytime while creating stack structure
typedef struct
{
    int data[MAX];
    int topIndex;
} Stack;

// Handler function terminate program when encounter with error and also print error Message
void Error(const char *msg)
{
    printf("%s", msg);
    exit(1);
}

void push(Stack *stack, int value)
{
    if (stack->topIndex == MAX - 1)
        Error("Expression is Too long");
    stack->data[++(stack->topIndex)] = value;
}

int pop(Stack *stack) { return stack->data[(stack->topIndex)--]; }

int top(Stack *stack) { return stack->data[stack->topIndex]; }

// This helper function use to determine operator precedence.
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    return 2;
}

int applyOperation(int a, int b, char op)
{
    if (op == '+')
        return a + b;
    if (op == '-')
        return a - b;
    if (op == '*')
        return a * b;
    if (op == '/')
    {
        if (b == 0)
            Error("Error:Division by zero");
        return a / b;
    }
}
char operatorsAllowed[] = "/*+-";

// This function check for invalid input like alphabest,special characters and return true if found
bool invalidInput(char inp)
{
    if (strchr(operatorsAllowed, inp) == NULL && !isdigit(inp))
        return true;
    return false;
}

// This function pop two operators and operand and evaluate
void evaluate(Stack *operands, Stack *operators)
{
    int b = pop(operands);
    int a = pop(operands);
    char op = pop(operators);
    push(operands, applyOperation(a, b, op));
}

int evaluateExpression(const char *expression)
{
    Stack operators, operands;
    operands.topIndex = operators.topIndex = -1;
    // expression always starts with an operand.
    bool operandTurn = true;
    int i = 0, n = strlen(expression);
    while (i < n)
    {
        if (isspace(expression[i]))
            i++;
        else if (invalidInput(expression[i]))
            Error("Error:Invalid Input");
        // If the input is a number,parse it to integer
        // if input->+3+4 and operandTurn is true but first input is operator, means input is invalid
        else if (isdigit(expression[i]) && operandTurn)
        {
            int value = 0;
            while (i < n && isdigit(expression[i]))
            {
                value = value * 10 + (expression[i] - '0');
                i++;
            }
            push(&operands, value);
            operandTurn = false;
        }
        // if the input is an operator
        else if (strchr(operatorsAllowed, expression[i]) != NULL && !operandTurn)
        {
            // if input->12++45 then after examine 12+ operantTurn=false and again when found + but operandTurn is true,means expression is invalid

            //  While top of operators has the same or greater precedence
            while (operators.topIndex != -1 && precedence(top(&operators)) >= precedence(expression[i]))
                evaluate(&operands, &operators);
            push(&operators, expression[i]);
            operandTurn = true;
            i++;
        }
        else
            Error("Error:Invalid Input");
    }
    // if the expression is valid , we always end up with operandTurn=false
    //  if the input->3+4+ then operandTurn is true,means expression is invalid
    if (operandTurn)
        Error("Error:Invalid Input");

    // Process remaining expression
    while (operators.topIndex != -1)
        evaluate(&operands, &operators);

    // Final result
    return pop(&operands);
}

int main()
{

    printf("Enter a mathematical expression : ");
    char expression[MAX];
    // fgets read upto newline or n-1 character read from standared input(keyboard) and store it into expression
    fgets(expression, MAX, stdin);
    // fgets read new Line char also,  so place null char there if found.
    // strcspn->find no of characters before \n,means provide index of \n.
    expression[strcspn(expression, "\n")] = '\0';
    int result = evaluateExpression(expression);
    printf("Result: %d\n", result);

    return 0;
}
