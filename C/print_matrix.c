#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void printar_string(char string[], int i)
{
    while (string[i] != '\0')
    {
        printf("%c",string[i]);
        ++i;
    }
    printf("\n");
}

void main()
{
    char string[15] = "Hello, world!";
    char new_string[15] = {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};

    int j = 0;
    while(string[j] != '\0')
    {
        for(int i = 32; i<=126; ++i)
        {
            usleep(5000);
            new_string[j] = (char) i;
            if ((char)i != string[j])
            {
                printar_string(new_string,0);
            }
            else
            {
                printar_string(new_string,0);
                break;
            }
        }
        ++j;
    }
    /* system("clear");
    printar_string(new_string,0); */
}