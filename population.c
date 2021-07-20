#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start;
    int end;
    do
    {
        //Prompts for start size. Size must be a positive number.
        start = get_int("Start size: ");
    }
    while ((start/3) < 2);
    
    do
    {
        //Prompts for end size
        end = get_int("End size: ");
    }
    while (start > end);
        
           
    
    do
    {
    while (start< end)
    {
        start = (start + (start/3) - (start/4));
        
    }
    }while (start < end);
    //Prints number of years
    printf("Years: %i\n", start);
                
    
   
}