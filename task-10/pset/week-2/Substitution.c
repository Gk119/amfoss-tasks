#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if(strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 letters.\n");
        return 1;
    }

    for(int i = 0; i < 26; i++)
    {
        if(!((argv[1][i] >= 97 && argv[1][i] <= 122) || (argv[1][i] >= 65 && argv[1][i] <= 90)))
        {
            printf("Enter only smaller or lower case alphabets in key.\n");
            return 1;
        }
    }

    //to upper
    for(int i = 0; i < 26; i++)
    {
        if(argv[1][i] >= 97 && argv[1][i] <= 122)
        {
            argv[1][i] = argv[1][i] - 32;

        }
    }
    char plaintxt[200];
    char ciphertxt[200];
    printf("plain text: ");
    scanf("%200[^\n]",plaintxt);
    int len = strlen(plaintxt);
    for(int i = 0; i < len; i++)
    {
        char ch = plaintxt[i];
        if(ch >= 65 && ch <= 90)
        {
            int n = ch - 65;
            ciphertxt[i] = argv[1][n];
        }
        else if(ch >= 97 && ch <= 122)
        {
            int n = ch - 97;
            ciphertxt[i] = argv[1][n] + 32;
        }
        else ciphertxt[i] = ch;
    }
    printf("cipher text: %s\n", ciphertxt);

}