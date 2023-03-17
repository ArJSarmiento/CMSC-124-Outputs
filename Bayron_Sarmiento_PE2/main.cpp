#include <iostream>
#include <string.h>

using namespace std;

// function prototypes
void compress(string str);
void expand(string str);
void description();
void instructions();
void input_validation(string &str);
char choice_transformer(string input);
void choice_validation(char &validated_continue_choice, string &continue_choice);

int main()
{
    string str;
    string choice = "\0";
    string continue_choice;
    char validated_continue_choice = '\0';

    while (choice != "X" && choice != "x")
    {
        instructions();
        input_validation(choice);

        switch (choice_transformer(choice))
        {
        case 'P':
        case 'p':
            description();
            break;
        case 'E':
        case 'e':
            do
            {
                cout << "\nEnter a string to expand: ";
                input_validation(str);
                expand(str);
                choice_validation(validated_continue_choice, continue_choice);
            } while (validated_continue_choice == 'Y' || validated_continue_choice == 'y');
            break;
        case 'C':
        case 'c':
            do
            {
                cout << "\nEnter a string to compress: ";
                input_validation(str);
                compress(str);
                choice_validation(validated_continue_choice, continue_choice);
            } while (validated_continue_choice == 'Y' || validated_continue_choice == 'y');
            break;
        case 'X':
        case 'x':
            cout << "\nExiting program...\n";
            exit(0);
            break;
        default:
            cout << "\n\nInvalid input\n";
            break;
        }
    }

    return 0;
}

/*
    Compresses a string based on the number of consecutive characters
    Input: string
    Output: none
*/
void compress(string str)
{
    int i = 0;
    int count = 0;

    cout << "\n";
    while (i < str.length())
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            if (str[i] == str[i + 1])
            {
                count++;
            }
            else
            {
                count++;
                if (count == 1)
                {
                    cout << str[i];
                }
                else
                {
                    cout << count << str[i];
                }
                count = 0;
            }
        }
        else
        {
            cout << "\nInvalid input\n";
            break;
        }
        i++;
    }
    cout << endl;
}

/*
    Expands a string based on the number of consecutive characters
    Input: string
    Output: none
*/
void expand(string str)
{
    int i = 0;
    int count = 0;

    cout << endl;

    while (i < str.length())
    {
        if (isalpha(str[i]))
        {
            cout << str[i];
        }
        else if (isdigit(str[i]))
        {
            count = str[i] - '0';
            while (count > 1)
            {
                cout << str[i + 1];
                count--;
            }
        }
        else
        {
            cout << endl
                 << "\nInvalid input" << endl;
            break;
        }
        i++;
    }
    cout << endl;
}

/*
    Prints program instructions
    Input: none
    Output: none
*/
void instructions()
{
    cout << "\nWelcome to this String Expansion/Compression program! Please choose an action to perform...\n"
         << "[P] Program Description\n"
         << "[E] String Expansion\n"
         << "[C] String Compression\n"
         << "[X] Exit\n"
         << "Choice: ";
}

/*
    Prints program description
    Input: none
    Output: none
*/
void description()
{
    cout << "\nName: Sean Gabriel Bayron\n";
    cout << "Student Number: 2021-04354\n";
    cout << "Name: Arnel Jan Sarmiento\n";
    cout << "Student Number: 2021-05094\n";
    cout << "Date: 2023-3-17\n";
    cout << "This program is a string compression/expansion program. It can compress and expand strings.\n";
    cout << "The program was developed by Sean Gabriel Bayron and Arnel Jan Sarmiento.\n";
    cout << "Arnel developed the original version of the program. Sean then modified the program to make it more efficient.\n";
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

/*
    This function transforms the input to a single character
    Input: string
    Output: character
*/
char choice_transformer(string input)
{
    if (input.empty())
        return '\0';
    if (input.length() > 1)
        return 'I';
    return input[0];
}

/*
    This function validates the choice of the user
    Input: pointer of validated choice, pointer of choice
    Output: none
*/
void choice_validation(char &validated_continue_choice, string &continue_choice)
{
    validated_continue_choice = '\0';
    while (validated_continue_choice != 'Y' && validated_continue_choice != 'y' && validated_continue_choice != 'N' && validated_continue_choice != 'n')
    {
        cout << "\nContinue? (Y/N): ";
        input_validation(continue_choice);
        validated_continue_choice = choice_transformer(continue_choice);
        switch (validated_continue_choice)
        {
        case 'Y':
        case 'y':
        case 'N':
        case 'n':
            break;
        default:
            cerr << "Invalid input\n";
            break;
        }
    }
}