/*Nome:Yago Martins Pintos
Matricula:20100404*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool judgeCircle(char *moves)
{
    int lrcount = 0, udcount = 0;
    for (int i = 0; i < strlen(moves); i++)
    {
        if (moves[i] == 'U')
        {
            udcount++;
        }
        if (moves[i] == 'D')
        {
            udcount--;
        }
        if (moves[i] == 'L')
        {
            lrcount--;
        }
        if (moves[i] == 'R')
        {
            lrcount++;
        }
    }
    if ((lrcount == 0) && (udcount == 0))
    {
        return true;
    }

    return false;
}
int main()
{
    bool print;
    int i, countmalloc = 1, toaddchar;
    char *str;
    i = 0;

    toaddchar = 0;
    str = (char *)malloc(countmalloc * sizeof(char));
    if (str == NULL)
    {
        printf("no memory available for allocation\n");
    }
    do
    {

        printf("enter the robot's movements:\n");
        scanf(" %c", &str[i]);
        i++;
        countmalloc++;
        str = realloc(str, countmalloc * sizeof(char));
        if (str == NULL)
        {
            printf("no memory available for allocation\n");
        }
        printf("want to add more characters(type 0 if you want to add more, any other key to finish)\n");
        scanf(" %d", &toaddchar);

    } while (toaddchar == 0);

    judgeCircle(str);
    print = judgeCircle(str);
    if (print == true)
    {
        printf(" true\n");
    }
    else
    {
        printf(" false\n");
    }
    free(str);
    return 0;
}