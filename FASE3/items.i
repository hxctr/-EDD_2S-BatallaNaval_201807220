%module items

%{
#include "items.h"
%}

%include "std_string.i"
%include "std_vector.i"

using namespace std;
%template(IntVector) vector<int>;
%template(StringVector) vector<string>;

%include items.h