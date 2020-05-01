/******************/
/* Leroy Valencia */
/*    04/20/20    */
/*   CS-241-006   */
/******************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// #include <lcg.h>


bool validateDirection(char);
bool validateKey(int);
bool validateData(char);
bool validateAction(char);

void main()
{
    char c, action;
    char *line;
    char *direction;
    char *key;
    char * data;
    bool error;
    int commaCount, dirIndex, keyIndex, dataIndex;
    commaCount = dirIndex = keyIndex = dataIndex = 0;
    error = false;
/* 
    I am going to have to get the string then to a comma, then the digit, and then look for a new line char
 */
    direction = (char *) malloc(20);
    key = (char *) malloc(20);
    data = (char *) malloc(20);
    while((c = getchar()) != EOF)
    {
        if(c == '\n')
        {


            /* Reset all the variables */
            commaCount = dirIndex = keyIndex = dataIndex = 0;
            *direction = 0;
            *key = 0;
            *data = 0;
            putchar('\n');
        }
        else if(!error)
        {
            if(c == ',')
            {
                commaCount++;
            }
            else
            {
                struct LinearCongruentialGenerator* lcg;
                lcg.m  = 0;
                
                if(commaCount == 0) 
                {
                /* I will need to find a way to just skip to the next line if validate action is false */
                    if(dirIndex == 0) 
                    {
                        validateAction(c);
                        /* I need to see at the first comma for action and direction number */
                    }
                    if(dirIndex < 21)
                    {
                        strncat(direction, &c, 1);
                    }
                    else
                    {
                        error = true;
                    }
                    //printf("Direction: %s\n", direction);
                    dirIndex++;
                }
                if(commaCount == 1) 
                {
                    if(keyIndex < 21)
                    {
                        strncat(key, &c, 1);
                    }
                    else
                    {
                        /* This stops the rest of the line */
                        error = true;
                    }
                    
                    //printf("Key: %s\n", key);
                    keyIndex++;
                }
                if(commaCount == 2) 
                {
                    strncat(data, &c, 1);
                    //printf("Data: %s\n", data);
                    dataIndex++;
                    //data = realloc(data, dataIndex+1);
                }
            }
        }
        error = false;
    printf("%s,", direction);
    printf("%s,", key);
    printf("%s", data);
    putchar('\n');
    } // end of while
}

bool validateAction(char c)
{
    if(c == 'e' || c == 'd') 
    {
        printf("validated action\n");
        return true;
    }
    printf("Error\n");
    return false;
}