A credit card has a number that is unique to each card. This number is used to identify
the card and also for validation of said card. An IBM enineer Peter Hans Luhn created an algorithm used
internationally to create the numbers but also validate them.

A credit card number usually has 16 digits but could have as few as 13 digits and msometimes as many as 19.
A valid credit card starts with specific digits; '4' for Visa cards, '5' for MasterCard credit cards, '37' for American Express cards and '6' for Discover cards 
The algorithm also known as Luhn check is as follows;
1. Double every second digit from right to left. If doubling of a digit results in a
two-digit number, add up the two digits to get a single-digit number.
2. Now add all single-digit numbers from Step 1.
3. Add all digits in the odd places from right to left in the card number.
4. Sum the results from Steps 2 and 3.
5. If the result from Step 4 is divisible by 10, the card number is valid; otherwise,
it is invalid. 

The program in file creditcard_solution.cpp does just that using the following functions;
1. int getSize(long long d): which takes in an integer specifically a long integer and uses division by 10 to get the number of digits or size of the integer. It uses a while loop in an if statement. The if statement caters for the case that the user enters 0. This is unlikely but could be possible. This funnction returns the size of the integer.
2. int getDigit(int number): which takes in an integer number and returns only one digit to represent the number. This is especially useful since when doubling the digits in the even positions we ought to get a single digit number for each double. It uses an if/else statement to obtain the representative digit. In the case that the integer has two digits,which is the most it can have, the funtion is able to mathematically separate the digit in the one position and that in the tens.  
3. int sumofOddPlace(long long number): which takes in an integer specifically a long integer like the credit card number and sums the digits in the odd position while starting to count from the right.The position of the number on the extreme right is give position 1. It uses a while loop.  Within the while loop, there is an if statement that is used to extract and sum only numbers with odd positions. The function returns the sum of all digits in the odd positions.
4. int sumOfDoubleEvenPlace(long long number): which is very similar to sumofOddPlace() in how it determine the positions but after determining a digit is in an even position, function getDigit() is used to get only one representative digit of the digits' double. After which the representative is added to the sum which upon exit of the while loop is returned.
5. long long getPrefix(long long number,int k) takes in the long integer and the size of the required prefix and returns the prefix i.e if the prefix is of size k, the function returns the number in first k positions.
6. bool prefixMatched (long long number,int d) which takes in the long number and a specified number d and checks if the prefix of the long number is that number d. If true , it returns 1, if false, 0. This function also makes use of the getSize() to get the size of d and getPrefix().
7. bool isValid(long long number): This function now bring all conditions together. It checks for size, finds the checksum, check it, and also checks the prefix. If even one condition is not passed , the function returns 0.

In the main fucntion , only the function isValid() is called. The input is the credit card number. 
The program will output:
The number 4567..... is valid if valid 
   or
The number 4567.... is invalid if not

This program utilises fucntions a lot especially the aspect of functions calling other functions.