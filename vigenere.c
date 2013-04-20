/***************************************************************************
*
* Jessie Hawkins - pset2 - vigenere.c
*
* This program enciphers text using a vigenere cypher, meaning it encrypts
* messages using a keyword
****************************************************************************/


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
        printf("Please enter a keyword!\n");
        return 1;
    }

    // rename argv[1]
    string k = argv[1];
    int k_length = strlen(k);

    // check if keyword is alphabetical
    for (int i = 0; i < k_length; i++)
    {
        if (!isalpha(k[i]))
        {
            printf("Keyword is not all alphabetical!");
            return 1;
        }
    }

    // get string of plain text from user
    string s = GetString();
    argv[2] = s;

    // declare counter for letters seen
    int letters_seen = 0;

    //encrypt plain text
    for (int i = 0; i < strlen(s); i++)
    {
        // check to encrypt letters only
        if (isalpha(s[i]))
        {
            // turn keyword into integer range
            int key;
            if (isupper(k[letters_seen % k_length]))
            {
                key = k[letters_seen % k_length] - 'A';
            }
            else
            {
                key = k[letters_seen % k_length] - 'a';
            }

            // encrypt message
            if (isupper(s[i]))
            {
                s[i] = ((s[i] - 'A' + key) % 26) + 'A';
            }
            else
            {
                s[i] = ((s[i] - 'a' + key) % 26) + 'a';
            }

            //go to next letter
            letters_seen++;
        }
    }

    // print message
    printf("%s\n", s);

    //return 0 to indicate no errors occured
    return 0;
}
