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
    char line[20];
    char c, action;
    char direction[20];
    char key[20];
    char * data;
    int index = 0;
    int lineIndex = 0;
/* 
    I am going to have to get the string then to a comma, then the digit, and then look for a new line char
 */
    while((c = getchar()) != EOF)
    {
        if(lineIndex == 0)
        {
            if(validateAction(c))
            {
                action = c;
                // putchar(action);
            }
        }

        if(c == '\n')
        {
            index = 0;
        }
        else
        {
            if(c == ',')
            {
                if(c == ',')
                {
                    
                }
            }
            
        }
        lineIndex++;
        if(c == '\n')
        {
            lineIndex = 0;
        }
    }
}

bool validateAction(char c)
{
    if(c == 'e' || c == 'd') return true;
    printf("Error\n");
    return false;
}