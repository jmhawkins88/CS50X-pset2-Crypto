/***********************************************************************
*
* Jessie Hawkins - pset2 - caesar.c
*
* This program enciphers text using Ceasar cipher, meaning it encrypts text
* using a numeric key.
*
************************************************************************/
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // return 1 if user inputs improper # of command line arguments
    if (argc != 2)
    {
        printf("Please enter a key!\n");
        return 1;
    }

    //second command line argument is key
    //convert key from string to int
    int key = atoi(argv[1]);

    //get string of text from user
    string s = GetString();

    //encrypt plain text using key
    for (int i = 0, n = strlen(s); i < n; i++)
        if (isalpha(s[i]))

            //if capitalized
            if (isupper(s[i]))
            {
                //keep ASCII value in uppercase range, rotate key places, print
                s[i] = (s[i] - 'A' + key) % 26 + 'A';
                printf("%c", s[i]);
            }

    //if lowercased
            else
            {
                //keep ASCII value in lowercase range, rotate key places, print
                s[i] = (s[i] - 'a' + key) % 26 + 'a';
                printf("%c", s[i]);
            }

    //if character is not part of the alaphabet
        else
        {
            //print as is
            printf("%c", s[i]);
        }

    //print new line
    printf("\n");

    //return 0 to indicate no errors occured
    return 0;
}
