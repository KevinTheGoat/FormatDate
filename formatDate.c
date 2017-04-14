#include "dateHead.h"
/*============================================================================
    Source code:  formatDate.c
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

purpose: reads date that has been validated from stdin and then prints it in
    appropriate format

@param argc - number of arguments
@param *argv[] - pointer to a char of array of arguments

@return NOERROR - value returned if no errors were encountered
____________________________________________________________________________*/
int main(int argc, char *argv[]) {
  char currentLine[LINE_LENGTH] = {0};

  fputs("**********Formatted Data**********\r\n", stdout);

  while (fgets(currentLine, LINE_LENGTH, stdin) != NULL) {

    writeFormat(currentLine);
  }
  appendFile();
  return NO_ERROR;
}

/*____________________________________________________________________________
function writeFormat ()

purpose: writes the format to a File

@param currentLine - current line being formated

@return void
____________________________________________________________________________*/
void writeFormat(char currentLine[LINE_LENGTH]) {

  char newLine[LINE_LENGTH] = {0};
  Date aDate                = {0, 0, 0};

  sscanf(currentLine, "%2d/%2d/%ld", &aDate.month, &aDate.day, &aDate.year);

  snprintf(newLine, sizeof(newLine), "%d %s %ld\r\n", aDate.day,
           MONTHS[aDate.month], aDate.year);

  fputs(newLine, stdout);

  return;
}
/*____________________________________________________________________________
function writeFormat ()

purpose: appends dates to end of outputfile

@return void
____________________________________________________________________________*/
void appendFile(){

  FILE *dateFile             = fopen("dates.dat", "r");
  FILE *outputFile           = fopen("output.dat", "a");
  char fileLine[LINE_LENGTH] = {0};

  fputs("**************OG Data**************\r\n", stdout);
  while (fgets(fileLine, LINE_LENGTH ,dateFile) != NULL) {

    fputs(fileLine, stdout);
  }
  fclose(dateFile);
  fclose(outputFile);
  return;
}