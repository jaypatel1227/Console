#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// the temporary way to analyze the input and execute
void evaluate(string inp);


// checks if inp begins with match
bool begins_with(string inp, string match); 

// removes match from the front of inp
// doesn't check if inp begins with match (must check with begins_with)
string remove_match_front(string inp, string match);

// checks if inp ends with match
bool ends_with(string inp, string match);

// removes match from the end of inp
// doesn't check if inp ends with match (must check with ends_with)
string remove_match_end(string inp, string match);

int read_num(string inp);

string read_word(string inp);
