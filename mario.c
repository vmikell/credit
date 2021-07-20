#import <stdio.h>
#import <cs50.h>
//Prints a pyramid, the height of which is determined by the users input.
void width(int userInput)
{
    for(int i = 0; i < userInput; i++)
    {
        printf("#");
    }
    
}

void space(int userInput)
{
    for(int i = 0; i < userInput; i++)
    {
        printf(" ");
    }
}

int main(void)
{   
    int n;
    do
    {
        //Asks user their desired height of the pyramid.
        n = get_int("Height: ");
        
        int k = 1;
        int m = 0;
        //Prints mario pyramid to the desired height if number is between 1 and 8.
        if(n>0 && n<9)
        {
            for(int i = 0; i < n; i++)
            {
           
                space((n+m)-1);
                width((n-n)+k);
                printf("  ");
                width((n-n)+k);
                printf("\n"); 
                k++;
                m--;
            
            }
        }
         
    //Returns user to height selection if value is < 1.
    }
    while(n<1 || n>8);
}