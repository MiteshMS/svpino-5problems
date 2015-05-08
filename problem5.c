/*  
    Problem 5
    Write a program that outputs all possibilities to put + or - or nothing 
    between the numbers 1, 2, ..., 9 (in this order) such that the result 
    is always 100. For example: 1 + 2 + 34 – 5 + 67 – 8 + 9 = 100.
*/
/*
    Code written by me (@MiteshMS) , enjoy! :)
*/

#include<stdio.h>

#define PLUS 0
#define MINUS 1
#define NONE 2

void printResult(int a[]);
int findResult(int a[]);
void func(int i, int a[]);

int main()
{
    int i;      //loop counter

    /*  a[0] = X where X in 1 X 2
        Array 'a' stores PLUS / MINUS / NONE */
    int a[9];

    for(i = 0; i < 9; i++)
    {
        a[i] = PLUS;    // Initialize all operators to PLUS
    }

    func(0,a);
    return 0;
}

/* Solver function */
void func(int i, int a[])
{
    int j;
    for(j = 0; j < 3; j++)
    {
        a[i] = j; // PLUS --> MINUS --> NONE for every operator position

        /* If the result totals to 100 print solution
           else continue until all operators have been tested */
        if( findResult(a) != 100)
        {
            if(i<7)
                func(i+1,a);
        }
        else
        {
            printResult(a);
        }
    }
}

/* Finds the sum of the text */
int findResult(int a[])
{
    int sum = 1, i;
    for(i = 2; i < 10; i++)
    {
        if(a[i-2] == PLUS)
        {
            sum += i;
        }
        else if(a[i-2] == MINUS)
        {
            sum -= i;
        }
        else
        {
            if(a[i-3] == PLUS)
                sum = sum + ((i-1)*10)+(1);
            else if(a[i-3] == MINUS)
                sum = sum - ((i-1)*10)-(1);
            else return 0;
        }
    }
    return sum;
}

/* Prints human readable result */
void printResult(int a[])
{
    int i;
    printf("{ ");
    for(i = 0; i < 8; i++)
    {
        printf("%d", i+1);
        if(a[i] == PLUS)
        {
            printf("+");
        }
        else if(a[i] == MINUS)
        {
            printf("-");
        }
        else
        {
            //Do nothing
        }
    }
    printf("9 }: Sums to 100\n");
}
