#include "dateHead.h"
/*============================================================================
    Source code:  validateDate.c
    Author:  Kevin Moreau
    Student ID:  4804471
    Assignment:  Program #5 Unix Interface

    Course:  COP 4338 - Advanced Programming
    Section:  U04
    Instructor:  William Feild
    Due Date:  March 30th, by the end of class

        I hereby certify that this collective work is my own
        and none of it is the work of any other person or entity.
        ______________________________________ [Signature]

    Language:  C

    Compile: make sure header is in same directory to compile input
    "gcc -pedantic -ansi -o validateDate  validateDate.c"
    "gcc -pedantic -ansi -o formatDate  formatDate.c"
    or
    "make build"

    Run: to run
    ./validateDate < dates.dat [number of Dates or 0 for all] |./formatDate >
                        output.dat
  --------------------------------------------------------------------------

    Description:  reads an input file of dates
        and generate an output file that contains a list of validated dates.

    Input:  Accept input for the first program via the command-line arguments.
        Command-line this will represent the number o dates to read

    Output:  Generate an output file (output.dat) from the second program that
        contains a converted list of dates in day, abbreviated month & year
        format (i.e. 1 JAN 1900), followed by the original list of dates.

    Process:  Dates from a file

    Required Features Not Included:   Minimum of two source code files — one 
        for each main() — for the separate programs. Use of at least one 
        user-defined header file is required.

    Known Bugs:  N/A

============================================================================*/

/*____________________________________________________________________________
function main (argc , argv[])

purpose: takes in date from file, reads them line by line and then passes it to
  validate functions

@param argc - number of arguments
@param *argv[] - pointer to a char of array of arguments from command line

@return NOERROR - value returned if no errors were encountered
____________________________________________________________________________*/
int main(int argc, char *argv[]) {

  char currentLine[LINE_LENGTH] = { 0 };
  Date aDate                    = { 0, 0, 0 };
  int amountToRead              = 0;
  int dateCounter               = COUNT_INITIAL;


  amountToRead = validateCommandLine(argc, argv);

  while (fgets(currentLine, LINE_LENGTH, stdin) != NULL &&
         dateCounter <= amountToRead) {

    if (validateFormat(currentLine, &aDate) && validateMonth(aDate.month) &&
        validateDay(aDate.month, aDate.day, aDate.year) &&
        validateYear(aDate.year)) {

      fputs(currentLine, stdout);
    }
    dateCounter++;
  }
  return NO_ERROR;
}

/*____________________________________________________________________________
function validateFormat (char lineList[LINE_LENGTH], Date *aDatePointer)

purpose: checks if the format is in the valid m/d/yyyy format

@param currentLine[LINE_LENGTH] - the current line to be validated
@param *aDatePointer - a pointer to the Date created in main

@return true or false enum
____________________________________________________________________________*/
Boolean validateFormat(char currentLine[LINE_LENGTH], Date *aDatePointer) {
  Date aDate = {0,0,0};

  if (sscanf(currentLine, "%2d/%2d/%ld", &aDate.month, &aDate.day,
             &aDate.year) == CORRECT_FORMAT) {

    *aDatePointer = aDate;
    return isTrue;
  }
  return isFalse;
}

/*____________________________________________________________________________
function validateMonth (int month)

purpose: validate that the month is inbetween 1-12

@param month - month to be validated

@return a true or false enum
____________________________________________________________________________*/
Boolean validateMonth(int month) {
  if (month >= MIN_MONTH && month <= MAX_MONTH) {

    return isTrue;
  }
  return isFalse;
}

/*____________________________________________________________________________
function LeapYear(int year)

purpose: checks of year is a leap year
  algorithm(http://stackoverflow.com/questions/725098/leap-year-calculation)

@param year - year to be checked

@return a true or false enum
____________________________________________________________________________*/
Boolean LeapYear(long year) {
  if ((year % FOURTH_YEAR == LEAP && year % HUNDRED_YEAR != LEAP) 
      || year % (FOURTH_YEAR * HUNDRED_YEAR) == LEAP) {

    return isTrue;
  }
  return isFalse;
}

/*____________________________________________________________________________
function validateYear(long year)

purpose: checks if year is inbetween INT_MIN and INT_MAX

@param year - year to be analyzed

@return a true or false enum
____________________________________________________________________________*/
Boolean validateYear(long year) {
  if (year >= INT_MIN && year <= INT_MAX) {

    return isTrue;
  }

  return isFalse;
}
/*____________________________________________________________________________
function validateDay (int month, int day, int year)

purpose: validates the day of the Date to see if it is within valid possible
    days also checks for leap year

@param month - the month of the current date
@param day - the day of the current date
@param year - the year of the current date

@return a true or false enum
____________________________________________________________________________*/
Boolean validateDay(int month, int day, long year) {

  Boolean isLeap = isFalse;

  if (month == Feb) {

    isLeap = LeapYear(year);

    if (day >= MIN_DAY && day <= MONTH_DAYS[month]) {

      return isTrue;
    }
    if (isLeap == isTrue && day == LEAP_DAY) {

      return isTrue;
    }
  }
  if (day >= MIN_DAY && day <= MONTH_DAYS[month]) {

    return isTrue;
  }
  return isFalse;
}

/*____________________________________________________________________________
function validateYear(long year) (TBA)

purpose: checks if year is inbetween INT_MIN and INT_MAX

@param year - year to be analyzed

@return a true or false enum
____________________________________________________________________________*/
int validateCommandLine(int argsAmount, char *userInputPointer[]) {
  int amountToRead          = 0;
  char userInput[MAX_ARRAY] = { 0 };
  if (argsAmount == MIN_ARGS) {

    userInput[0] = *userInputPointer[READ_AMOUNT_LOC];

    if (sscanf(userInput, "%d", &amountToRead) == LINE_IS_NUM) {

      if (amountToRead == READ_ALL) {

        amountToRead = MAX_ARRAY;
      }
      return amountToRead;
    }
  }
  printf("Invalid Command line argument");
  return ERROR;
}
