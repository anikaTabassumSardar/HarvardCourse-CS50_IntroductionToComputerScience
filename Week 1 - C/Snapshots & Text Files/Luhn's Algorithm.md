# Luhn's Algorithm

## Steps to verify validity of credit card (given by CS50)
So what’s the secret formula? Well, most cards use an algorithm invented by Hans Peter Luhn of IBM. According to Luhn’s algorithm, you can determine if a credit card number is (syntactically) valid as follows:

Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
Add the sum to the sum of the digits that weren’t multiplied by 2.
If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
That’s kind of confusing, so let’s try an example with David’s Visa: 4003600000000014.

1. For the sake of discussion, let’s first underline every other digit, starting with the number’s second-to-last digit:

    4003600000000014

    Okay, let’s multiply each of the underlined digits by 2:

    1•2 + 0•2 + 0•2 + 0•2 + 0•2 + 6•2 + 0•2 + 4•2

    That gives us:

    2 + 0 + 0 + 0 + 0 + 12 + 0 + 8

2. Now let’s add those products’ digits (i.e., not the products themselves) together:

    2 + 0 + 0 + 0 + 0 + 1 + 2 + 0 + 8 = 13

    Now let’s add that sum (13) to the sum of the digits that weren’t multiplied by 2 (starting from the end):

    13 + 4 + 0 + 0 + 0 + 0 + 0 + 3 + 0 = 20

3. Yup, the last digit in that sum (20) is a 0, so David’s card is legit!

    So, validating credit card numbers isn’t hard, but it does get a bit tedious by hand. Let’s write a program.
