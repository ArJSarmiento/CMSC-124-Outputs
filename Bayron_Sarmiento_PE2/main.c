#include <stdio.h>
#include <stdlib.h>

void compress(char *str);
void expand(char *str);
void description();
void instructions();

int main()
{
    char choice;
    char str[100];

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
            printf("\nEnter a string to expand: ");
            scanf("%s", str);
            expand(str);
            break;
        case 'C':
        case 'c':
            printf("\nEnter a string to compress: ");
            scanf("%s", str);
            compress(str);
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

/*
    Prints program description
*/
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

/*
    Compresses a string based on the number of consecutive characters
*/
void compress(char *str)
{
    int i = 0;
    int count = 0;

    printf("\n");
    while (str[i] != '\0')
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
                    printf("%c", str[i]);
                }
                else
                {
                    printf("%d%c", count, str[i]);
                }
                count = 0;
            }
        }
        else
        {
            printf("\nInvalid input\n");
            break;
        }
        i++;
    }
    printf("\n");
}

/*
    Expands a string based on the number of consecutive characters
*/
void expand(char *str)
{
    int i = 0;
    int count = 0;

    printf("\n");
    while (str[i] != '\0')
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            printf("%c", str[i]);
        }
        else if (str[i] >= '0' && str[i] <= '9')
        {
            count = str[i] - '0';
            while (count > 1)
            {
                printf("%c", str[i + 1]);
                count--;
            }
        }
        else
        {
            printf("\nInvalid input\n");
            break;
        }
        i++;
    }
    printf("\n");
}

/*
    Prints program instructions
*/
void instructions()
{
    printf("\nWelcome to this String Expansion/Compression program! Please choose an action to perform...\n");
    printf("[P] Program Description\n");
    printf("[E] String Expansion\n");
    printf("[C] String Compression\n");
    printf("[X] Exit\n");
    printf("Choice: ");
}