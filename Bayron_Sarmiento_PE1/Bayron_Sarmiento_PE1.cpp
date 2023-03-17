#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstring>

using namespace std;

// prototypes
char choice_validation(string input);
char is_operator(char c);
string remove_space(string str);
void calculate(const char *infix, char *postfix);
int evaluate_postfix(char *postfix);
void description();
void instructions();
void input_validation(string &str);

int main()
{
    const int MAX = 100;
    string choice = "\0";
    string continue_choice = "Y";
    string input_expr;
    string infix;
    string parsedInfix;
    char postfix[MAX];

    while (choice != "X" && choice != "x")
    {
        instructions();
        input_validation(choice);

        switch (choice_validation(choice))
        {
        case 'P':
        case 'p':
            description();
            break;
        case 'E':
        case 'e':
            continue_choice = 'Y';

            cout << "\nEnter an infix expression: ";
            input_validation(infix);

            parsedInfix = remove_space(infix);
            calculate(parsedInfix.c_str(), postfix);

            while (continue_choice != "N" && continue_choice != "n")
            {
                cout << "\nContinue? (Y/N): ";
                input_validation(continue_choice);
                switch (choice_validation(continue_choice))
                {
                case 'Y':
                case 'y':
                    cout << "\nEnter an infix expression: ";
                    input_validation(infix);

                    parsedInfix = remove_space(infix);
                    calculate(parsedInfix.c_str(), postfix);
                    break;

                case 'N':
                case 'n':
                    break;

                default:
                    cerr << "\nInvalid input\n";
                    break;
                }
            }
            break;

        case 'X':
        case 'x':
            cout << "\nExiting program...\n";
            break;
        default:
            cerr << "\nInvalid input\n";
            choice = "\0";
            break;
        }
    }

    return 0;
}

char choice_validation(string input)
{
    if (input.length() > 1)
    {
        return 'I';
    }
    return input[0];
}

/*
    This function removes all spaces in a string
    Input: string
    Output: string
*/
string remove_space(string str)
{
    str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());
    return str;
}

/*
    This function checks if a character is an operator
    Input: char
    Output: char
*/
char is_operator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

/*
    This function returns the precedence of an operator
    Input: char
    Output: int
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
}

/*
    This function converts an infix expression to its equivalent postfix expression and evaluates the postfix if valid
    Input: infix expression
    Output: none
*/
void calculate(const char *infix, char *postfix)
{
    int infix_length = strlen(infix);
    int j = 0;
    stack<char> stack;

    if (is_operator(infix[0]) || is_operator(infix[-1]))
    {
        cerr << "\nError: Invalid expression\n";
        return;
    }

    for (int i = 0; i < infix_length; i++)
    {

        char current_char = infix[i];

        if (isdigit(current_char))
        {
            // append digits directly to postfix expression
            while (isdigit(infix[i]))
            {
                postfix[j++] = infix[i++];
            }
            i--; // back up one character since we advanced one too far
        }
        else if (is_operator(current_char))
        {

            if (is_operator(infix[i + 1]) || infix[i + 1] == '\0')
            {
                cerr << "\nError: Invalid expression\n";
                return;
            }

            postfix[j++] = ' ';
            // pop operators with higher or equal precedence from stack
            while (!stack.empty() && stack.top() != '(' && precedence(stack.top()) >= precedence(current_char))
            {
                postfix[j++] = stack.top();
                postfix[j++] = ' ';
                stack.pop();
            }

            // push current operator onto stack
            stack.push(current_char);
        }
        else if (current_char == '(')
        {
            // push left parenthesis onto stack
            if (is_operator(infix[i + 1]))
            {
                cerr << "\nError: Invalid expression\n";
                return;
            }

            stack.push(current_char);
        }
        else if (current_char == ')')
        {
            if (!is_operator(infix[i + 1]) && infix[i + 1] != '\0')
            {
                cerr << "\nError: Invalid expression\n";
                return;
            }

            // pop operators until left parenthesis is found
            while (!stack.empty() && stack.top() != '(')
            {
                postfix[j++] = ' ';
                postfix[j++] = stack.top();
                stack.pop();
            }
            if (stack.empty())
            {
                cerr << "\nError: Mismatched parentheses in infix expression\n";
                return;
            }
            // discard left parenthesis
            stack.pop();
        }
        else
        {
            // invalid character
            cerr << "\nError: Invalid character '" << current_char << "' in infix expression\n";
            return;
        }
    }
    // append remaining operators from stack to postfix expression
    while (!stack.empty())
    {
        if (stack.top() == '(' || stack.top() == ')')
        {
            cerr << "\nError: Mismatched parentheses in infix expression\n";
            return;
        }
        postfix[j++] = ' ';
        postfix[j++] = stack.top();
        stack.pop();
    }

    // terminate postfix expression with null character
    postfix[j] = '\0';
    // Display postfix
    cout << "Postfix expression: " << postfix << '\n';
    // Evaluate postfix
    cout << "Result: " << evaluate_postfix((postfix)) << endl;
}

/*
    This function evaluates a postfix expression
    Input: postfix expression
    Output: result of the expression
*/
int evaluate_postfix(char *postfix)
{
    int stack[100];
    int top = -1;                       // initialize stack top index to -1
    char *token = strtok(postfix, " "); // tokenize the string by spaces
    while (token != NULL)
    {
        if (isdigit(token[0]))
        {
            // if token is a number, convert it to an integer and push it onto the stack
            int num = atoi(token);
            stack[++top] = num;
        }
        else
        {
            // if token is an operator, pop the top two elements from the stack
            // perform the operation and push the result onto the stack
            int op2 = stack[top--];
            int op1 = stack[top--];
            switch (token[0])
            {
            case '+':
                stack[++top] = op1 + op2;
                break;
            case '-':
                stack[++top] = op1 - op2;
                break;
            case '*':
                stack[++top] = op1 * op2;
                break;
            case '/':
                stack[++top] = op1 / op2;
                break;
            case '%':
                stack[++top] = op1 % op2;
                break;
            }
        }
        token = strtok(NULL, " "); // get next token
    }
    return stack[top]; // the final result will be on top of the stack
}

/*
    This function prints the program description
    Input: none
    Output: none
*/
void description()
{
    cout << "\nName: Sean Gabriel Bayron\n"
         << "Student Number: 2021-04354\n"
         << "Name: Arnel Jan Sarmiento\n"
         << "Student Number: 2021-05094\n"
         << "Date: 2023-3-17\n"
         << "This program converts a given infix expression to its equivalent postfix expression and then evaluates the expression.\n"
         << "The program was developed by Sean Gabriel Bayron and Arnel Jan Sarmiento.\n"
         << "Sean developed the original version of the program. Arnel then modified the program to make it more efficient.\n"
         << "Sean also implemented the infix to postfix conversion while Arnel implemented the postfix evaluation.\n";
}

/*
    This function prints the program instructions
    Input: none
    Output: none
*/
void instructions()
{
    cout << "\nWelcome to this Expression Evaluator program! Please choose an action to perform...\n"
         << "[P] Program Description\n"
         << "[E] Evaluate Expression(s)\n"
         << "[X] Exit\n"
         << "Choice: ";
}

/*
    This function validates string inputs. Gets the entire line of input.
    Input: pointer of input string
    Output: none
*/
void input_validation(string &str)
{
    getline(cin >> ws, str);
}
