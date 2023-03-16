#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void infix_to_postfix(char *infix, char *postfix);
void description();
void instructions();
int evaluate_postfix(char* postfix);

int main()
{
   char choice;
   char infix[100];
   char postfix[100];
   int result = 0;

   while (choice != 'X' && choice != 'x')
   {
      instructions();

      choice = getchar();

      switch (choice)
      {
      case 'P':
      case 'p':
         description();
         break;
      case 'E':
      case 'e':
         printf("\nEnter a string to evaluate: ");
         scanf("%s", infix);

         infix_to_postfix(infix, postfix);
         printf("Postfix expression: %s\n", postfix);

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

      while ((getchar()) != '\n')
         ;
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
int is_operator(char c)
{
   return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

/*
   Returns the precedence of an operator
*/
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

/*
   Converts an infix expression to its equivalent postfix expression
*/
void infix_to_postfix(char *infix, char *postfix)
{
   int MAX_LEN = 100;
   int i, j;
   char op_stack[MAX_LEN];
   int op_top = -1;

   for (i = 0, j = 0; infix[i] != '\0'; i++)
   {
      if (isdigit(infix[i]))
      {
         postfix[j++] = infix[i];
      }
      else if (is_operator(infix[i]))
      {
         while (op_top != -1 && is_operator(op_stack[op_top]) &&
                precedence(op_stack[op_top]) >= precedence(infix[i]))
         {
            postfix[j++] = op_stack[op_top--];
         }
         op_stack[++op_top] = infix[i];
      }
      else if (infix[i] == '(')
      {
         op_stack[++op_top] = infix[i];
      }
      else if (infix[i] == ')')
      {
         while (op_top != -1 && op_stack[op_top] != '(')
         {
            postfix[j++] = op_stack[op_top--];
         }
         if (op_top == -1) {
            printf("Error: Mismatched parentheses!\n");
            exit(1);
         }
         op_top--;
      }
      else
      {
         printf("Error: Invalid character '%c' in infix expression!\n", infix[i]);
         return;
      }
   }

   while (op_top != -1)
   {
      if (op_stack[op_top] == '(')
      {
         printf("Error: Mismatched parentheses!\n");
         return;
      }
      postfix[j++] = op_stack[op_top--];
   }

   postfix[j] = '\0';
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
