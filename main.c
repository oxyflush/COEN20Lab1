#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

long numToBinary(long input)
{
    int remainder;
    long binary = 0, i = 1;

    if(input>=0 && input <=127)
    {
        while(input != 0)
        {
            remainder = input%2;
            input /= 2;
            binary= binary + (remainder*i);
            i *= 10;
        }
        printf("%08lu",binary);
        printf("%s"," both unsigned and 2s complement \n");
        return binary;
    }

    if(input>=128 && input <=255)
    {
        while(input != 0)
        {
            remainder = input%2;
            input /= 2;
            binary= binary + (remainder*i);
            i *= 10;
        }
        printf("%08lu",binary);
        printf("%s"," unsigned \n");
        return binary;
    }


    if(input<=-1 && input>=-128)
    {
        input = -input;
        bool a = 1;
        while(input != 0)
        {
            if(a)
            {
                remainder = input%2;
                input /= 2;
                binary= binary + (remainder*i);
                i *= 10;
            }

            else
            {
                remainder = input%2;
                if(remainder == 0)
                {
                    remainder = 1;
                }
                else
                {
                    remainder = 0;
                }
                input /=2;
                binary = binary + (remainder*i);
                i *= 10;
            }


            if(remainder == 1)
            {
                a = 0;
            }
        }

        while(binary < 10000000)
        {
            binary = binary + (1*i);
            i *= 10;
        }


        printf("%lu",binary);
        printf("%s"," signed \n");
        return binary;
    }

    printf("%s", "out of range \n");
    return -1;
}


int main(void)
{
    long n = numToBinary(-128);
    //printf("%08lu",n);
    //printf("\n");
    return 0;
}

