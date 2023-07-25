#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompts for credit card number
    long cardNumber = get_long("Number: ");

    // Count length of cardNumber
    int length = 0;
    long cardNumberForLength = cardNumber;
    while (cardNumberForLength > 0)
    {
        cardNumberForLength = cardNumberForLength / 10;
        length++;
    }

    // Checks if length is valid
    if (length != 13 && length != 15 && length != 16)
    {
        printf("INVALID\n");
        return 0;
    }


    // Calculate checksum
    int sum1 = 0;
    int sum2 = 0;
    long copyOfCardNumber = cardNumber;
    int total = 0;
    int modulus1;
    int modulus2;
    int digit1;
    int digit2;
    do
    {
        // Remove last digit and add to sum1
        modulus1 = copyOfCardNumber % 10;
        copyOfCardNumber = copyOfCardNumber / 10;
        sum1 = sum1 + modulus1;
        // Remove second last digit
        modulus2 = copyOfCardNumber % 10;
        copyOfCardNumber = copyOfCardNumber / 10;
        // Double second last digit and add digits to sum2
        modulus2 = modulus2 * 2;
        digit1 = modulus2 % 10;
        digit2 = modulus2 / 10;
        sum2 = sum2 + digit1 + digit2;
    }
    while (copyOfCardNumber > 0);
    total = sum1 + sum2;


    // Check Luhn Algorithm
    if (total % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }


    // Get first two digits to help determine which type of card this is
    long firstTwoDigits = cardNumber;
    do
    {
        firstTwoDigits = firstTwoDigits / 10;
    }
    while (firstTwoDigits >= 100);


    // Check starting digits to identify and print card type
    if ((firstTwoDigits / 10 == 3) && (firstTwoDigits % 10 == 4 || firstTwoDigits % 10 == 7))
    {
        printf("AMEX\n");
    }
    else if ((firstTwoDigits / 10 == 5) && (0 < firstTwoDigits % 10 && firstTwoDigits % 10 < 6))
    {
        printf("MASTERCARD\n");
    }
    else if (firstTwoDigits / 10 == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
