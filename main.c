#include <stdio.h>

//takes an input and converts it into 2s complement or unsigned binary number
//return type long just in case it needs to be stored.
long printBinary(long input)
{
    long binary = 0;

    //2s complement and unsigned numbers
    if(input>=0 && input <=127)
    {
        binary = numToBinary(input);
        printf("%08lu",binary); //adds in leading 0s
        printf("%s"," both unsigned and 2s complement \n");
        return binary; //returns the full binary number.
    }

    //unsigned numbers
    if(input>=128 && input <=255)
    {
        binary = numToBinary(input);
        printf("%08lu",binary);
        printf("%s"," unsigned \n");
        return binary; //returns the full binary number.
    }

    //signed numbers
    if(input<=-1 && input>=-128)
    {
        //adding 256 to negative number to get 2s complement positive equivalent
        binary = numToBinary(256+input);
        printf("%lu",binary);
        printf("%s"," signed \n");
        return binary; //returns the full binary number.
    }

    //if numbers don't fit into the ranges provided
    printf("%s", "out of range \n");
    return -1;
}

int numToBinary(long input)
{
    //creating infrastructure to convert numbers into binary
    int remainder;
    long binary = 0, i = 1;

    //algorithm to turn longs into binary using division method, adding using powers of 10.
    while(input != 0)
    {
        remainder = input%2;
        input /= 2;
        binary= binary + (remainder*i);
        i *= 10;
    }
    return binary;
}


int main(void)
{
    long x;
    printf("%s\n","Please enter in a number from -128 to 255"); //prompt user
    scanf("%ld",&x); //recieve a singed long
    printBinary(x); //execute function
    return 0;
}

