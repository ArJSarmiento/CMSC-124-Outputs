#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int is_operator(char c)
{
   return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

int precedence(char c)
{
   if (c == '+' || c == '-')
   {
      return 1;
   }
   else if (c == '*' || c == '/' || c == '%')
   {
      return 2;
   }
   else
   {
      return 0;
   }
}

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

int main()
{
   char postfix[100] = "156 10 + 5 % 12 -";
   int result;

   result = evaluate_postfix(postfix);
   printf("The value of the postfix expression '%s' is %d\n", postfix, result);
   return 0;
}