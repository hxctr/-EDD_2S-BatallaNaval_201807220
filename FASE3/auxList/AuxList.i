%module AuxList

%{
#include "AuxList.h"
%}

%include "std_string.i"
%include "std_vector.i"

using namespace std;
%template(StringVector) vector<string>;

%include AuxList.h