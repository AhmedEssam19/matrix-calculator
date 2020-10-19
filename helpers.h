#pragma once

#include <string>
#include "Complex.h"
#include <vector>

// split string on a specific character to a vector of strings 
vector<string>* split(string txt, char split_char);

// Eliminate spaces in the begining and at the end of string
string strip(string txt);

void print_vector(vector<vector<Complex>*>* matrix);
