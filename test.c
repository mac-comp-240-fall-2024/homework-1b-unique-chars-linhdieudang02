/*
 * Tests for the hasUniqueChars function.
 * This program runs several test cases using string inputs to verify 
 * if hasUniqueChars() works correctly. It uses assertions to validate
 * the function's return values.
 */

#include <stdio.h>    // printf
#include <stdbool.h>  // to define a boolean type and true, false
#include <string.h>   // strcpy  to copy a string
#include <assert.h>


// declaration of function from hasUniqueChars.c
bool hasUniqueChars(char * inputStr);


int main() {

  // ------------------------------------------------------------
  // Examples of declaring string constants
  /* Example 1 */
  char string1[] = "A string declared as an array.\n";

  /* Example 2 */
  char *string2 = "A string declared as a pointer.\n";

  /* Example 3 */
  char string3[128];   // can copy in up to 127 characters
                       // chose 128 because it is a multiple of 8 bytes
  strcpy(string3, "A string constant copied in.\n");

  // You can uncomment these to see how the strings were initialized above.
  // Then you can comment these out again once you see that the 
  // strings were created correctly
  // printf ("%s", string1);
  // printf ("%s", string2);
  // printf ("%s", string3);

  // -------------------------------------------------------------
  // Thorough and exhaustive tests of hasUniqueChars()  
  bool ok;    // holds the result of hasUniqueChars(); used in asserts
  
  // Test 1: a test case that should return false because characters are duplicated
  strcpy(string3, "This should fail (l and s and i and h)");
  ok = hasUniqueChars(string3);
  assert(!(ok));
  printf("Test passes\n");
  
  // Test 2: This should be true and not fail, but won't work until you
  // complete the hasUniqueChars() function
  strcpy(string3, "abcdefghij");
  ok = hasUniqueChars(string3);
  assert(ok);
  printf("Test passes\n");

  // Test 3: String with space character repeated, which is allowed.
  strcpy(string3, "a b c d e f g h i j");
  ok = hasUniqueChars(string3);
  assert(ok); 
  printf("Test passes\n");

  // Test 4: A string with mixed-case letters but unique.
  strcpy(string3, "AbCdEfGhIj");
  ok = hasUniqueChars(string3);
  assert(ok);
  printf("Test passes\n");

  // Test 5: String with a duplicate letter 'a'.
  strcpy(string3, "abcdefga");
  ok = hasUniqueChars(string3);
  assert(!ok);
  printf("Test passes\n");

  // Test 6: Empty string should be considered as all unique.
  strcpy(string3, "");
  ok = hasUniqueChars(string3);
  assert(ok);
  printf("Test passes\n");

  // NOTE: if you add a \n to any tests, this should cause the
  //       exit failure given. Keep this test last so you can check 
  //       that others pass or fail as you expect them to.
  strcpy(string3, "a b cc\n");
  ok = hasUniqueChars(string3);
  printf("Test passes\n");
  // other examples that should fail that you can place in strings
  // are \0 or \t or \r
  // See problem description for more details about escape sequences
  
  return 0;
}