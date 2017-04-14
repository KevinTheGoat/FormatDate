/*============================================================================
Source code:  dateHead.h

Decription: header file for program. contains libraries, constants, structs,
    enums, and prototypes
============================================================================*/
/*libraies*/
#include <limits.h>
#include <stdint.h>
#include <stdio.h>

/*symbolic constants*/
#define LINE_LENGTH 30    /*max number of characters for a line*/
#define NO_ERROR 0        /*no errors recieved from main*/
#define MIN_MONTH 1       /*lowest possible month*/
#define MAX_MONTH 12      /*highest possible month*/
#define MIN_DAY 1         /*min number for day*/
#define LEAP_DAY 29       /* max day for feb on leap year*/
#define FOURTH_YEAR 4     /*fourth year for leap year calculations*/
#define HUNDRED_YEAR 100  /*hundred year for leap year calculations*/
#define LEAP 0            /*number used to identify leap year after mod*/
#define CORRECT_FORMAT 3  /*correct day month year return value*/
#define MAX_ARRAY 65535   /* Max array size allowed by standard*/
#define ERROR -1          /*error in main from user input*/
#define READ_ALL 0        /*reads all avaiable data*/
#define READ_AMOUNT_LOC 1 /*location of how many dates to read*/
#define COUNT_INITIAL 0   /* what to initialize counter to*/
#define LINE_IS_NUM 1     /*gives back 1 if the line read is all numbers*/
#define MIN_ARGS 2        /*min amount of arguments*/

/* constants */
const char *MONTHS[] = {"error", "JAN", "FEB", "MAR", "APR", "MAY", "JUN",
                        "JUL",   "AUG", "SEP", "OCT", "NOV", "DEC"}; /* an array
                          of char to hold the string value of months to be
                          printed for later */

const int MONTH_DAYS[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
                          /*an array of ints to correspond with the months max
                          value for a regular year*/

/*struct*/
typedef struct Date {

  int month;
  int day;
  long year;
} Date; /*Date: a struct made for the date received from file*/

/*enum*/

typedef enum MonthNum{

    Jan = MIN_MONTH, Feb, Mar, Apr, May, Jun, Jul, Aug, Sept, Oct, Nov, Dec 
} MonthNum; /*Month: enum to hold the months for the date*/


typedef enum Boolean {

    isFalse, isTrue
} Boolean; /*Boolean: a enum to hold true and false values*/

/*prototypes*/
void appendFile();
Boolean validateFormat(char lineList[LINE_LENGTH], Date *aDatePointer);
Boolean validateMonth(int month);
Boolean LeapYear(long year);
Boolean validateYear(long year);
Boolean validateDay(int month, int day, long year);
int validateCommandLine(int argsAmount, char *userInputPointer[]);
void writeFormat(char currentLine[LINE_LENGTH]);

