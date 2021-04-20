/**
 * AUTHOR   : Gagan
 * DATE     : Nov 10 2019
 * DESC     : A header file, contains preprocessor directives, function prototypes, macros etc
 * See c_language_features.c for the corresponding compilation unit
*/

#ifndef C_LANGUAGE_FEATURES_H // check if this symbol has been defined before
#define C_LANGUAGE_FEATURES_H // if not, define it now

#define A_NEW_SYMBOL 1 // a symbolic constant

#define IS_DEFINED_NOW 1 // define another symbol using #define
                         // this  is checked in the related c file

#else
// do nothing
#endif

// TODO: understand the following in depth:
// is this a special directive?
// #include_next "c_language_features.h" // this is a way to include the file at the next path,
// include_next is useful for overriding some of the stuff before includng the original
// file