#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 101
char operatorsAllowed[] = "/*+-";
char expression[MAX];
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

char *findElement(char inp)
{
    for (size_t i = 0; i < 4; i++)
    {
        if (operatorsAllowed[i] == inp)
            return operatorsAllowed + i;
    }
}
bool isDigit(char inp)
{
    return (inp >= '0' && inp <= '9');
}
// This function check for invalid input like alphabest,special characters and return true if found
bool invalidInput(char inp)
{
    if (findElement(inp) != NULL || isDigit(inp))
        return false;
    return true;
}

// This function pop two operators and operand and evaluate
void evaluate(Stack *operands, Stack *operators)
{
    int b = pop(operands);
    int a = pop(operands);
    char op = pop(operators);
    push(operands, applyOperation(a, b, op));
}

size_t strlen(const char *str)
{
    size_t len = 0;
    while (str[len] != '\0')
        len++;
    return len;
}

int evaluateExpression()
{
    Stack operators, operands;
    operands.topIndex = operators.topIndex = -1;
    // expression always starts with an operand.
    bool operandTurn = true;
    int currPos = 0;
    size_t expressionLen = strlen(expression);
    while (currPos < expressionLen)
    {
        if (expression[currPos] == ' ')
            currPos++;
        else if (invalidInput(expression[currPos]))
            Error("Error:Invalid Input");
        // If the input is a number,parse it to integer
        // if input->+3+4 and operandTurn is true but first input is operator, means input is invalid
        else if (isDigit(expression[currPos]) && operandTurn)
        {
            int value = 0;
            while (currPos < expressionLen && isDigit(expression[currPos]))
            {
                value = value * 10 + (expression[currPos] - '0');
                currPos++;
            }
            push(&operands, value);
            operandTurn = false;
        }
        // if the input is an operator
        else if (findElement(expression[currPos]) != NULL && !operandTurn)
        {
            // if input->12++45 then after examine 12+ operantTurn=false and again when found + but operandTurn is true,means expression is invalid

            //  While top of operators has the same or greater precedence
            while (operators.topIndex != -1 && precedence(top(&operators)) >= precedence(expression[currPos]))
                evaluate(&operands, &operators);
            push(&operators, expression[currPos]);
            operandTurn = true;
            currPos++;
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

void removeNewLine()
{
    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] == '\n')
        {
            expression[i] = '\0';
            return;
        }
    }
}

void takeInput()
{
    printf("Enter a mathematical expression : ");
    // fgets read upto newline or n-1 character read from standared input(keyboard) and store it into expression
    fgets(expression, MAX, stdin);
    // fgets read new Line char also,  so place null char there if found.
    removeNewLine();
}
int main()
{

    takeInput();
    int result = evaluateExpression();
    printf("Result: %d\n", result);

    return 0;
}
