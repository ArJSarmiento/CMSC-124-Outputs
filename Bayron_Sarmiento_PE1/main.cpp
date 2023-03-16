#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstring>

using namespace std;

char is_operator(char c);
void description();
void instructions();
string remove_space(string str);
void infix_to_postfix(const char* infix, char* postfix);
int evaluate_postfix(string postfix);

int main()
{
    const int MAX = 100;
    char choice = '\0';
    string input_expr;
    string infix;
    string parsedInfix;
    char postfix[MAX];
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
            cout << "\nEnter an infix expression: ";
            cin.ignore();
            getline(cin, infix);
            parsedInfix = remove_space(infix);
            infix_to_postfix(parsedInfix.c_str(), postfix);
            result = evaluate_postfix(postfix);
            cout << "Result: " << result << endl;
            break;
        case 'X':
        case 'x':
            cout << "\nExiting program...\n";
            break;
        default:
            cerr << "\nInvalid input\n";
            break;
        }
    }
    return 0;
}

string remove_space(string str)
{
    str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());
    return str;
}

char is_operator(char c)
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
}

void description()
{
    cout << "\nName: Sean Gabriel Bayron\n";
    cout << "Student Number: 2021-04354\n";
    cout << "Name: Arnel Jan Sarmiento\n";
    cout << "Student Number: 2021-05094\n";
    cout << "Date: 2023-3-05\n";
    cout << "This program converts a given infix expression to its equivalent postfix expression and then evaluates the expression.\n";
    cout << "The program was developed by Sean Gabriel Bayron and Arnel Jan Sarmiento.\n";
    cout << "Sean developed the original version of the program. Arnel then modified the program to make it more efficient.\n";
    cout << "Sean also implemented the infix to postfix conversion while Arnel implemented the postfix evaluation.\n";
}

void instructions()
{
    cout << "\nWelcome to this Expression Evaluator program! Please choose an action to perform...\n";
    cout << "[P] Program Description\n";
    cout << "[E] Evaluate Expression(s)\n";
    cout << "[X] Exit\n";
    cout << "Choice: ";
}

void infix_to_postfix(const char* infix, char* postfix) {
    int infix_length = strlen(infix);
    int j = 0;
    stack<char> stack;

    if (is_operator(infix[0]) || is_operator(infix[-1]))
    {
        cerr << "Error: Invalid expression\n";
        return;
    }
    

    for (int i = 0; i < infix_length; i++) {
        
        char current_char = infix[i];

        if (isdigit(current_char)) {
            // append digits directly to postfix expression
            while (isdigit(infix[i])) {
                postfix[j++] = infix[i++];
            }
            i--; // back up one character since we advanced one too far
        } else if (is_operator(current_char)) {
            if (is_operator(infix[i+1]))
            {
                cerr << "Error: Invalid expression\n";
                return;
            }
            
            postfix[j++] = ' ';
            // pop operators with higher or equal precedence from stack
            while (!stack.empty() && stack.top() != '(' && precedence(stack.top()) >= precedence(current_char)) {
                postfix[j++] = stack.top();
                postfix[j++] = ' ';
                stack.pop();
            }

            // push current operator onto stack
            stack.push(current_char);
        } else if (current_char == '(') {
            // push left parenthesis onto stack
            if (is_operator(infix[i+1]))
            {
                cerr << "Error: Invalid expression\n";
                return;
            }
            
            stack.push(current_char);
        } else if (current_char == ')') {
            if (!is_operator(infix[i+1]) && infix[i+1] != '\0')
            {
                cerr << "Error: Invalid expression\n";
                return;
            }
            
            // pop operators until left parenthesis is found
            while (!stack.empty() && stack.top() != '(') {
                postfix[j++] = ' ';
                postfix[j++] = stack.top();
                stack.pop();
            }
            if (stack.empty()) {
                cerr << "Error: Mismatched parentheses in infix expression\n";
                return;
            }
            // discard left parenthesis
            stack.pop();
        } else {
            // invalid character
            cerr << "Error: Invalid character '" << current_char << "' in infix expression\n";
            return;
        }
    }
    // append remaining operators from stack to postfix expression
    while (!stack.empty()) {
        if (stack.top() == '(' || stack.top() == ')') {
            cerr << "Error: Mismatched parentheses in infix expression\n";
            return;
        }
        postfix[j++] = ' ';
        postfix[j++] = stack.top();
        stack.pop();
    }

    // terminate postfix expression with null character
    postfix[j] = '\0';
    cout << "Postfix expression: " << postfix << '\n';
}

int evaluate_postfix(string postfix) {
    stack<int> stack; // use stack instead of array
    string delimiter = " "; // set delimiter as a string
    size_t pos = 0;
    string token;
    while ((pos = postfix.find(delimiter)) != string::npos) {
        token = postfix.substr(0, pos);
        postfix.erase(0, pos + delimiter.length());
        if (isdigit(token[0])) {
            // if token is a number, convert it to an integer and push it onto the stack
            int num = stoi(token);
            stack.push(num);
        } else {
            // if token is an operator, pop the top two elements from the stack
            // perform the operation and push the result onto the stack
            int op2 = stack.top(); stack.pop();
            int op1 = stack.top(); stack.pop();
            switch (token[0]) {
                case '+': stack.push(op1 + op2); break;
                case '-': stack.push(op1 - op2); break;
                case '*': stack.push(op1 * op2); break;
                case '/': stack.push(op1 / op2); break;
                case '%': stack.push(op1 % op2); break;
            }
        }
    }
    // convert last token to integer and push it onto the stack
    int num = stoi(postfix);
    stack.push(num);
    return stack.top(); // the final result will be on top of the stack
}
