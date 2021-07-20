#import <stdio.h>
#import <cs50.h>

/*The following promts the user for a credit card number and determines if a entered value is a
valid AMEX, VISA or MASTERCARD credit card number. If the entered card number is valid the card
type will print. If the number entered is not a valid credit card number "INVALID" will
print to the console.
*/

int main(void)
{
    long numOne;
    long numOne2 = 0;
    long numTwo;
    long numTwo2 = 0;
    long numThree;
    long numThree2 = 0;
    long numFour;
    long numFour2 = 0;
    long numFive;
    long numFive2 = 0;
    long numSix;
    long numSix2 = 0;
    long numSeven;
    long numSeven2 = 0;
    long numEight;
    long numEight2 = 0;
    long number = get_long("Number: ");

    /*The following assigns a variable (num...)to each of the digits making up a
    credit card number starting with second to last number and doulbes it.
    This opperation is perfomed from right to left.
    If the product is comprised of two digits (i.e. 6 * 2 = 12)
    it assigns a variable (num...2) to each digit (i.e '1' and '2').
    */

    {
        numOne = (((number % 100) - (number % 10)) / 10) * 2;
        if (numOne > 9)
        {
            numOne2 = numOne % 10;
            numOne = numOne - (numOne % 10) - 9;
        }
        numTwo = (((number % 10000) - (number % 1000)) / 1000) * 2;
        if (numTwo > 9)
        {
            numTwo2 = numTwo % 10;
            numTwo = numTwo - (numTwo % 10) - 9;
        }
        numThree = (((number % 1000000) - (number % 100000)) / 100000) * 2;
        if (numThree > 9)
        {
            numThree2 = numThree % 10;
            numThree = numThree - (numThree % 10) - 9;
        }
        numFour = (((number % 100000000) - (number % 10000000)) / 10000000) * 2;
        if (numFour > 9)
        {
            numFour2 = numFour % 10;
            numFour = numFour - (numFour % 10) - 9;
        }
        numFive = (((number % 10000000000) - (number % 1000000000)) / 1000000000) * 2;
        if (numFive > 9)
        {
            numFive2 = numFive % 10;
            numFive = numFive - (numFive % 10) - 9;
        }
        numSix = (((number % 1000000000000) - (number % 100000000000)) / 100000000000) * 2;
        if (numSix > 9)
        {
            numSix2 = numSix % 10;
            numSix = numSix - (numSix % 10) - 9;
        }
        numSeven = (((number % 100000000000000) - (number % 10000000000000)) / 10000000000000) * 2;
        if (numSeven > 9)
        {
            numSeven2 = numSeven % 10;
            numSeven = numSeven - (numSeven % 10) - 9;
        }
        numEight = (((number % 10000000000000000) - (number % 1000000000000000)) / 1000000000000000) * 2;
        if (numEight > 9)
        {
            numEight2 = numEight % 10;
            numEight = numEight - (numEight % 10) - 9;
        }

        //The digits of the products found in the preceeding operation are added together.

        long sumOne =
            numOne + numOne2 +
            numTwo + numTwo2 +
            numThree + numThree2 +
            numFour + numFour2 +
            numFive + numFive2 +
            numSix + numSix2 +
            numSeven + numSeven2 +
            numEight + numEight2;


        long otherOne;
        long otherTwo;
        long otherThree;
        long otherFour;
        long otherFive;
        long otherSix;
        long otherSeven;
        long otherEight;

        //Variables (other...) are assigned to the remaining card numbers.

        {
            otherOne = (number % 10);
            otherTwo = (((number % 1000) - (number % 100)) / 100);
            otherThree = (((number % 100000) - (number % 10000)) / 10000);
            otherFour = (((number % 10000000) - (number % 1000000)) / 1000000);
            otherFive = (((number % 1000000000) - (number % 100000000)) / 100000000);
            otherSix = (((number % 100000000000) - (number % 10000000000)) / 10000000000);
            otherSeven = (((number % 10000000000000) - (number % 1000000000000)) / 1000000000000);
            otherEight = (((number % 1000000000000000) - (number % 100000000000000)) / 100000000000000);

            //The digits of the products found in the preceeding operation are added together.

            long sumTwo =
                otherOne + otherTwo + otherThree + otherFour + otherFive + otherSix + otherSeven + otherEight;
            long checkSum = sumOne + sumTwo;

            //Sets logic for VISA cards which are comprised of either 13 or 16 numbers and always begin with a '4'.

            if (((number > 3999999999999 && number < 5000000000000) && checkSum % 10 == 0) || ((number > 3999999999999999
                    && number < 4999999999999999) && checkSum % 10 == 0))
            {
                printf("VISA\n");
            }

            //Sets logic for MASTERCARD which is always 16 digits long and starts with a 51,52,52,54 or 55.

            else if (number > 4999999999999999 && number < 5599999999999999 && checkSum % 10 == 0)
            {
                printf("MASTERCARD\n");
            }

            //Sets logic for AMEX which is always 15 digits long and start with either a 34 or 37.

            else if (((number > 339999999999999 && number < 349999999999999) && checkSum % 10 == 0) || ((number > 369999999999999
                     && number < 379999999999999) && checkSum % 10 == 0))
            {
                printf("AMEX\n");
            }
            else

                //If the number does not meet any of the above conditions it is inivalid.

            {
                printf("INVALID\n");
            }

        }
    }
}

