#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void infix_to_postfix(char *infix, char *postfix);
void description();
void instructions();
// void deallocate(char *infix, char *postfix);
void tokenize_input(char* input, char** tokens, int* num_tokens);

int main()
{
    int MAX = 100;
    char choice = '\0';
    char input_expr[MAX];
    char* tokens[MAX];
    char infix[MAX];
    char postfix[MAX];
    int num_tokens = 0;
    // char *infix = (char *)malloc(MAX * sizeof(char));
    // char *postfix = (char *)malloc(MAX * sizeof(char));

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
            tokenize_input(input_expr, tokens, &num_tokens);
            
            for (int i = 0; i < num_tokens; i++) 
            {
                // copy elements of tokens to infix
                strcat(infix, tokens[i]);
                printf("%s", tokens[i]);
            }
            infix_to_postfix(infix, postfix);
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
        "This program is a string compression/expansion program. It can compress and expand strings.\n");
    printf(
        "The program was developed by Sean Gabriel Bayron and Arnel Jan Sarmiento.\n");
    printf(
        "Arnel developed the original version of the program. Sean then modified the program to make it more efficient.\n");
}

void instructions()
{
    printf("\nWelcome to this Expression Evaluator program! Please choose an action to perform...\n");
    printf("[P] Program Description\n");
    printf("[E] Evaluate Expression(s)\n");
    printf("[X] Exit\n");
    printf("Choice: ");
}

int isoperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

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

void infix_to_postfix(char *infix, char *postfix)
{
    int i, j;
    char stack[100];
    int stack_top = -1;
    int infix_length = strlen(infix);

    for (i = 0, j = 0; i < infix_length; i++)
    {
        char current_char = infix[i];

        if (isspace(current_char))
        {
            // skip whitespace
            continue;
        }
        else if (isdigit(current_char))
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


// void deallocate(char *infix, char *postfix)
// {
//     if (infix != NULL) free(infix);
//     if (postfix != NULL) free(postfix);
// }

// define a function to determine operator precedence
// int precedence(char op) {
//     if (op == '*' || op == '/' || op == '%') {
//         return 2;
//     } else if (op == '+' || op == '-') {
//         return 1;
//     }
// }
// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>
// #include <string.h>

// #define MAX_EXPR_LENGTH 100

// int precedence(char op) {
//     int result = 0;
//     switch (op) {
//         case '*':
//         case '/':
//         case '%':
//             result = 2;
//             break;

//         case '+':
//         case '-':
//             result = 1;
//             break;

//         default:
//             break;
//     }

//     return result;
// }

// int main() {
//     char infix[MAX_EXPR_LENGTH];
//     char postfix[MAX_EXPR_LENGTH];
//     char stack[MAX_EXPR_LENGTH];
//     int stack_top = -1;
//     int infix_length, postfix_index = 0;

//     printf("Enter an infix expression: ");
//     fgets(infix, MAX_EXPR_LENGTH, stdin);
//     infix_length = strlen(infix);

//     // convert infix to postfix
//     for (int i = 0; i < infix_length; i++) {
//         char current_char = infix[i];

//         if (isdigit(current_char)) {
//             // append digits directly to postfix expression
//             while (isdigit(infix[i])) {
//                 postfix[postfix_index++] = infix[i++];
//             }
//             postfix[postfix_index++] = ' ';
//             i--; // back up one character since we advanced one too far
//         } else if (isspace(current_char)) {
//             // skip whitespace
//             continue;
//         } else if (current_char == '+' || current_char == '-' || current_char == '*' || current_char == '/' || current_char == '%') {

//             // pop operators with higher or equal precedence from stack
//             while (stack_top >= 0 && stack[stack_top] != '(' && precedence(stack[stack_top]) >= precedence(current_char)) {

//                 postfix[postfix_index++] = stack[stack_top--];
//                 postfix[postfix_index++] = ' ';
//             }

//             // push current operator onto stack
//             stack[++stack_top] = current_char;
//         } else if (current_char == '(') {
//             // push left parenthesis onto stack
//             stack[++stack_top] = current_char;
//         } else if (current_char == ')') {
//             // pop operators until left parenthesis is found
//             while (stack_top >= 0 && stack[stack_top] != '(') {

//                 postfix[postfix_index++] = stack[stack_top--];
//                 postfix[postfix_index++] = ' ';
//             }
//             if (stack_top < 0) {
//                 printf("Error: Mismatched parentheses in infix expression\n");
//                 return 1;
//             }
//             // discard left parenthesis
//             stack_top--;
//         } else {
//             // invalid character
//             printf("Error: Invalid character '%c' in infix expression\n", current_char);
//             return 1;
//         }
//     }

//     // append remaining operators from stack to postfix expression
//     while (stack_top >= 0) {
//         if (stack[stack_top] == '(' || stack[stack_top] == ')') {
//             printf("Error: Mismatched parentheses in infix expression\n");
//             return 1;
//         }
//         postfix[postfix_index++] = stack[stack_top--];
//         postfix[postfix_index++] = ' ';
//     }

//     // terminate postfix expression with null character
//     postfix[postfix_index] = '\0';

//     printf("Postfix expression: %s\n", postfix);

//     return 0;
// }
