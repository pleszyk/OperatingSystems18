#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//function returns the size of the word
int findWordSize(char a[])
{
    int i = 0;
    while (a[i] != '\0')
    {
        i = i + 1;
    }
    return i;
}
//function checks if the character is vowel or not
bool isVowel(char a)
{
    if (a == 'A' || a == 'a' || a == 'E' || a == 'e' || a == 'I' || a == 'i' || a == 'O' || a == 'o' || a == 'U' || a == 'u')
        return true;
    else
        return false;
}
//main method
int main()
{
    char name[20];
    char word[30];
    //requesting the input file name
    printf("Enter the input filename: ");
    scanf("%s", name);

    //opening the input file
    FILE *in_file;
    in_file = fopen(name, "r");

    FILE *out_file;
    out_file = fopen("output.txt", "a");
    //file is null printf error
    if (in_file == NULL)
    {
        printf("Error file missing\n");
        exit(-1);
    }

    while (!feof(in_file))
    {
        strcpy(word, "");
        //reading each word in file to char array word[]
        fscanf(in_file, "%s", word);

        //finding the word size
        int l = findWordSize(word);
        //if word size >1 do the following
        if (l > 1)
        {
            //if thw first character is capital convert it to small or vice versa
            if (word[0] >= 'A' && word[0] <= 'Z')
            {
                word[0] = word[0] + 32;
            }
            else if (word[0] >= 'a' && word[0] <= 'z')
            {
                word[0] = word[0] - 32;
            }
            //if the last character is capital convert it to small or vice versa
            if (word[l - 1] >= 'A' && word[l - 1] <= 'Z')
            {
                word[l - 1] = word[l - 1] + 32;
            }
            else if (word[l - 1] >= 'a' && word[l - 1] <= 'z')
            {
                word[l - 1] = word[l - 1] - 32;
            }
        }
        //if the word starts with vowel, write it to output file
        if (isVowel(word[0]))
        {
            fprintf(out_file, "%s\n", word);
        }
        //printing each word in the input file after modification
        printf("%s\n", word);
    }

    return 0;
}