#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

//takes an input and converts it into 2s complement or unsigned binary number
long numToBinary(long input)
{
    //creating infrastructure to convert numbers into binary
    int remainder;
    long binary = 0, i = 1;

    //2s complement and unsigned numbers
    if(input>=0 && input <=127)
    {
        //algorithm to turn longs into binary using division method, adding using powers of 10.
        while(input != 0)
        {
            remainder = input%2;
            input /= 2;
            binary= binary + (remainder*i);
            i *= 10;
        }
        printf("%08lu",binary); //adds in leading 0s
        printf("%s"," both unsigned and 2s complement \n");
        return binary; //returns the full binary number.
    }

    //unsigned numbers
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
        return binary; //returns the full binary number.
    }

    //signed numbers
    if(input<=-1 && input>=-128)
    {
        //using method where up until first 1, binary number is copied.
        input = -input;
        bool a = 1; //used to indicate when 0s and 1s should be flipped.
        while(input != 0)
        {
            if(a) //while the first 1 is not encountered, copy binary number exactly.
            {
                remainder = input%2;
                input /= 2;
                binary= binary + (remainder*i);
                i *= 10;
            }

            else //when first 1 is encountered, start flipping the bits.
            {
                remainder = input%2;
                //flip all bits
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


            if(remainder == 1) // when encountering the first 1, make sure the rest of the bits are flipped by changing trigger boolean.
            {
                a = 0;
            }
        }

        //adding leading 1s to 2s complement number.
        while(binary < 10000000)
        {
            binary = binary + (1*i);
            i *= 10;
        }

        printf("%lu",binary);
        printf("%s"," signed \n");
        return binary; //returns the full binary number.
    }

    //if numbers don't fit into the ranges provided
    printf("%s", "out of range \n");
    return -1;
}


int main(void)
{
    long n = numToBinary(-128);
    return 0;
}

