/*
    AUTHOR: Gagan
    Description: This is a test pad for testing various c features. It will contain some experimental code,
    so run this at your own risk. This may crash!!
*/

#include <stdio.h>

inline int g_add(int a, int b);             // function prototype
void print_char_in_binary(unsigned char c); // print binary representation of char
void print_int_in_binary(unsigned int c);   // print binary representation of int
// print in binary form, using custom print function
void print_binary(unsigned char c, void (*printer)(unsigned char c2));

int main(int argc, char const *argv[]) // char const *argv makes the values constant
{

  int answer = g_add(4, 2);
  printf("answer is %d\n", answer);
  // print_char_in_binary(answer);

  printf("\nBinary numbers\n");
  for (size_t i = 0; i < 16; i++)
  {
    // print_int_in_binary(i);
    // print_char_in_binary(i);
    print_binary(i, print_char_in_binary);
  }

  unsigned char initial = 0b11111110;  // 11111111 is 255, 11111110 is 254,
                                       // 0b prefix specifies binary numbers
  unsigned char complement = ~initial; // flip all bits, 11111110 becomes 00000001
  printf("~%d is %d\n", initial, complement);

  print_char_in_binary(initial);
  print_char_in_binary(complement);
  print_char_in_binary(255);

  printf("Using custom functions\n");
  print_binary(initial, print_char_in_binary);    // use a custom function to print char
  print_binary(complement, print_char_in_binary); // use a custom function to print char
  printf("\n");
  // printf("\n\n");
  return 0;
}

// add 2 numbers
int g_add(int a, int b) // function definition
{
  return a + b;
}

// prints bits of char
void print_char_in_binary(unsigned char c)
{
  unsigned char mask = 0b10000000;
  for (size_t i = 0; i < sizeof(char) * 8; i++)
  {
    printf("%c", c & (mask >> i) ? '1' : '0');
  }
  printf("\n");
}

// prints bits of char
void print_int_in_binary(unsigned int c)
{
  unsigned int mask = 1 << (sizeof(int) * 8 - 1);
  for (size_t i = 0; i < sizeof(int) * 8; i++)
  {
    printf("%c", c & (mask >> i) ? '1' : '0');
  }
  printf("\n");
}

void print_binary(unsigned char c, void (*printer)(unsigned char c2))
{
  if ((*printer))
  {
    (*printer)(c);
  }
  else
  {
    printf("function printer is not provided.\n");
  }
}
