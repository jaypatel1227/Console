#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <stdlib.h>

using namespace std;

// USAGE: echo $message$
// implements the good ol' echo command
void echo(string inp);

// USAGE: list_nums $low$ $high$
// lists numbers from low to high (inclusive)
void list_nums(string inp);

// USAGE: cat $filename$ $filename$ ...
// prints the contents of all of the inputed files
void cat(string inp);

// USAGE: touch $filename$
// makes a file if it doesn't exist else interacts with it (without doing anything)
void touch(string inp);

// USAGE: head $filename$
// prints the first 10 lines of the file
void head(string inp);

// USAGE: tail $filename$
// prints the last 10 lines of the file
void tail(string inp);

// USAGE: clear
// clears the screen 
void clear();
