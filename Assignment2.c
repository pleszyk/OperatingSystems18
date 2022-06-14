#include <stdio.h>
#include <time.h>

int main()
{

    char file[100];
    printf("Enter filename: ");
    scanf("%s", file);
    FILE *fp;
    fp = fopen(file, "r");

    int a = 0, e = 0, i = 0, o = 0, u = 0;
    char ch;

    while (!feof(fp))
    {
        fscanf(fp, "%c", &ch);
        if (ch == 'a' || ch == 'A')
            a++;
        else if (ch == 'e' || ch == 'E')
            e++;
        else if (ch == 'i' || ch == 'I')
            i++;
        else if (ch == 'o' || ch == 'O')
            o++;
        else if (ch == 'u' || ch == 'U')
            u++;
    }

    printf("This file has %d nummber of A's or a's\n", a);
    printf("This file has %d nummber of E's or e's\n", e);
    printf("This file has %d nummber of I's or i's\n", i);
    printf("This file has %d nummber of O's or o's\n", o);
    printf("This file has %d nummber of U's or u's\n", u);

    time_t t = time(NULL);

    struct tm tm = *localtime(&t);

    printf("The current year is %d, and this file is being created at %d:%d, on %d/%d/%d\n", tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_mon + 1, tm.tm_mday, tm.tm_year + 1900);

    return 0;
}