/*
 * hasUniqueChars.c
 * 
 * This program defines a function `hasUniqueChars` which determines if 
 * all characters in a given string are unique, ignoring spaces, and checks for
 * non-printing characters. The function uses bitwise operations on unsigned 
 * long integers to efficiently track occurrences of ASCII characters.
 * 
 * Author: Linh Dang
 */


#include <stdio.h>  // fprintf, printf
#include <stdlib.h> // exit() defined here
#include <string.h> // useful string operations
#include <ctype.h>  //useful character operations
#include <stdbool.h>  // to define a boolean type and true, false
                      // see https://en.wikibooks.org/wiki/C_Programming/stdbool.h

#include "binary_convert.h"


/*
 * This function is for debugging by printing out the value
 * of an input insigned long as a binary string.
 */
void seeBits(unsigned long value, char *debug_text) {
  
  // string to represent binary value of variable value
  char *bin_str;

  bin_str = ulong_to_bin_str(value);
  printf("%s%s\n", debug_text, bin_str);
  free(bin_str);
  
}


/*
 * Given an input string of chars, check for any non-printing
 * characters and print an error and exit if the string has any.
 */
void checkInvalid(char * inputStr) {
  char nextChar;
  int i;
  
  for(i = 0; i < strlen(inputStr); i++) {
    nextChar = inputStr[i];

    // if nextChar is invalid (31 or less or 127 as an ascii char code), then bail out
    if ((nextChar <= 31 ) || (nextChar == 127)) {
      fprintf(stderr, "invalid character in string\n");
      exit(EXIT_FAILURE);
    }
  }
}


/*
 * This function takes an input string and checks if all characters, except spaces,
 * are unique. It uses two unsigned long integers (`checkBitsA_z` and `checkBitsexcl_amp`)
 * as bit vectors to track the occurrence of ASCII characters. If any character repeats,
 * it returns false. If any non-printing characters are found, the program exits.
 *
 * Parameters:
 *   - inputStr: A pointer to the input string to be checked.
 *
 * Returns:
 *   - true if all characters in the string are unique, false if any duplicates are found.
 *
 * Errors:
 *   - Exits the program if non-printing ASCII characters (values ≤ 31 or 127) are found.
 */

bool hasUniqueChars(char * inputStr) {
  // bail out quickly if any invalid characters
  checkInvalid(inputStr);
  
  int i;   // loop counter
  
  // unsigned long can handle 64 different chars in a string
  // if a bit at a position is 1, then we have seen that character
  unsigned long checkBitsA_z = 0;   // for checking A through z and {|}~
  unsigned long checkBitsexcl_amp =0;  // for checking ! though @ 

  char nextChar;         // next character in string to check

  // -------------------------------------------------------------
  // This section contains code to display the initial values of checkBitsA_z
  // and checkBitsexcl_amp, for debugging purposes. 
  // It also illustrates how to use the seeBits function for debugging.
  // Printed values should initially be all zeros
  
  // char debug_str_A_z[128];
  // strcpy(debug_str_A_z, "checkBitsA_z before: \n");
  // seeBits(checkBitsA_z, debug_str_A_z);
  
  // char debug_str_excl_amp[128];
  // strcpy(debug_str_excl_amp, "checkBitsexcl_amp before: \n");
  // seeBits(checkBitsexcl_amp, debug_str_excl_amp);
  // -------------------------------------------------------------

  
  for(i = 0; i < strlen(inputStr); i++) {
    nextChar = inputStr[i];

    if (nextChar == ' ') {
      continue;
    }

        if (nextChar >= 65 && nextChar <= 126) {
            unsigned long mask = 1UL << (nextChar - 65);
            if (checkBitsA_z & mask) {
                return false; // Duplicate found
            }
            checkBitsA_z |= mask;
        }
        else if (nextChar >= 33 && nextChar <= 64) {
            unsigned long mask = 1UL << (nextChar - 33);
            if (checkBitsexcl_amp & mask) {
                return false; // Duplicate found
            }
            checkBitsexcl_amp |= mask;
        }
    }
    // -------------------------------------------------------------
    // Below this are examples of debugging print statements you could use
    // Move/use as makes sense for you!
    // Modify to work on checkBitsexcl_amp
    // printf("nextchar int value: %d\n", nextChar);
    // char char_str[2] = "\0";
    // char_str[0] = nextChar;
    // strcpy(debug_str_A_z, "nextchar: ");
    // strcat(debug_str_A_z, char_str);
    // strcat(debug_str_A_z,", checkBitsA_z: \n");
    // seeBits(checkBitsA_z, debug_str_A_z);
    // ------------------------------------------------------------- 

  // if through all the characters, then no duplicates found
  return true;
  
}
