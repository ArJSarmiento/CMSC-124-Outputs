#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string.h>

using namespace std;

void compress(string str);
void expand(const string &str);
void description();
void instructions();

int main()
{
    char choice;
    string str;

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
            cout << "\nEnter a string to expand: ";
            cin.ignore();
            getline(cin, str);
            expand(str);
            break;
        case 'C':
        case 'c':
            cout << "\nEnter a string to compress: ";
            cin.ignore();
            getline(cin, str);
            compress(str);
            break;
        case 'X':
        case 'x':
            cout << "\nExiting program...\n";
            exit(0);
            break;
        default:
            cout << "\nInvalid input\n";
            break;
        }
    }

    return 0;
}

/*
    Prints program description
*/
void description()
{
    cout << "\nName: Sean Gabriel Bayron\n";
    cout << "Student Number: 2021-04354\n";
    cout << "Name: Arnel Jan Sarmiento\n";
    cout << "Student Number: 2021-05094\n";
    cout << "Date: 2023-3-05\n";
    cout << "This program is a string compression/expansion program. It can compress and expand strings.\n";
    cout << "The program was developed by Sean Gabriel Bayron and Arnel Jan Sarmiento.\n";
    cout << "Arnel developed the original version of the program. Sean then modified the program to make it more efficient.\n";
}

/*
    Compresses a string based on the number of consecutive characters
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
*/
void expand(const string &str)
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
