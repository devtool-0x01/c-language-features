/**
 * AUTHOR: Gagan Singh
 * DESC: a program to try C syntax and features/controls available in the language,
 *         see c_language_features.h for preprocessor stuff
 * NOTE: CAUTION
 *  this program compiles and will probably run as well, HOWEVER, run it at your own risk, 
 *  may result in program or system crash!!
 *  I have crashed a couple of computers in the past using c and sockets stuff :D
*/

// #include directive includes another file, <- a single line comment begins with //
// #include is like import in python/js/ts, using in c#, include in php, @import in css/scss etc
#include <stdio.h>               // include standard library header for io.
#include <stdbool.h>             // include standard library header for bool datatype.
#include "c_language_features.h" // use "" for including files local to project,
                                 // use <> for including standard headers

// preprocessor directives
#define A_DEFINED_CONSTANT 0 // a symbolic constant, this is better than using magic numbers in code

// following has been moved to a header file
// #define IS_DEFINED_NOW 0    // define another symbol using #def
#if defined(IS_DEFINED_NOW) // check if IS_DEFINED_NOW is defined?
#undef IS_DEFINED_NOW       // undefine previously defined symbol using #undef ?!?!
#endif                      // IS_DEFINED_NOW

#ifdef IS_DEFINED_NOW // alternate version of #if defined(SYMBOL)
#undef IS_DEFINED_NOW
#endif

#define MIN(x, y) (((x) < (y)) ? (x) : (y)) // a macro, like a little inline function

// global variables
int global_variable = 0;                 // a global variable, external linkage maybe?
static int internal_global_variable = 0; // a global variable but static, with internal linkage
extern int an_external_varable;          // an externally defined variable, global scope

// function prototypes, but no definitions or function body
void func_without_args();      // a function without any arguments
void func_without_args2(void); // another way to say function takes no arguments
//void func_with_one_arg(int arg);              // a function with 1 argument, pass by value
//void func_with_const_arg(const int arg);      // a function with 1 argument, arg is constant in function
//void func_with_more_arg(int arg1, int arg2);  // a function with more than 1 argument
void func_with_pointer_arg(int *arg); // a function with a pointer argument, pass by reference/address
//void func_with_multiple_args(char *fmt, ...); // a function with many arguments, e.g. c printf, c# params

// TODO: add function pointer syntax, i.e. the weird int (*fp)(int, int) stuff :D <- DONE
int new_min(int l, int r, int (*comp)(int a, int b)); // a function pointer declaration

// a function with declaration and body definition
// returns smaller of the 2 values
int min(int a, int b)     // this is pass by value
{                         // same a above macro MIN, but in a function, this is much better :)
    return a < b ? a : b; // ?: is like if else, but compact and always returns 1 value,
                          // this means, is a less than b?, return a, else return b
}
// inlined, returns biggest of 2 values. must be static?!?!
inline static int max(int a, int b)
{
    // an inlined function, but compiler decides when/whether to inline
    // inline function didn't compile without static keyword for this file
    return a > b ? a : b; // return statement returns a value back to calling function
}

struct my_struct // a structure definition with 2 members
{
    int a;         // a member variable
    int b;         // another member variable
} initialVariable; // create a variable along with structure definition

typedef struct my_struct mytype; // create an alias for a type with typedef,
                                 // alias comes after existing type

union c_union // a union structure declaration
{
    char c;  // a character datatype member
    short s; // a short datatype member
    int i;   // an int member
    long l;  // a long type member, all members will be stored in the same space as biggest type,
             // this will have the storage size of type long, as it is the biggest datatype here
};

// bitfelds, for packing values together in one datatype
struct c_bit_fields
{
    unsigned int flag1 : 1;     // one bit flag for flag1
    unsigned int flag2 : 1;     // one bit for flag2
    unsigned int hex_color : 6; // six bits for hex_color flag, this will not save a hex color value though
};

// an enumeration, or enum for short, fixed value constants
enum DaysOfWeek
{
    Monday = 0, // this week starts from Monday!
    Tuesday,    // implicitly this will have value 1 + previous
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday,
    UnknownDay = 7,      // explicitly specify another value
    WhatDayDidYouSay = 7 // same as UnknownDay, two enum members can have same value
};

// main function, execution of program mostly starts here,
// 'mostly' because there are clever ways to run code before main, although not sure if possible in C
int main(int argc, char const *argv[])
{
    /*  
        a multiline comment, same as the one at the beginning of the file :)
    */

    // argv[0][0] = "";   // cannot change/modify part of argument value,
    // argv[0] = "Huh?!"; // but can change/update entire argument to a new one?!

    // inbuilt types
    char character = 'a';               // a char datatype variable
    short short_variable = 0;           // short datatype variable
    int int_variable = 0;               // int datatype variable
    long long_variable = 0L;            // long datatype variable, suffixed with L or l, use L
    long long long_long_variable = 0LL; // long long datatype variable, suffixed with LL

    float float_variable = 0.0f;            // float datatype variable, suffixed with f
    double double_variable = 0.0;           // double datatype variable
    long double long_double_variable = 0.0; // long double datatype variable

    bool a_bool_variable = false;   // a bool datatype variable
    _Bool a__Bool_variable = false; // another bool datatype variable

    // custom types, types here means a custom container, C does not have types per say
    mytype mytype_variable;              // a typedef'd datatype variable
    struct my_struct my_struct_variable; // a structure variable variable

    mytype *mytype_pointer = &my_struct_variable; // a pointer to a struct variable
    my_struct_variable.a = 0;                     // assign 0 to structure member, using a struct variable
    mytype_pointer->b = 0;                        // assign 0 to structure member, using a struct pointer

    union c_union cunion; // a union variable
    cunion.c = 'a';       // set char value to charater a
    cunion.i = 4;         // at this point, int value is 4 and char value is also 4

    struct c_bit_fields c_bitfields_variable; // a bitfield structure variable
    c_bitfields_variable.flag1 = 1;           // set flag1 value = 1, could represent that a flag is set
    c_bitfields_variable.flag1 = 0;           // set flag1 value to 0, could represent flag is unset

    //enum DayOfWeek day_of_week_variable = Sunday; // enum variable not allowed?!?!
    int day_of_week_variable = Sunday; // enum value in use
    day_of_week_variable = Friday;     // update to another value from enum

    // modifiers and qualifiers
    signed int signed_variable = -1;                 // a variable with negative values, variables are signed by default?!
    unsigned int unsigned_variable = 1U;             // an unsigned variable, with only positive values
    const unsigned int const_unsigned_variable = 1U; // a constant unsigned variable, cannot update value
    // const_unsigned_variable = 2; // this is invalid, cannot change a constant variable val

    int a_normal_variable; // a variable declaration/definition, with automatic storage
    a_normal_variable = 0; // assignment, assign 0 to variable

    extern int an_extern;                 // an externally defined variable, cannot initilize here
    const int a_constant = 0;             // defines a constant value with const
    volatile int a_volatile = 0;          // defines a value that can change by external update, thread etc
    register int a_register_variable = 0; // defines a variable to be stored in register instead of ram
    // auto int an_automatic_variable = 0;   // defines a variable with automatic storage, default for c
    static int a_static_variable = 0; // defines a variable with static local storage

    // other variable declaration syntax
    int another_variable, and_another_variable;  // defining/declaring multiple variables
    another_variable = and_another_variable = 0; // assign 0 to both variables

    // bool type, not available in older compilers/standards, may be only available in c11/c99?!
    bool are_vars_equal = false, are_vars_not_equal = false;    // define and initialize multiple variables
    are_vars_equal = another_variable == a_normal_variable;     // use == to checking equality
    are_vars_not_equal = another_variable != a_normal_variable; // use != to check inequality

    // _Bool is the new actual type in the background for bool
    _Bool temp = false;                           // temp variable for temp values, all results below are bools
    temp = another_variable > a_normal_variable;  // > to check 1 value is greater than other
    temp = another_variable < a_normal_variable;  // < to check 1 value is less than other, reassign to temp
    temp = another_variable >= a_normal_variable; // > to check 1 value is greater than or equal to other
    temp = another_variable <= a_normal_variable; // > to check 1 value is less than or equal to other

    // conditional branching statements/controls
    if (temp) // check if temp is true, or truthy. 0, false, '', NULL are falsy, other values are true
    {
        /* code */ // run this code if condition in if (temp) above is true
    }
    else if (1 == 1) // check for another condition if previous if condition is false
    {
        /* else if code */ // run this block if else if (test) is true
    }
    else // if none of above if(tests) are true, go here
    {
        /* else code */ // run this code block as default, else{} and else if(test){} blocks are optional
    }

    // ternary operator ?:
    char ternary_c = 1 > 2 ? 2 : 1; // ?: checks condition, if true, return ? value, else return : value

    switch (a_normal_variable) // a switch testing structure/control for multiple specific values
    {
    case 1:        // case value must be a constant
        /* code */ // run this block is a_normal_variable is 1
        break;     // break out of this case and the switch statement
    case 2:        // can have multiple case statements
        /* code for case 2 */
        break;
    case 3: // will run for value of 3 and
    case 4: // will also run for value of 4, combined cases
        // code will run if switched on value is 3 or 4
        break; // break is necessary for stopping cases falling through to next case
    default:   // default case, is optional
        // default code to run if none of the cases match
        break;
    }

    // loops
    int i = 0; // a common counter variable i, used to control loop conditions
    // while loop
    while (i < 10) // loop while i is less than 10, condition checked at the top/first
    {
        printf("%d ", i); // print value if i for each iteration
        i += 1;           // increment i by 1, without a changing condition, the loop will run forever
    }
    printf("\n"); // print an empty line

    // for loop
    for (int i = 0; i < 10; i++) // a for loop, contains (initialization; condition; increment)
    {
        printf("%d ", i); // print i, i is local to for loop in this case and overrides the i above
    }
    printf("\n"); // print an empty line

    i = 0; // reset i for do while loop
           // do while loop
    do     // run at least once
    {
        printf("%d ", i); // print i, will be 0 on first run
        i += 1;           // increment i by 1, so test condition changes, othewise we go in an infinite loop
    } while (i < 10);     // check condition at the bottom/last
    printf("\n\n");       // print 2 empty lines for spacing

    i = 0; // reset i to 0 for next break and continue example

    // while loop for break and continue
    while (true) // infinite loop
    {
        if (i == 2) // check is value of i is equal to 2, == checks for equality, single = is assignment
        {
            continue; // if i is 2, skip rest of the block and go to next iteration, back to while(true)
        }
        if (i == 4) // check if i is 4
        {
            break; // if i is 4, break out of the loop completely, this will stop the loop completely
        }

        printf("%d ", i); // print i, this is like the else block if above conditions are false
    }
    printf("\n\n"); // empty lines for spacing

    // goto example
    i = 0;         // reset i
    while (i < 10) // set condition for loop
    {
    increment_i:        // defines a label to jump to
        i++;            // increment i
    test_i_for_value_4: // another label to jump to if needed
        if (i == 4)     // check if i is 4
        {
            goto increment_i; // if i is 4, jump to increment label,
                              // this will increment i and skip printing 4
        }
    print:                 // another label
        printf("%d\n", i); // print i, NOTE: since we do increment above, i will go upto 10, not 9
    }

    // arrays
    int def_array[5];                   // define an array of 5 ints, total elements = 5, last index = 4
    int def_array_initialized[5] = {0}; // define and initialze array of 5 ints, total elements = 5, last index = 4
    def_array[0] = 1;                   // access first element and assign value 1, first element is index 0
    def_array[4] = 1;                   // access last element and assign 1, last index is size - 1

    // pointers
    int *pointer_to_int;                       // a pointer variable, declared with: datatype *variable_name
    pointer_to_int = &another_variable;        // assign address of another variable using &variable_name
    int deref_pointer_value = *pointer_to_int; // dereference a pointer to get value back

    pointer_to_int = def_array; // point to first element of array, 1st item but index 0
    pointer_to_int += 1;        // point to next item in array, 2nd item in this case, but index 1

    int **pointer_to_pointer;             // a double pointer, or a pointer to a pointer to int
    pointer_to_pointer = &pointer_to_int; // assign address of another pointer

    // sizeof operator
    size_t size_of_bool = sizeof(bool);                   // get size of bool type
    size_t size_of_char = sizeof(char);                   // get size of char type
    size_t size_of_short = sizeof(short int);             // get size of short type, short int == short
    size_t size_of_int = sizeof(int);                     // get size of int
    size_t size_of_long_int = sizeof(long int);           // get size of long int, long int == long
    size_t size_of_long_long_int = sizeof(long long int); // get size of long long int
    size_t size_of_float = sizeof(float);                 // get size of float
    size_t size_of_double = sizeof(double);               // get size of double
    size_t size_of_long_double = sizeof(long double);     // get size of long long double

    size_t size_of_mystruct = sizeof(struct my_struct);      // get size of my_struct structure
    size_t size_of_mytype = sizeof(mytype);                  // get size of my_struct, using typdef'd type
    size_t size_of_cunion = sizeof(union c_union);           // get size of union, is the size of biggest member
    size_t size_of_cbitfields = sizeof(struct c_bit_fields); // get size of bitfields, is the size of int
    size_t size_of_enums = sizeof(enum DaysOfWeek);          // get size of enum, is the size of int

    size_t size_of_variable = sizeof(another_variable);             // get size of variable
    size_t size_of_array = sizeof(def_array);                       // get size of array
    size_t size_of_pointer = sizeof(pointer_to_int);                // get size of a pointer
    size_t size_of_pointer_to_pointer = sizeof(pointer_to_pointer); // get size of a pointer to pointer

    // Macros and functions calls
    int using_defined_value;
    using_defined_value = A_DEFINED_CONSTANT; // using a defined constant
    int min_val_with_macro = MIN(2, 3);       // a macro usage
    int min_val = min(2, 3);                  // a function call with arguments/parameters
    int max_val = max(4, 6);                  // another function call
    func_with_pointer_arg(&min_val);          // a function call that accepts pointer as argument
    func_without_args();                      // a function call without arguments
    func_without_args2();                     // another call without arguments,
                                              // this function explicitly says no args in declaration

    // printing with printf function
    printf("hello world\n"); // a function call, print just a string literal

    printf("min_val = %d, max_val = %d\n", min_val, max_val);   // printf is like Console.Writeline
    printf("min_val = %3d, max_val = %3d\n", min_val, max_val); // print both ints 3 digits wide

    printf("char is %c\n", 'a');               // chars are printed with %c
    printf("int is %d\n", 1);                  // ints are printed with %d
    printf("float is %2.2f\n", 1.0f);          // floats are printed with %f, .2 sets 2 decimals
    printf("double is %lf\n", 1.0);            // doubles are printed with %lf
    printf("pointer is %p\n", pointer_to_int); // pointers are printed with %p

    // asm("nop"); // asm allows adding assembly code in c

    // operators
    int a = 1, b;                        // just 2 temp variables for use in operators examples
    a = 1, b = 1;                        // = operator for assignment, use comma , operator for multiple
    int addition = a + b;                // + operator for addition
    int subtraction = a - b;             // - operator for subtraction
    int multiplication = a * b;          // * operator for multiplication
    int division = a / b;                // / operator for division, a single forward slash
    int modulus = a % b;                 // % operator for modulus, or getting the remainder after division
    int or = a | b;                      // | operator for OR-ing bits, 0101 | 0011 becomes 0111
    int and = a & b;                     // & operator for AND-ing bits, 1011 & 1001 becomes 1001
    int xor = a ^ b;                     // - operator for XOR-ing bits, 1011 ^ 0010 becomes 1001
    int left_shift = a << 1;             // << operator for shifting bits left, 0010 becomes 0100
    int right_shift = a >> 1;            // >> operator for shifting bits right, 0100 becomes 0010
    int complement = ~0;                 // ~ operator for flipping bits, 0100 becomes 1011
    unsigned int u_complement = ~0U;     // ~ operator for flipping bits, 0100 becomes 1011
    bool not_a = !true;                  // ! operator for Not a, !true becomes false and !false becomes true
    bool a_equals_b = a == b;            // == operator for equality test
    bool a_not_equals_b = a != b;        // != operator for checking if values are not equal
    bool a_greater_than_b = a > b;       // > operator for checking if left value is greater than right
    bool a_less_than_b = a < b;          // < operator for checking left value if less than b
    bool a_greater_or_equals_b = a >= b; // >= operator for checking if left value is greater than or equal to right value
    bool a_less_or_equals_b = a <= b;    // <= operator for checking if left value is less than or equal to right value

    a++; // add 1 to a, incement value after using value of a, postfix form
    ++a; // add 1 to a, increment value before using value of a, prefix form
    a--; // subtract 1 from a, uses value first, then subtracts 1
    --a; // subtract 1 from a, subtracts 1, then uses value

    a = a + 1; // take value of a and add 1, and save it back in a
    a += 1;    // same as a = a + 1; this form also applies to other operators

    a = a - 1; // take value of a, minus 1, and save back in a
    a -= 1;    // same as a = a -1; this form also applies to other operators

    // casts
    double double_value = 200.0;                      // create a wider datatype value
    short short_value = 20;                           // create a smaller datatype value
    int implicitly_converted_int = short_value;       // assign to a wider type, automatically converted
    int explicitly_converted_int = (int)double_value; // explicitly converted using cast, will lose information

    // some pointer and const tricky syntax madness :)
    const int *const_int_pointer; // a pointer to a const value, the pointer can change but value cannot
    const_int_pointer = &a;       // assign address of a using addressof (&) operator
    //*const_int_pointer = 2; // invalid, pointer to a constant value cannot change value
    const_int_pointer = &b; // valid, pointer can point to another variable

    int *const int_const_pointer = &a; // a constant pointer variable, value pointed can change
    //int_const_pointer = &b; // invalid, cannot change pointed to value
    *int_const_pointer = 1; // valid, can change value pointed to, not the pointer itself

    // this is like a reference to an object, like the 'this' pointer that always points to an object
    const int *const const_int_const_pointer = &a; // const value, const pointer, cannot change either
    // const_int_const_pointer = &b; // invalid, cannot change constant pointer
    // *const_int_const_pointer = 1; // invalid, cannot change pointed to value

    // const int const is invalid syntax! Even in c11
    // const int const *const_int_const_pointer2 = &b; // position of * matters, this is invalid syntax
    // const_int_const_pointer2 = &a;                  // valid, pointer is not const
    // *const_int_const_pointer2 = 2; // not valid, value is const

    // return 0 to OS from main, 0 signals a successful run of program
    return 0;
}

// define functions previously prototyped
void func_with_pointer_arg(int *pointer)
{
    printf("%p = %d\n", pointer, *pointer); // print address and value (dereference pointer with *pointer)
}

void func_without_args()
{
    printf("a function without arguments, func()\n");
}

void func_without_args2(void)
{
    printf("another function without arguments, func(void)\n");
}

// return min of 2 numbers, using a custom testing function
int new_min(int l, int r, int (*comp)(int a, int b))
{
    if ((*comp))
    {
        return (*comp)(l, r);
    }
    else
    {
        return min(l, r);
    }
}
