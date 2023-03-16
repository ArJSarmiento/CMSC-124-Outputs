#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void infix_to_postfix(char *infix, char *postfix);
void description();
void instructions();
void tokenize_input(char* input, char** tokens, int* num_tokens);
int evaluate_postfix(char* postfix);

int main()
{
    int MAX = 100;
    char choice = '\0';
    char input_expr[MAX];
    char* tokens[MAX];
    char infix[MAX];
    char postfix[MAX];
    int num_tokens = 0;
   int result = 0;

    while (choice != 'X' && choice != 'x')
    {
        instructions();

        choice = getchar();
        getchar();

        switch (choice)
        {
        case 'P':
        case 'p':
            description();
            break;
        case 'E':
        case 'e':
            printf("\nEnter a string to evaluate: ");
            fgets(input_expr, MAX, stdin);
            
            for (int i=0; i<MAX; i++) {
                tokens[i] = malloc(20 * sizeof(char));
            }
            // tokenize_input(input_expr, tokens, &num_tokens);
            
            for (int i = 0; i < num_tokens; i++) 
            {
                // strcat(infix, tokens[i]);
                printf("%c", input_expr[i]);
            }
            // infix_to_postfix(infix, postfix);

            result = evaluate_postfix(postfix);
            printf("Result: %d\n", result);
            break;
        case 'X':
        case 'x':
            printf("\nExiting program...\n");
            exit(0);
            break;
        default:
            printf("\nInvalid input\n");
            break;
        }
    }
    return 0;
}

void description()
{
   printf("\nName: Sean Gabriel Bayron\n");
   printf("Student Number: 2021-04354\n");
   printf("Name: Arnel Jan Sarmiento\n");
   printf("Student Number: 2021-05094\n");
   printf("Date: 2023-3-05\n");
   printf(
       "This program converts a given infix expression to its equivalent postfix expression and then evaluate the expression.\n");
   printf(
       "The program was developed by Sean Gabriel Bayron and Arnel Jan Sarmiento.\n");
   printf(
       "Sean developed the original version of the program. Arnel then modified the program to make it more efficient.\n");
   printf(
       "Sean also implemented the infix to postfix conversion while Arnel implemented the postfix evaluation.\n");
}

/*
    Prints program instructions
*/
void instructions()
{
    printf("\nWelcome to this Expression Evaluator program! Please choose an action to perform...\n");
    printf("[P] Program Description\n");
    printf("[E] Evaluate Expression(s)\n");
    printf("[X] Exit\n");
    printf("Choice: ");
}

/*
   Tells if a token is an operator
*/
int isoperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

/*
   Returns the precedence of an operator
*/
int precedence(char c)
{
    switch (c)
    {
    case '*':
    case '/':
    case '%':
        return 2;

    case '+':
    case '-':
        return 1;

    default:
        return 0;
    }
    return 0;
}




/*
   Converts an infix expression to its equivalent postfix expression
*/
void infix_to_postfix(char *infix, char *postfix)
{
    int i, j;
    char stack[100];
    int stack_top = -1;
    int infix_length = strlen(infix);

    for (i = 0, j = 0; i < infix_length; i++)
    {
        char current_char = infix[i];

        // if (isspace(current_char))
        // {
        //     // skip whitespace
        //     continue;
        // }
        if (isdigit(current_char))
        {
            // append digits directly to postfix expression
            while (isdigit(infix[i]))
            {
                postfix[j++] = infix[i++];
            }
            i--; // back up one character since we advanced one too far
        }
        else if (isoperator(current_char))
        {
            postfix[j++] = ' ';
            // pop operators with higher or equal precedence from stack
            while (stack_top >= 0 && stack[stack_top] != '(' && precedence(stack[stack_top]) >= precedence(current_char))
            {
                postfix[j++] = stack[stack_top--];
                postfix[j++] = ' ';
            }

            // push current operator onto stack
            stack[++stack_top] = current_char;
        }
        else if (current_char == '(')
        {
            // push left parenthesis onto stack
            stack[++stack_top] = current_char;
        }
        else if (current_char == ')')
        {
            // pop operators until left parenthesis is found
            while (stack_top >= 0 && stack[stack_top] != '(')
            {

                postfix[j++] = ' ';
                postfix[j++] = stack[stack_top--];
            }
            if (stack_top < 0)
            {
                goto errorParentheses;
            }
            // discard left parenthesis
            stack_top--;
        }
        else
        {
        // invalid character
        // errorChar:
            printf("Error: Invalid character '%c' in infix expression\n", current_char);
            // deallocate(infix, postfix);

            return;
        }
    }
    // append remaining operators from stack to postfix expression
    while (stack_top >= 0)
    {
        if (stack[stack_top] == '(' || stack[stack_top] == ')')
        {
        errorParentheses:
            printf("Error: Mismatched parentheses in infix expression\n");
            // deallocate(infix, postfix);
            return;
        }
        postfix[j++] = ' ';
        postfix[j++] = stack[stack_top--];
    }

    // terminate postfix expression with null character
    postfix[j] = '\0';
    printf("Postfix expression: %s\n", postfix);
    // deallocate(infix, postfix);
}

void tokenize_input(char* input, char** tokens, int* num_tokens)
{
    char* delim = " \n";
    char* token = strtok(input, delim);
    int i = 0;
    while (token != NULL) {
        // check if token is a number or operator
        if (isdigit(token[0]) || strchr("+-*/%()", token[0])) {
            // check if previous token was a number
            if (i > 0 && isdigit(tokens[i-1][strlen(tokens[i-1])-1]) && isdigit(token[0])) {
                // concatenate numbers without space
                strcat(tokens[i-1], token);
            } else {
                // add token with space
                strcpy(tokens[i], token);
                i++;
            }
        }
        token = strtok(NULL, delim);
    }
    *num_tokens = i;
}

/*
   Evaluates a postfix expression
*/
int evaluate_postfix(char* postfix) {
    int stack[100]; 
    int top = -1; // initialize stack top index to -1
    char* token = strtok(postfix, " "); // tokenize the string by spaces
    while (token != NULL) {
        if (isdigit(token[0])) {
            // if token is a number, convert it to an integer and push it onto the stack
            int num = atoi(token);
            stack[++top] = num;
        } else {
            // if token is an operator, pop the top two elements from the stack
            // perform the operation and push the result onto the stack
            int op2 = stack[top--];
            int op1 = stack[top--];
            switch (token[0]) {
                case '+': stack[++top] = op1 + op2; break;
                case '-': stack[++top] = op1 - op2; break;
                case '*': stack[++top] = op1 * op2; break;
                case '/': stack[++top] = op1 / op2; break;
                case '%': stack[++top] = op1 % op2; break;
            }
        }
        token = strtok(NULL, " "); // get next token
    }
    return stack[top]; // the final result will be on top of the stack
}
